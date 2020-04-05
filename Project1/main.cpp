#include "Simulation.h"

using namespace std;
int main(void) {
	cout << "hello world" << endl;
	srand(time(NULL));
	Food *foodPtr=new Food(5.0, 12.0);
	cout << foodPtr->getFoodPosX() << endl;
	cout << foodPtr->getFoodPosY() << endl;
	Food *foodPtr2 = new Food(18.1, 22.0);
	cout << foodPtr2->getFoodPosX() << endl;
	cout << foodPtr2->getFoodPosY() << endl;

	double x = -2;
	double y = -3;
	double arct = atan2(y,x);
	cout << arct << endl;

	/*tick=0 inicializar simulación(dubujar blobs, comida, etc.)
	tick=1 
	1.Check for blobDeath, eliminate blobs
	2.Calculate new position for remaining blobs
	3.move blobs
	4.check for collision
	5.blobMerge
	6.check for food eaten
	7.blobBirth
	8.restore food
	9.++tick

	*/



	return 0;
}