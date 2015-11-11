/*************************************************************************
                           Sensor  -  classe des capteurs
                             -------------------
    début                : 20/10/15
    copyright            : (C) 2015 par LEPIC/BUONOMO
*************************************************************************/

//---------- Réalisation de la classe Sensor (fichier Sensor.cpp) -------

#include "Sensor.h"

//----------------------------------------------------- Méthodes publiques

int Sensor::Count(char trafic, int wDay, int hour, int minute) const
// Algorithme :
// Création de bornes pour limiter la recherche sur eventMatrix
// aux elements souhaités.
{
	// definintion des bornes de la somme :
	int traficMin;
	int traficMax;
	switch (trafic)
	{
	case('V'):
		traficMax= 1;
		traficMin= 0;
		break;
	case ('J') :
		traficMax= 2;
		traficMin= 1;
		break;
	case ('R'):
		traficMax= 3;
		traficMin= 2;
		break;
	case ('N'):
		traficMax= 4;
		traficMin= 3;
		break;
	default:
		traficMin= 0;
		traficMax= 4;
		break;

	}

	 int wDMin = (wDay >= 0) ? wDay : 0 ;
	 int wDMax = (wDay >= 0) ? wDay+1 : 7;

	 int hourMin = (hour >= 0) ? hour :0;
	 int hourMax = (hour >= 0) ? hour+1 :24;

	 int minuteMin = (minute >= 0) ? minute : 0;
	 int minuteMax = (minute >= 0) ? minute + 1 : 60;

// réalisation de la somme
	 int sum = 0;
	 for (int mnCount(minuteMin) ; mnCount < minuteMax ; mnCount++)
	 	{
	 		for (int hCount(hourMin) ; hCount < hourMax ; hCount++)
	 		{
	 			for (int dayCount(wDMin) ; dayCount < wDMax ; dayCount ++)
	 			{
	 				for (int traficCount(traficMin) ; traficCount < traficMax ; traficCount++ )
	 				{
	 					sum += eventMatrix[mnCount][hCount][dayCount][traficCount];
	 				}
	 			}
	 		}
	 	}
	 return sum ;
}
int Sensor::CountInAllSensor(Sensor*  rootSensorTree, char trafic, int wDay , int hour, int minute)
//Algorithme :
// appel itératife de countInAllSensor. Lors des itération 'rootSensorTree' n'est alors
// plus la racine de l'arbre entier mais celle de sous arbres de celui-ci.
{
	int result =rootSensorTree->Count(trafic,  wDay ,  hour,  minute);
	if (rootSensorTree->nextL!=NULL)
	{
		result += Sensor::CountInAllSensor(rootSensorTree->nextL,  trafic,  wDay ,  hour,  minute);
	}
	if (rootSensorTree->nextR!=NULL)
	{
		result += Sensor::CountInAllSensor(rootSensorTree->nextR,  trafic,  wDay ,  hour,  minute);
	}
	return result;
}

void Sensor::Add(int year, int month, int day, int hour, int minute, int wDay, char trafic)
{
	int traficInt;
	switch  (trafic)
	{
		case ('V'):
			traficInt =0;
			break;
		case ('J'):
			traficInt =1;
			break;
		case ('R'):
			traficInt =2;
			break;
		case ('N'):
			traficInt =3;
			break;
		default :
			traficInt=0;
			break;
	}

	eventMatrix[minute][hour][wDay][traficInt]++;
}



 Sensor* Sensor::Find(long idSensor,Sensor*  rootSensorTree)
// Algorithme :
// recherche au sein de l’arbre
{
	if (rootSensorTree==NULL)
	{
		return NULL;
	}
	else
	{
		Sensor* cur = rootSensorTree;
		while (cur != NULL)
		{
			if (idSensor == cur->id)
			{
				return cur;
			}

			if (idSensor > cur->id)
			{
				cur= cur->nextR ;
			}
			else
			{
				cur = cur->nextL;
			}
		}
		return NULL;
	}
}

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor (long idSensor, Sensor*&  rootSensorTree) :
		id (idSensor)
{
	//insertion du capteur dans l'arbre de racine 'rootSensorTree'
	if (rootSensorTree == NULL)
	{
		rootSensorTree=this;
	}
	else
	{
		Sensor * cur = rootSensorTree;
		Sensor * curPrevus;

		// non respect du guide de style sur l’utilisation du this pour
		// mieux differencier "this -> id " de "cur -> id"
		while (cur != NULL)
		{
			curPrevus = cur ;
			cur = (cur -> id > this -> id) ? cur -> nextL : cur -> nextR;
		}

		if(curPrevus -> id > this -> id)
		{
			curPrevus -> nextL = this;
		}
		else
		{
			curPrevus -> nextR = this;
		}
	}

	//initialisation de eventMatrix
	for (int mnCount(0) ; mnCount < 60; mnCount++)
	{
		for (int hCount(0) ; hCount < 24 ; hCount++)
		{
			for (int dayCount(0) ; dayCount < 7; dayCount ++)
			{
				for (int traficCount(0) ; traficCount < 4 ; traficCount++ )
				{
					eventMatrix[mnCount][hCount][dayCount][traficCount]=0;
				}
			}
		}
	}
}



Sensor::Sensor(const Sensor & aSensor)
{
	this->id = aSensor.id;
	//copie du tableau eventMatrx
	for (int mnCount= 0; mnCount < 60; mnCount++)
	{
		for (int hCount = 0; hCount < 24 ; hCount++)
		{
			for (int dayCount = 0 ; dayCount < 7; dayCount ++)
			{
				for (int traficCount=0 ; traficCount < 4 ; traficCount++ )
				{
					this->eventMatrix[mnCount][hCount][dayCount][traficCount]=
							aSensor.eventMatrix[mnCount][hCount][dayCount][traficCount];
				}
			}
		}
	}

	// copie des elements suivant de l’arbre.
	if (aSensor.nextL != NULL)
	{
		nextL = new Sensor(*(aSensor.nextL));
	}
	else
	{
		this -> nextL = NULL;
	}
	if (aSensor.nextR != NULL)
	{
		this -> nextR= new Sensor(*(aSensor.nextR));
	}
	else
	{
		this -> nextR = NULL;
	}
}


Sensor::~Sensor ()
// Algorithme :
// destruction itérative des capteurs (Sensors)
{
	if (nextL != NULL)
	{
		delete nextL;
	}
	if (nextR != NULL)
	{
		delete nextR;
	}
}
