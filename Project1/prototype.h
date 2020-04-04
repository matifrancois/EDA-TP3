#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

/**********************************
DEFINE
**********************************/
#define FOODRADIUS 1
#define BABYRADIUS 1
#define GROWNRADIUS 2
#define GOODOLDRADIUS 3
#define TAMANIO_PANTALLA_X_ENTRADA 400
#define TAMANIO_PANTALLA_Y_ENTRADA 800
#define TAMANIO_PANTALLA_X 1200
#define TAMANIO_PANTALLA_Y 800
#define MAX_FOOD 1000
#define FOOD_COUNT_INICIAL 5
#define PROBABILIDAD_MUERTE_BABY 0.1f
#define PROBABILIDAD_MUERTE_GROWN 0.2f
#define PROBABILIDAD_MUERTE_OLD 0.3f
#define PORCENTAJE_INICIAL_VEL 50.0f
#define SMELLRADIUS_INICIAL 5.0f
#define DIR_INICIAL 0.0f




/**********************************
INCLUDE
**********************************/
#include<iostream>
#include <ctime>
#include <cstdlib>
#include <stdint.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>


/**********************************
FUNCTIONS
**********************************/
double getDistance(double x1, double x2, double y1, double y2); //obtiene la distancia entre dos puntos
int randBetween(int a, int b); //regresa un número aleatorio entre a y b
double normalRand(void); //regresa un número aleatorio entre cero y uno
void setSeed(void);



#endif // !PROTOTYPE_H_
