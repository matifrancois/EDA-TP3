#include "Simulation.h"


Simulation::Simulation()
{
}


Simulation::~Simulation()
{
}

bool Blob::check_for_food(Blob *blobPtr, Food * foodPtr)
{
	if (getDistance(blobPtr->getX(), foodPtr->getFoodPosX(), blobPtr->getY(), foodPtr->getFoodPosY()) <= blobPtr->radius)
	{
		return true;
	}
	else return false;
}