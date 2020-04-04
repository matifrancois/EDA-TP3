#ifndef FOOD_H_
#define FOOD_H_

/**********************************
INCLUDE
**********************************/
#include "prototype.h"


/**********************************
CLASS
**********************************/
class Food
{
public:
	Food();
	Food(double posx, double posy);
	~Food();

	/*Getters*/
	double getFoodPosX(void);
	double getFoodPosY(void);

	/*Setters*/
	void setFoodPosX(double a);
	void setFoodPosY(double b);

private:
	double foodx;
	double foody;
	double foodRadius;
};



#endif // !FOOD_H_
