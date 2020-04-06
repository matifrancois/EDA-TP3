#ifndef SIM_H_
#define SIM_H_

/**********************************
INCLUDE
**********************************/
#include "Blob.h"
#include "BabyBlob.h"
#include "GrownBlob.h"
#include "GoodOldBlob.h"

/**********************************
DEFINE
**********************************/
#define MAXBLOBS 1000
#define MAXFOOD 1000

#define default_maxX 1000.0
#define default_maxY 500.0
#define default_blobNum 1
#define default_maxSpeed 0.0
#define default_alphaSpeed 0.0
#define defaultMode 1
#define default_foodNum 0
#define default_smellRadius 0.0
#define defaultMode 1
#define defaultFPS 11.0
#define default_deathProb 0.0
#define default_randomJiggleLimit 0
#define default_deathProb 0.0

/**********************************
CLASS
**********************************/

class Simulation
{
public:
	Simulation();

	Simulation(double maxX_=default_maxX, double maxY_=default_maxY, int blobNum_=default_blobNum, int foodNum_=default_foodNum, 
		double maxSpeed_=default_maxSpeed, double alphaSpeed_=default_alphaSpeed, double smellRadius_=default_smellRadius, 
		double randomJiggleLimit_=default_randomJiggleLimit, double babyDeathProb_=default_deathProb,  double grownDeathProb_=default_deathProb,
		double goodDeathProb_=default_deathProb, int mode_=defaultMode); //Constructor de simulación inicial.
	
	~Simulation();

	/*Inicializar blobs y food*/
	bool generateFood(int newFood);	//agrega la comida indicada por newFood al arreglo de comidas.
	bool generateBlobs(int blobNum);	//genera los babyBlobs iniciales en posiciones aleatorias.

	
	/*Completar y recuperar datos*/
	void firstData(void);
	void getData(void);
										
										
	/*Revisar nacimientos y muertes*/
	void blobDeath(void);	//Elimina a los blobs por probabilidad de muerte.
	void blobBirth(void);	//crea nuevos blobs.
	void clearBlob(int i);	//elimina a un blob del arreglo de blobs y luego ajusta el arreglo acorde a la eliminación, de forma que blobNum siempre apunte al primer lugar libre para crear un blob.
	void blobMerge(void);	//revisa si hay blobs que se deban mezclar.
	void blobDivide(void);	//crea al nuevo blob por división y elimina al padre


	/*Elimina comida*/
	void delFood(int total);

	/*Inicia un ciclo de juego*/
	void gameLoop(void);


	Blob *blobPtr[MAXBLOBS];	//contiene los punteros a los distintos blobs en el tablero.
	Food *foodPtr[MAXFOOD];		//contiene los punteros a las distintas comidas en el juego.
	int blobNum;
	int foodNum;
	int mode;
	int tick;
	double babyDeathProb;
	double grownDeathProb;
	double goodDeathProb;
	double maxX;
	double maxY;
	double maxSpeed;
	double alphaSpeed;
	double randomJiggleLimit;
	double smellRadius;

};



#endif // !SIM_H_