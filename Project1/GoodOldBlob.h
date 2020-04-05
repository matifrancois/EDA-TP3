#pragma once
#include "Blob.h"

/**********************************
DEFINE
**********************************/
#define GOODOLDMAXFOOD 3
#define GOODOLDRADIUS 3

/**********************************
CLASS
**********************************/
class GoodOldBlob :
	public Blob
{
public:
	GoodOldBlob();
	GoodOldBlob(double maxX, double maxY, double maxSpeed_, double alphaSpeed_, double radius_, double deathProb_);
	GoodOldBlob(Blob *copyBlob);
	~GoodOldBlob();
};

