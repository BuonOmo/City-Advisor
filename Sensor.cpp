/*
 * Sensor.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#include "Sensor.h"


int Sensor::count(char trafic, int wDay, int hour, int minute) const
{
	// définitaion des bornes de la somme:
	int traficMin= 0;
	int traficMax= 4;
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
	}
	//cout << "Sensor::count tmin="<<traficMin<<" tman="<<traficMax<<endl;

	 int wDMin = (wDay >0 )? wDay : 0 ;
	 int wDMax = (wDay >0 )? wDay+1 : 7;

	 int hourMin = (hour >0)? hour :0;
	 int hourMax = (hour >0)? hour+1 :24;

	 int minuteMin = (minute >0 )? minute : 0;
	 int minuteMax = (minute >0 )? minute + 1 : 60;

	 int sum = 0;
	 for (int mnCount= minuteMin; mnCount < minuteMax ; mnCount++)
	 	{
	 		for (int hCount = hourMin; hCount < hourMax ; hCount++)
	 		{
	 			for (int dayCount = wDMin ; dayCount < wDMax; dayCount ++)
	 			{
	 				for (int traficCount= traficMin ; traficCount < traficMax ; traficCount++ )
	 				{
	 					if (eventMatrix[mnCount][hCount][dayCount][traficCount]!=0)
	 					{
	 						//cout << "eventMatrix " << mnCount <<" "<<hCount<<" "<< dayCount << " "<<traficCount<<"  = "<<eventMatrix[mnCount][hCount][dayCount][traficCount] << endl;
	 					}
	 					sum += eventMatrix[mnCount][hCount][dayCount][traficCount];
	 				}
	 			}
	 		}
	 	}
	 //cout<<sum <<endl;
	 return sum ;
}
int Sensor::countInAllSensor(Sensor*  arrayRoot, char trafic, int wDay , int hour, int minute)
{
	int result =arrayRoot->count(trafic,  wDay ,  hour,  minute);
	if (arrayRoot->nextL!=NULL)
	{
		result += Sensor::countInAllSensor(arrayRoot->nextL,  trafic,  wDay ,  hour,  minute);
	}
	if (arrayRoot->nextR!=NULL)
	{
		result += Sensor::countInAllSensor(arrayRoot->nextR,  trafic,  wDay ,  hour,  minute);
	}
	return result;
}

void Sensor::add(int year, int month, int day, int hour, int minute, int wDay, char trafic)
{
	//cout << trafic << endl;
	int traficInt=0;
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
	}
	//cout<<"trafic"<<traficInt<<endl;
	(eventMatrix[minute][hour][wDay][traficInt])++;
	//cout << "Sensor::add eventMatrix"<< minute <<" "<< hour << " "<<wDay<<" "<<traficInt <<" ="<<eventMatrix[minute][hour][wDay][traficInt]<<endl;
}


long Sensor::getId() const
{
	return id;
}
 Sensor* Sensor::find(long idSensor,Sensor*  arrayRoot)
{
	 //cout << "find looking for : "<< idSensor<< endl ;
	if (arrayRoot==NULL)
	{
		return NULL;
	}
	else
	{
		Sensor* cur = arrayRoot;
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


bool Sensor::hasNext() const
{
	return !(nextL == NULL)||!(nextR == NULL);
}

Sensor::Sensor (long anId, Sensor*&  rootSensorTree) :
		id(anId)
{
	if (rootSensorTree == NULL)
	{
		rootSensorTree=this;
		previus =  NULL;
	}
	else
	{
		Sensor * cur = rootSensorTree;
		Sensor * curPrevus;


		while (cur != NULL)
		{
			curPrevus = cur ;
			cur = ((cur->id) > this->id )? cur->nextL : cur->nextR;
		}

		if(curPrevus->id > this->id )
		{
			curPrevus->nextL= this;
			this->previus = curPrevus;
		}
		else
		{
			curPrevus->nextR= this;
			this->previus = curPrevus;
		}
	}
	//inicialisation
	for (int mnCount= 0; mnCount < 60; mnCount++)
	{
		for (int hCount = 0; hCount < 24 ; hCount++)
		{
			for (int dayCount = 0 ; dayCount < 7; dayCount ++)
			{
				for (int traficCount=0 ; traficCount < 4 ; traficCount++ )
				{
					eventMatrix[mnCount][hCount][dayCount][traficCount]=0;
				}
			}
		}
	}
}

Sensor::Sensor() :
		id(0)
{
	previus=nextL=nextR= NULL;
	//inicialisation
	for (int mnCount= 0; mnCount < 60 ; mnCount++)
	{
		for (int hCount = 0; hCount < 24 ; hCount++)
		{
			for (int dayCount = 0 ; dayCount < 7; dayCount ++)
			{
				for (int traficCount=0 ; traficCount < 4 ; traficCount++ )
				{
					eventMatrix[mnCount][hCount][dayCount][traficCount]=0;
				}
			}
		}
	}

}

Sensor::~Sensor ()
{
		//TODO reflechir à un destructeur
	//cout << "destructor sensor" << endl;
	if (nextL != NULL)
	{
		delete(nextL);
	}
	if (nextR != NULL)
	{
		delete(nextR);
	}
	//delete this;
}

