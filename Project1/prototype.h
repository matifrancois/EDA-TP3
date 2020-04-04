#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

/**********************************
DEFINE
**********************************/



/**********************************
INCLUDE
**********************************/
#include<iostream>
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
double getDistance(double x1, double x2, double y1, double y2)
{
	double distance;
	double dis2 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	distance = sqrt(dis2);
	return distance;
}








#endif // !PROTOTYPE_H_
