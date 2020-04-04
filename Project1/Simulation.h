#ifndef SIM_H_
#define SIM_H_



/**********************************
INCLUDE
**********************************/
#include "prototype.h"
#include "Food.h"
#include "Blob.h"


/**********************************
CLASS
**********************************/


class Simulation
{
public:
	Simulation();
	~Simulation();
};


bool check_for_food(Blob *blobPtr, Food *foodPtr);


#endif // !SIM_H_