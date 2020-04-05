#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

/**********************************
DEFINE
**********************************/
#define MAXDISTANCE 2000
#define PI 3.14159265359

typedef unsigned int uint;

using namespace std;

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
#include <vector>
#include <new>
#include <fstream>


/**********************************
FUNCTIONS
**********************************/
double getDistance(double x1, double x2, double y1, double y2); //obtiene la distancia entre dos puntos
int randBetween(int a, int b); //regresa un número aleatorio entre a y b
double normalRand(void); //regresa un número aleatorio entre cero y uno
double randBetweenReal(double a, double b);  //regresa un double entre dos valores especificados
double randomDir(void);
void setSeed(void);



#endif // !PROTOTYPE_H_
