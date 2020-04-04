#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

/**********************************
DEFINE
**********************************/
#define FOODRADIUS 1
#define BABYRADIUS 1
#define GROWNRADIUS 2
#define GOODOLDRADIUS 3


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
