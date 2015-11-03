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
int* City::statSensor(int idSensor)
// Algorithme :
{
	Sensor* SToStat = find (idSensor);
	if (SToStat!=NULL)
	{
		int vers = SToStat->count('V');
		int jaune = SToStat->count('J');
		int rouge = SToStat->count('R');
		int noire = SToStat->count('N');
		int somme = vers+jaune+noire+rouge;
		int* toReturn = new int(4);
		toReturn[0]= somme;
	}
	return new int(1);

} //----- Fin de Méthode


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

    root = NULL ;
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


