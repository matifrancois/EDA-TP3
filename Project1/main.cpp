#include "Simulation.h"
#include "Graph.h"

using namespace std;
int main(void) {

	srand(time(NULL));
	Simulation *simPtr = new (throw) Simulation;	//se inicializa la simulaci�n.
	if (!(simPtr == NULL))
	{
		Graph myGUI;	//Objeto que permitir� recuperar informaci�n de la GUI.
		if (!(myGUI.getinfo()))
		{
			simPtr->firstData();	//Recupero los primeros datos (necesarios para iniciar las cosas invariantes)
			simPtr->generateBlobs(simPtr->blobNum);		//genero la cantidad de blobs iniciales
			simPtr->generateFood(simPtr->foodNum);		//genero la cantidad de comida inicial.
			
			while (simPtr->blobNum && myGUI.isGameFinished())	//ac� habr�a que hacer alg�n loop con alguna funci�n de la GUI supongo pero no s� c�mo.
			{
				simPtr->tick++;
				simPtr->getData();
				simPtr->gameLoop();
			}


		}
	}




	//objetoGraph
	//Llamo GUI inicio
	//parser
	//initSim
	//Dentro de Sim
	//updateSim(Graph)
	//


	/*tick=0 inicializar simulaci�n(dubujar blobs, comida, etc.)
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
	10.Graficar

	*/



	return 0;
}