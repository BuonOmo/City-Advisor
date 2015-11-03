/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <City> (fichier ${file_name}) ------
#if ! defined CITY_H
#define CITY_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//----------------------------------------------------------------Includes
#include "Sensor.h"

//------------------------------------------------------------------------
// Rôle de la classe <City>
//
//
//------------------------------------------------------------------------

class City
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    	void addEvent(long IDSensor, int year,int month,int day, int hour, int minute);
    // Contrat :
    //


    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
		int* statSensor(int sensor);
    // Contrat :
    //


    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
		int* statDay (int day);
    // Contrat :
    //


    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
		int* jamDay(int idcapteur);
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    City & operator = ( const City & unCity );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    City ( const City & unCity );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    City ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~City ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	Sensor* find(int idSensor);
	bool sensorExiste(long idSensor);
	void addSensor (long idSensor);

//----------------------------------------------------- Attributs protégés
	Sensor* root;
	int nbSensors;

};

//--------------------------- Autres définitions dépendantes de <City>

#endif // ${include_guard_symbol}


