#pragma once
#include "Blob.h"

/**********************************
DEFINE
**********************************/
#define BABYMAXFOOD 5
#define BABYRADIUS 20

/**********************************
CLASS
**********************************/
class BabyBlob :
	public Blob
{
public:
	BabyBlob();
	BabyBlob(double maxX, double maxY, double maxSpeed_, double alphaSpeed_, double radius_, double deathProb_);
	BabyBlob(Blob *copyBlob);
	~BabyBlob();
};

