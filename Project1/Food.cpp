#include "Food.h"



Food::Food()
{
	foodx = 0.0;
	foody = 0.0;
	foodRadius = FOODRADIUS;
}


Food::~Food()
{
}

Food::Food(double posx, double posy)
{
	foodx = posx;
	foody = posy;
	foodRadius = FOODRADIUS;
}


/*Getters*/
double Food::getFoodPosX(void)
{
	return foodx;
}

double Food::getFoodPosY(void)
{
	return foody;
}

/*Setters*/
void Food::setFoodPosX(double a)
{
	foodx = a;
}

void Food::setFoodPosY(double b)
{
	foody = b;
}

