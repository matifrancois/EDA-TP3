#pragma once
#include "Blob.h"

/**********************************
DEFINE
**********************************/
#define GROWNMAXFOOD 4
#define GROWNRADIUS 1

/**********************************
CLASS
**********************************/
class GrownBlob :
	public Blob
{
public:
	GrownBlob();
	GrownBlob(double maxX, double maxY, double maxSpeed_, double alphaSpeed_, double radius_, double deathProb_);
	GrownBlob(Blob *blobCopy);
	~GrownBlob();
};

