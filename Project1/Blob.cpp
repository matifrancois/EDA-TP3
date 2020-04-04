#include "Blob.h"

/*Constructors*/
Blob::Blob()
{
	x = 0.0;
	y = 0.0;
	newx = 0.0;
	newy = 0.0;
	dir = 0.0;
	newdir = 0.0;
	radius = 0.0;
	speed = 0.0;
	foodEaten = 0;
	group = 0;
}

Blob::
Blob(double posx, double posy, double direction, double sp, double rad)
{
	x = posx;
	y = posy;
	dir = direction;
	radius = rad;
	speed = sp;
	newx = 0.0;
	newy = 0.0;
	newdir = 0.0;
	foodEaten = 0;
	group = 0;
	colissionRadius = 0.0;
}

/*Destructors*/
Blob::~Blob()
{
}

/*Getters*/
double Blob::getX(void)
{
	return x;
}

double Blob::getY(void)
{
	return y;
}

double Blob::getNewx(void)
{
	return newx;
}

double Blob::getNewy(void)
{
	return newy;
}

double Blob::getSpeed(void)
{
	return speed;
}

double Blob::getDir(void)
{
	return dir;
}

double Blob::getNewdir()
{
	return newdir;
}


/*Setters*/

void Blob::setX(double a)
{
	x = a;
}

void Blob::setY(double b)
{
	y = b;
}

void Blob::setSpeed(double v)
{
	speed = v;
}

void Blob::setDir(double k)
{
	dir = k;
}



/*Funciones*/
void Blob::newPositions(double maxX, double maxY)
{
	double nx = x + speed*cos(newdir);
	double ny = y + speed*sin(newdir);
	if (nx >= maxX) 
	{
		nx -= maxX;
	}
	if (nx <= 0)
	{
		nx += maxX;
	}
	if (ny >= maxY)
	{
		ny -= maxY;
	}
	if (ny <= 0)
	{
		ny += maxY;
	}
	newx = nx;
	newy = ny;
}








