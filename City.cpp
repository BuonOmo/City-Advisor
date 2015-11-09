/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <City> (fichier ${file_name}) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "City.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

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
		long vers = SToStat->count('V');
		long jaune = SToStat->count('J');
		long rouge = SToStat->count('R');
		long noire = SToStat->count('N');
		long somme = vers+jaune+noire+rouge;
		//cout << "somme" << somme << endl;
		somme = (somme==0)? 1 : somme ;
		//cout << "V" <<vers << endl;
		//cout << "J" <<jaune << endl;
		//cout << "R" <<rouge << endl;
		//cout << "N" <<noire << endl<< endl <<endl;

		cout << "V " <<((vers*1000)/somme+5)/10 <<"%"<< endl;
		cout << "J " <<((jaune*1000)/somme+5)/10  <<"%"<< endl;
		cout << "R " <<((rouge*1000)/somme+5)/10  <<"%"<< endl;
		cout << "N " <<((noire*1000)/somme+5)/10  <<"%"<< endl;
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
		long noir;
		long total;
	for (int hourCount = 0 ; hourCount< 24; hourCount++)
	{
		noir=Sensor::countInAllSensor(root,'N',wDay,hourCount);
		total=Sensor::countInAllSensor(root,'A',wDay,hourCount);
		cout << hourCount << ((noir*1000)/total+5)/10<< endl; //TODO 	affigage
	}
}



void City::statDay(int wDay)
{
	#ifdef MAP
		cout << "Appel a stateDay City" << endl;
	#endif
	long vers = Sensor::countInAllSensor(root,'V',wDay);
	long jaune = Sensor::countInAllSensor(root,'J',wDay);
	long rouge = Sensor::countInAllSensor(root,'R',wDay);
	long noire = Sensor::countInAllSensor(root,'N',wDay);
	long somme = vers+jaune+noire+rouge;
	cout << "V " <<((vers*1000)/somme+5)/10 <<"%"<< endl;
	cout << "J " <<((jaune*1000)/somme+5)/10 <<"%"<< endl;
	cout << "R " <<((rouge*1000)/somme+5)/10 <<"%"<< endl;
	cout << "N " <<((noire*1000)/somme+5)/10 <<"%"<< endl;
}

//------------------------------------------------- Surcharge d'opérateurs
//City & City::operator = ( const City & aCity )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
City::City ( const City & aCity )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <City>" << endl;
#endif
    root = NULL;
    nbSensors = 0;

} //----- Fin de City (constructeur de copie)


City::City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <City>" << endl;
#endif

    root = NULL;
    nbSensors = 0;
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
bool City::sensorExiste(long idSensor)
{
#ifdef MAP
    cout << "Appel a sensorExiste (City)" << endl;
#endif
	Sensor* cur = root;
	while (cur->hasNext())
	{
		if (cur->getId() == idSensor)
		{
			return true;
		}
	}
	return false;
}
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


