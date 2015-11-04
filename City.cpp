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
	Sensor* InsSensor(find(IDSensor));
		if (InsSensor!= NULL)
	{
		InsSensor->add( year, month, day,  hour,  minute, wDay, trafic);
	}
	else
	{
				Sensor newOne(IDSensor, root);
		cout << "ça passe7" << endl;
		newOne.add( year, month, day,  hour,  minute, wDay, trafic);
	}
}
int* City::statSensor(int idSensor)
// Algorithme :
{
	Sensor* SToStat = find (idSensor);
	int* toReturn = new int(4);
	if (SToStat!=NULL)
	{
		int vers = SToStat->count('V');
		int jaune = SToStat->count('J');
		int rouge = SToStat->count('R');
		int noire = SToStat->count('N');
		int somme = vers+jaune+noire+rouge;
		toReturn[0]= (vers*100)/somme;
		toReturn[1]= (jaune*100)/somme;
		toReturn[2]= (rouge*100)/somme;
		toReturn[3]= (noire*100)/somme;
	}
	else
	{

		toReturn[0]= -1;
		toReturn[1]= -1;
		toReturn[2]= -1;
		toReturn[3]= -1;
	}
	return toReturn;

} //----- Fin de Méthode

int* City::jamDay (int wDay)
{
	int* noir = new int(24);
	int* total = new int(24);
	for (int i = 0 ; i< 24; i++)
	{
		noir[i]=0;
		total[i]=0;
	}
	Sensor* cur = root;
	while (cur->hasNext())
	{
		for (int h = 0; h <24 ; h++)
		{
			noir[h]+= cur->count( 'N', wDay, h);
			total[h]+= cur->count( 'A', wDay, h);
		}
	}
	for (int h = 0; h <24 ; h++)
	{
		noir[h]*=100;
		noir[h]/=total[h];
	}
	return noir;
}
int* City::statDay(int wDay)
{
	int* stat = new int(4);
	for (int i = 0 ; i< 4; i++)
	{
		stat[i]=0;
	}
	Sensor* cur = root;
	while (cur->hasNext())
	{
		stat[0]+= cur->count( 'V', wDay);
		stat[1]+= cur->count( 'J', wDay);
		stat[2]+= cur->count( 'R', wDay);
		stat[3]+= cur->count( 'N', wDay);
	}
	int somme = stat[0]-stat[1]-stat[2]-stat[3];
	for (int i= 0; i <24 ; i++)
	{
		stat[i]*=100;
		stat[i]/=somme;
	}
	return stat;
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

    root = new Sensor;
    nbSensors = 0;
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
} //----- Fin de ~City


//------------------------------------------------------------------ PRIVE
bool City::sensorExiste(long idSensor)
{
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
		Sensor* cur = root;
		while (cur->hasNext())
	{
		if (cur->getId() == idSensor)
		{
			return cur;
		}
	}
	return NULL ;
}
void City::addSensor (long idSensor)
{
	{
		Sensor ( idSensor , root);
	}
}
//----------------------------------------------------- Méthodes protégées


