#include "Simulation.h"
#include "Graph.h"

using namespace std;
int main(void) {

	srand(time(NULL));
	Simulation simPtr;	//se inicializa la simulación.
	
	
		Graph myGUI;	//Objeto que permitirá recuperar información de la GUI.
		if (!(myGUI.get_info()))
		{

			simPtr.firstData(myGUI);	//Recupero los primeros datos (necesarios para iniciar las cosas invariantes)
			simPtr.generateBlobs(simPtr.blobNum);		//genero la cantidad de blobs iniciales
			simPtr.generateFood(simPtr.foodNum);		//genero la cantidad de comida inicial.
			
			while (simPtr.blobNum && !myGUI.getClose())
			{
				myGUI.grafica(simPtr);
			}


		}




	return 0;
}