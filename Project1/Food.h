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
	double getFoodPosX(void);
	double getFoodPosY(void);
	void setFoodPosX(double a);
	void setFoodPosY(double b);
	~Food();

private:
	double foodx;
	double foody;
};



#endif // !FOOD_H_
