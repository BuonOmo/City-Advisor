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
		cout <<"addEvent befor root:"<< root << endl;
		Sensor* newOne = new Sensor(IDSensor, root);
		cout <<"addEvent root:"<< root << "newOne" <<newOne<<endl;
		newOne->add( year, month, day,  hour,  minute, wDay, trafic);
	}
}
void City::statSensor(int idSensor)
// Algorithme :
{
#ifdef MAP
    cout << "Appel a statSensor (City)" << endl;
#endif

	cout << "entre dans statSensor" << endl;
	Sensor* SToStat = find (idSensor);
	cout << "entre dans statSensor" << SToStat->getId() << endl;
	if (SToStat!=NULL)
	{
		int vers = SToStat->count('V');
		int jaune = SToStat->count('J');
		int rouge = SToStat->count('R');
		int noire = SToStat->count('N');
		int somme = vers+jaune+noire+rouge;
		cout << "somme" << somme << endl;
		somme = (somme==0)? 1 : somme ;
		cout << "V" <<vers << endl;
		cout << "J" <<jaune << endl;
		cout << "R" <<rouge << endl;
		cout << "N" <<noire << endl<< endl <<endl;

		cout << "V" <<(vers*100)/somme << endl;
		cout << "J" <<(jaune*100)/somme << endl;
		cout << "R" <<(rouge*100)/somme << endl;
		cout << "N" <<(noire*100)/somme << endl;
	}
	else
	{
		cout << "error sesor do not exist" << endl;
	}
} //----- Fin de Méthode

int* City::jamDay (int wDay)
{
	#ifdef MAP
		cout << "Appel a jamDay (City)" << endl;
	#endif
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



void City::statDay(int wDay)
{
	#ifdef MAP
		cout << "Appel a stateDay City" << endl;
	#endif
	int vers = Sensor::countInAllSensor(root,'V',wDay);
	int jaune = Sensor::countInAllSensor(root,'J',wDay);
	int rouge = Sensor::countInAllSensor(root,'R',wDay);
	int noire = Sensor::countInAllSensor(root,'N',wDay);
	int somme = vers+jaune+noire+rouge;
	cout << "V" <<(vers*100)/somme << endl;
	cout << "J" <<(jaune*100)/somme << endl;
	cout << "R" <<(rouge*100)/somme << endl;
	cout << "N" <<(noire*100)/somme << endl;
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
    if (Sensor::find(idSensor,root)!=NULL)
	{
    	long i = Sensor::find(idSensor,root)->getId();
    	cout << "find"<<i << endl;
	}
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


