#include "prototype.h"






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

int randBetween(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

double normalRand(void)
{
	return rand() / (double)RAND_MAX;
}

void setSeed(void)
{
	srand((unsigned int)time(NULL));
}
