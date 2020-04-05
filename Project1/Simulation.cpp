#include "Simulation.h"


Simulation::Simulation()
{
}

Simulation::Simulation(double maxX_, double maxY_, int blobNum_, int foodNum_, double maxSpeed_, double alphaSpeed_, 
	double smellRadius_, double randomJiggleLimit_, double babyDeathProb_, double grownDeathProb_, double goodDeathProb_, int mode_)
{
	maxX = maxX_;
	maxY = maxY_;
	blobNum = blobNum_;
	foodNum = foodNum_;
	tick = 0;
	maxSpeed = maxSpeed_;
	alphaSpeed = alphaSpeed_;
	smellRadius = smellRadius_;
	randomJiggleLimit = randomJiggleLimit_;
	babyDeathProb = babyDeathProb_;
	grownDeathProb = grownDeathProb_;
	goodDeathProb = goodDeathProb_;
	mode = mode_;
}

Simulation::~Simulation()
{
}

bool Simulation::generateFood(int foodNum)
{
	bool result = true;
	for (int i = 0; i < foodNum; i++)
	{
		foodPtr[i] = new (nothrow) Food(maxX, maxY);
		if (foodPtr[i]==nullptr)
		{
			result = false;
		}
	}
	return result;
}

bool Simulation::generateBlobs(int blobNum)
{
	bool result = true;
	double maxSpeed_;
	for (int i = 0; i < blobNum; i++)
	{
		if (mode == 1) {
			maxSpeed_ = maxSpeed;
		}
		else {
			maxSpeed_ = randBetweenReal(0.0, maxSpeed);
		}
		blobPtr[i] = new (nothrow) BabyBlob(maxX, maxY, maxSpeed_, alphaSpeed, smellRadius, babyDeathProb);
		if (blobPtr[i] == nullptr)
		{
			result = false;
		}
	}
	return result;
}

void Simulation::blobDeath(void)
{
	for (int i = 0; i < blobNum; i++)

		if (blobPtr[i]->blobFate())	//se decide si un blob debe morir o no.
		{
			clearBlob(i);	//si debe morir, se elimina del arreglo y se ajusta éste de forma que blobNum sea la primera posición libre.
			i--;
		}
}


void Simulation::blobBirth(void)
{
	double maxSpeed_;
	int birthNum = 0;	//cantidad de nacimientos
	for (int i = 0; i < blobNum; i++)
	{
		if (blobPtr[i]->isBlobFull())	//verifica que el blob esté lleno.
		{
			if (mode == 1) {
				maxSpeed_ = maxSpeed; 
			}
			else { 
				maxSpeed_ = randBetweenReal(0.0, maxSpeed); 
			}
			blobPtr[blobNum + birthNum] = new BabyBlob(maxX, maxY, maxSpeed_, alphaSpeed, smellRadius, babyDeathProb);	//si lo está, se genera un BbyBlob en una posición aleatoria.
			birthNum++;
		}
	}
	blobNum += birthNum;	//se ajusta la cantidad de blobs totales en el tablero.
}

void Simulation::clearBlob(int i)
{
	delete blobPtr[i];
	for (int j = i; j<(blobNum - 1); j++)
	{
		blobPtr[j] = blobPtr[j + 1];
	}
	blobNum--;
}

void Simulation::blobMerge(void)
{
	double distance;
	int totalMerges = 0;	//cantidad total de merges para luego ajustar la cantidad de blobs
	int merges = 0;			//cantidad de merges para luego calcular el promedio de la dirección y velocidad.
	int newcode = 0;
	for (int i = 0; i < blobNum; i++)
	{
		if (!((blobPtr[i]->getGroup()) == GOODOLDGROUP))		//revisa que el blob no sea uno de tipo GoodOldBlob.
		{
			for (int j = i+1; j < blobNum; j++)				//compara con los otros blobs en el arreglo.
			{
				if ((blobPtr[i]->getGroup()) == (blobPtr[j]->getGroup()))	//revisa que los blobs sean del mismo grupo etario
				{
					distance = getDistance(blobPtr[i]->getX(), blobPtr[j]->getX(), blobPtr[i]->getY(), blobPtr[j]->getY());
					if (distance < ((blobPtr[i]->getcolissionRadius()) / 2.0))
					{					
						blobPtr[i]->setDir((blobPtr[i]->getDir()) + (blobPtr[j]->getDir()));	//la idea es agrupar los datos del nuevo Babyblob en blob[i] para luego generarlo.
						blobPtr[i]->setMaxSpeed((blobPtr[i]->getMaxSpeed()) + (blobPtr[j]->getMaxSpeed()));	//se agrupan dirección, velocidad máxmima, y velocidad relativa.
						blobPtr[i]->setAlphaSpeed((blobPtr[i]->getAlphaSpeed()) + (blobPtr[j]->getAlphaSpeed()));
						merges++;
						totalMerges++;
						clearBlob(j);		//una vez que se recuperaron los datos del blob[j], como en la fusión desaparecen los involucrados, podemos eliminar a j ahora
						j--;	//al haberse ajustado el arreglo en clearBlob (disminuyendo en 1 el total), es necesario reducir j en uno para continuar con el for correctamente.
					}
				}
			}
			if (merges > 0) //si hubo algún merge se calcula la dirección y velocidad del nuevo blob.
			{
				blobPtr[i]->setDir(((blobPtr[i]->getDir()) / totalMerges) + randomJiggleLimit);	//se genera la nueva dirección haciendo el promedio y luego sumándole randomJiggleLimit;
				blobPtr[i]->setMaxSpeed((blobPtr[i]->getMaxSpeed()) / totalMerges);	//de forma análoga, se calcula la nueva velocidad máxima y relativa como el promedio de las anteriores.
				blobPtr[i]->setAlphaSpeed((blobPtr[i]->getAlphaSpeed()) / totalMerges);
				blobPtr[i]->setMergeStatus(true);	//se indica que este blob debe dividirse.
				merges = 0;
			}
		}
	}
	blobDivide(totalMerges);	//genera las divisiones de blobs necesarias.
}

void Simulation::blobDivide(int totalMerges)
{
	double maxSpeed_;
	double alphaSpeed_;
	blobNum -= totalMerges;
	for (int i = 0; i < blobNum; i++)
	{
		if (blobPtr[i]->getMergeStatus())	//se fija si es necesario crear un nuevo blob.
		{
			if (mode == 1) {
				maxSpeed_ = blobPtr[i]->getMaxSpeed();
			}
			else {
				maxSpeed_ = randBetweenReal(0.0,blobPtr[i]->getMaxSpeed());
			}
			alphaSpeed_ = blobPtr[i]->getAlphaSpeed();

			switch (blobPtr[i]->getGroup())	//según el grupo de blob, crea un grownblob o un goodoldblob
			{
			case BABYGROUP:
				clearBlob(i);	//el blob que se divide es eliminado, y se agrega otro en la última posición del arreglo disponible.
				i--;
				blobPtr[blobNum] = new GrownBlob(maxX, maxY, maxSpeed_, alphaSpeed_, smellRadius, grownDeathProb);
				blobNum++;
				break;
			case GROWNGROUP:
				clearBlob(i);	//De forma similar si se trata de colisiones de GrownBlobs.
				i--;
				blobPtr[blobNum] = new GoodOldBlob(maxX, maxY, maxSpeed_, alphaSpeed_, smellRadius, grownDeathProb);
				blobNum++;
				break;
			default:
				break;
			}
		}
	}
}

