/*************************************************************************
                           City  -  description
                             -------------------
    début                : 20/10/15
    copyright            : (C) 2015 par LEPIC/BUONOMO
*************************************************************************/

//---------- Réalisation de la classe City (fichier City.cpp) -------

//---------------------------------------------------------------- INCLUDE


//------------------------------------------------------ Include personnel
#include "City.h"

//----------------------------------------------------- Méthodes publiques
void City::addEvent(long IDSensor, int year,int month,int day, int hour, int minute, int wDay,char trafic)
{
	#ifdef MAP
		cout << "Appel a addEvent (City)" << endl;
	#endif
	Sensor* InsSensor(find(IDSensor));
	if (InsSensor!= NULL)
	{
		InsSensor->add( year, month, day,  hour,  minute, wDay, trafic);
	}
	else
	{
		//cout <<"addEvent befor root:"<< root << endl;
		Sensor* newOne = new Sensor(IDSensor, root);
		//cout <<"addEvent root:"<< root << "newOne" <<newOne<<endl;
		newOne->add( year, month, day,  hour,  minute, wDay, trafic);
	}
}
void City::statSensor(int idSensor)
// Algorithme :
{
#ifdef MAP
    cout << "Appel a statSensor (City)" << endl;
#endif

	//cout << "entre dans statSensor" << endl;
	Sensor* SToStat = find (idSensor);
	//cout << "entre dans statSensor" << SToStat->getId() << endl;
	if (SToStat!=NULL)
	{
		long green = SToStat->count('V');
		long yellow = SToStat->count('J');
		long red = SToStat->count('R');
		long black = SToStat->count('N');
		long sum = green+yellow+black+red;
		//cout << "somme" << somme << endl;
		sum = (sum==0)? 1 : sum ;
		//cout << "V" <<vers << endl;
		//cout << "J" <<jaune << endl;
		//cout << "R" <<rouge << endl;
		//cout << "N" <<noire << endl<< endl <<endl;

		cout << "V " <<(green*100)/sum <<"%"<< endl;
		cout << "J " <<(yellow*100)/sum <<"%"<< endl;
		cout << "R " <<(red*100)/sum  <<"%"<< endl;
		cout << "N " <<(black*100)/sum  <<"%"<< endl;
	}
	else
	{
		cout << "error sesor do not exist" << endl;
	}
} //----- Fin de Méthode

void City::jamDay (int wDay)
{
	#ifdef MAP
		cout << "Appel a jamDay (City)" << endl;
	#endif
		long jam;
		long sum;
	for (int hourCount = 0 ; hourCount< 24; hourCount++)
	{
		jam=Sensor::countInAllSensor(root,'N',wDay,hourCount)+Sensor::countInAllSensor(root,'R',wDay,hourCount);
		sum=Sensor::countInAllSensor(root,'A',wDay,hourCount);
		cout <<wDay << ""<< hourCount <<" "<< (jam*100)/sum<< "%" <<endl;
	}
}



void City::statDay(int wDay)
{
	#ifdef MAP
		cout << "Appel a stateDay City" << endl;
	#endif
	long green = Sensor::countInAllSensor(root,'V',wDay);
	long yellow = Sensor::countInAllSensor(root,'J',wDay);
	long red = Sensor::countInAllSensor(root,'R',wDay);
	long black = Sensor::countInAllSensor(root,'N',wDay);
	long sum = green+yellow+black+red;
	cout << "V " <<(green*100)/sum <<"%"<< endl;
	cout << "J " <<(yellow*100)/sum <<"%"<< endl;
	cout << "R " <<(red*100)/sum <<"%"<< endl;
	cout << "N " <<(black*100)/sum <<"%"<< endl;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
City::City ( const City & aCity )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <City>" << endl;
#endif
    this->root = new Sensor(*(aCity.root));

} //----- Fin de City (constructeur de copie)


City::City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <City>" << endl;
#endif

    root = NULL;
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
    delete(root);
} //----- Fin de ~City


//------------------------------------------------------------------ PRIVE

Sensor* City::find(int idSensor)
{

#ifdef MAP
    cout << "Appel a find (City)" << endl;
#endif
	return Sensor::find(idSensor,root);
}
void City::addSensor (long idSensor)
{
	{
#ifdef MAP
    cout << "Appel a addSensor (City)" << endl;
#endif
		Sensor ( idSensor , root);
	}
}
//----------------------------------------------------- Méthodes protégées


