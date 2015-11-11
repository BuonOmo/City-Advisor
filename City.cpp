/*************************************************************************
								  City
                             -------------------
    début                : 20/10/15
    copyright            : (C) 2015 par LEPIC/BUONOMO
*************************************************************************/

//---------- Réalisation de la classe City (fichier City.cpp) -------

#include "City.h"

//----------------------------------------------------- Méthodes publiques

void City::AddEvent(long IDSensor, int year,int month,int day, int hour, int minute, int wDay,char trafic)
{
#ifdef MAP
	cout << "# Appel de AddEvent (City)" << endl;
#endif
	Sensor* InsSensor(find(IDSensor));
	if (InsSensor!= NULL)
	{
		InsSensor->Add( year, month, day,  hour,  minute, wDay, trafic);
	}
	else
	{
		Sensor* newOne = new Sensor(IDSensor, root);
		newOne->Add( year, month, day,  hour,  minute, wDay, trafic);
	}
}
void City::StatSensor(long idSensor)
{
#ifdef MAP
	cout << "# Appel a statSensor (City)" << endl;
#endif

	Sensor* SToStat = find (idSensor);

	if (SToStat!=NULL)
	{
		long green = SToStat->Count('V');
		long yellow = SToStat->Count('J');
		long red = SToStat->Count('R');
		long black = SToStat->Count('N');
		long sum = green+yellow+black+red;

		sum = (sum==0)? 1 : sum ;

		cout << "V " <<(green*100)/sum <<"%"<< endl;
		cout << "J " <<(yellow*100)/sum <<"%"<< endl;
		cout << "R " <<(red*100)/sum  <<"%"<< endl;
		cout << "N " <<(black*100)/sum  <<"%"<< endl;
	}
	else
	{
		cout << "# Erreure : le capteur " << idSensor << " n’existe pas" << endl;
	}
} //----- Fin de Méthode

void City::JamDay (int wDay)
{
	#ifdef MAP
		cout << "# Appel a jamDay (City)" << endl;
	#endif
		long jam;
		long sum;
	for (int hourCount = 0 ; hourCount< 24; hourCount++)
	{
		jam=Sensor::CountInAllSensor(root,'N',wDay,hourCount)+Sensor::CountInAllSensor(root,'R',wDay,hourCount);
		sum=Sensor::CountInAllSensor(root,'A',wDay,hourCount);
		sum = (sum==0)? 1 : sum;
		cout <<wDay+1 << " "<< hourCount <<" "<< (jam * 100) / sum << "%" <<endl;
	}
}



void City::StatDay(int wDay)
{
	#ifdef MAP
		cout << "# Appel a stateDay City" << endl;
	#endif
	long green = Sensor::CountInAllSensor(root,'V',wDay);
	long yellow = Sensor::CountInAllSensor(root,'J',wDay);
	long red = Sensor::CountInAllSensor(root,'R',wDay);
	long black = Sensor::CountInAllSensor(root,'N',wDay);
	long sum = green+yellow+black+red;
	sum = (sum==0)? 1 : sum;
	cout << "V " <<(green*100)/sum <<"%"<< endl;
	cout << "J " <<(yellow*100)/sum <<"%"<< endl;
	cout << "R " <<(red*100)/sum <<"%"<< endl;
	cout << "N " <<(black*100)/sum <<"%"<< endl;
}

void City::Optimise(int wDay,int startHour, int endHour,int rideLength ,long* idSensors )
{
#ifdef MAP
	cout << "# Appel de Opt" << endl;
#endif
	const int timeMax = 60 *endHour-startHour;
	int optHour;
	int optMinute;
	bool aRideHasBeenFound = false;
	int optTime = timeMax; // en minutes
	for (int countHour(startHour) ; countHour < endHour ; countHour++)
	{
		for (int countMinute(0) ; countMinute < 60 ; countMinute++)
		{

			int curRideTime = 0;
			int nbTraveledSegment = 0;
			int curHour = countHour;
			int curMinute = countMinute;

			for (int IdSensorIndex= 0;IdSensorIndex<rideLength ; IdSensorIndex++)
			{

				if ( curRideTime>=optTime || curHour>=timeMax )
				{
					break;
				}
				Sensor* cur = find(idSensors[IdSensorIndex]);
				if (cur==NULL)
				{
					break ;
				}
				double green = cur->Count('V',wDay,curHour,curMinute);
				double yellow = cur->Count('J',wDay,curHour,curMinute);
				double red = cur->Count('R',wDay,curHour,curMinute);
				double black = cur->Count('N',wDay,curHour,curMinute);
				double sum = green+yellow+black+red;
				while (sum ==0)
				{
					// recherche d’une valeure sur le capteur présent,
					// en avancant minute par minute.
					curRideTime+=1;
					curMinute += 1;
					curHour+= curMinute/60;
					curMinute= curMinute % 60;

					green = cur->Count('V',wDay,curHour,curMinute);
					yellow = cur->Count('J',wDay,curHour,curMinute);
					red = cur->Count('R',wDay,curHour,curMinute);
					black = cur->Count('N',wDay,curHour,curMinute);
					sum = green+yellow+black+red;

				}
				int SegementTime = int (green/sum+2*yellow/sum+4*red/sum+10*black/sum);
				curRideTime+=SegementTime;
				curMinute += SegementTime;
				curHour+= curMinute/60;
				curMinute-= (curMinute/60)* 60;
				nbTraveledSegment++;
			}
			if (nbTraveledSegment == rideLength && curRideTime < optTime)
			{
				optHour = countHour;
				optMinute = countMinute;
				optTime = curRideTime;
				aRideHasBeenFound = true;
			}
		}
	}
	if (aRideHasBeenFound)
	{
		cout <<wDay+1<<" "<<optHour<<" "<<optMinute<<" "<<optTime<< endl;
	}
}

//-------------------------------------------- Constructeurs - destructeur

City::City ( const City & aCity )
{
#ifdef MAP
    cout << "# Appel au constructeur de copie de <City>" << endl;
#endif
    this->root = new Sensor(*(aCity.root));

} //----- Fin de City (constructeur de copie)


City::City ( )
{
#ifdef MAP
    cout << "# Appel au constructeur de <City>" << endl;
#endif

    root = NULL;
} //----- Fin de City


City::~City ( )
{
#ifdef MAP
    cout << "# Appel au destructeur de <City>" << endl;
#endif
    delete(root);
} //----- Fin de ~City

//-------------------------------------------------------- Méthodes privées

Sensor* City::find(long idSensor)
{

#ifdef MAP
    cout << "# Appel de find (City)" << endl;
#endif
	return Sensor::Find(idSensor,root);
}
void City::addSensor (long idSensor)
{
	{
#ifdef MAP
    cout << "# Appel de addSensor (City)" << endl;
#endif
		Sensor ( idSensor , root);
	}
}
