#include "Simulation.h"


Simulation::Simulation()
{
}


Simulation::~Simulation()
{
}

bool check_for_food(Blob *blobPtr, Food * foodPtr)
{
	if (getDistance(blobPtr->getX(), foodPtr->getFoodPosX(), blobPtr->getY(), foodPtr->getFoodPosY()) <= blobPtr->getRadius())
	{
		return true;
	}
	else return false;
}