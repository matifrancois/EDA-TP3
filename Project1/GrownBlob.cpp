#include "GrownBlob.h"



GrownBlob::GrownBlob()
{
}

GrownBlob::GrownBlob(double maxX, double maxY, double maxSpeed_, double alphaSpeed_, double radius_, double deathProb_):
	
	Blob(maxX, maxY, maxSpeed_, alphaSpeed_, radius_, deathProb_)
{
	maxFood = GROWNMAXFOOD;
	colissionRadius = GROWNRADIUS;
	group = GROWNGROUP;
}

GrownBlob::GrownBlob(Blob * blobCopy)
{
}


GrownBlob::~GrownBlob()
{
}
