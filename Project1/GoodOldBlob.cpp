#include "GoodOldBlob.h"



GoodOldBlob::GoodOldBlob()
{
}

GoodOldBlob::GoodOldBlob(double maxX, double maxY, double maxSpeed_, double alphaSpeed_, double radius_, double deathProb_) :

	Blob(maxX, maxY, maxSpeed_, alphaSpeed_, radius_, deathProb_)
{
	maxFood = GOODOLDMAXFOOD;
	colissionRadius = GOODOLDRADIUS;
	group = GOODOLDGROUP;
}


GoodOldBlob::~GoodOldBlob()
{
}
