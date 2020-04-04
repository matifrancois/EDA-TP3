#include "Food.h"



Food::Food()
{
}


Food::~Food()
{
}

Food::Food(double posx, double posy)
{
	foodx = posx;
	foody = posy;
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

