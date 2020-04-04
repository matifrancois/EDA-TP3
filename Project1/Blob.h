#ifndef BLOB_H_
#define BLOB_H_


/**********************************
INCLUDE
**********************************/
#include "prototype.h"

/**********************************
CLASS
**********************************/
class Blob
{
public:
	Blob();
	Blob(double posx, double posy, double direction, double sp, double rad);
	~Blob();

	/*Getters*/
	double getX(void);
	double getY(void);
	double getNewx(void);
	double getNewy(void);
	double getSpeed(void);
	double getDir(void);
	double getNewdir(void);
	double getRadius(void);

	/*Setters*/
	void setX(double a);
	void setY(double b);
	void setSpeed(double v);
	void setDir(double k);

	/*Funciones*/
	void newPositions(double maxX, double maxY);

private:
	double x;
	double y;
	double newx;
	double newy;
	double dir;
	double newdir;
	double radius;
	double speed;
	int foodEaten;
	int group;
	double colissionRadius;
};




#endif // !BLOB_H_