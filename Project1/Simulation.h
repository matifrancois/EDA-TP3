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

/**********************************
CLASS
**********************************/

class Simulation
{
public:
	Simulation();
	Simulation(double maxX_, double maxY_, int blobNum_, int foodNum_, double maxSpeed_, double alphaSpeed_,
	double smellRadius_, double randomJiggleLimit_, double babyDeathProb_, double grownDeathProb_, double goodDeathProb_, int mode_);
	~Simulation();

	/*Inicializar blobs y food*/
	bool generateFood(int foodNum);	//genera la comida en posiciones aleatorias. Devuelve uno si se pudo asignar la memoria dinámica.
	bool generateBlobs(int blobNum);	//genera los babyBlobs en posiciones aleatorias.

	/*Revisar nacimientos y muertes*/
	void blobDeath(void);
	void blobBirth(void);	//crea nuevos blobs.
	void clearBlob(int i);	//elimina a un blob del arreglo de blobs y luego ajusta el arreglo acorde a la eliminación, de forma que blobNum siempre apunte al primer lugar libre para crear un blob.
	void blobMerge(void);	//revisa si hay blobs que se deban mezclar.
	void blobDivide(void);	//crea al nuevo blob por división y elimina al padre


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