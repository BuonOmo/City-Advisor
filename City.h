/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <City> (fichier ${file_name}) ------

#ifndef CITY_H
#define CITY_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
using namespace std;
//----------------------------------------------------------------Includes
#include "Sensor.h"
#include <string>
#include <iostream>
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
    	void addEvent(long IDSensor, int year,int month,int day, int hour, int minute, int wDay,char trafic);
    // Contrat :
    //


    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    	void statDay (int wDay);
		void statSensor(int sensor);
    // Contrat :
    //

	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
		void jamDay(int wDay);
	// Contrat :
	//


    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
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
	Sensor* find(int idSensor);
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


	bool sensorExiste(long idSensor);
	void addSensor (long idSensor);

//----------------------------------------------------- Attributs protégés
	Sensor* root;
	int nbSensors;

};

//--------------------------- Autres définitions dépendantes de <City>

#endif // ${include_guard_symbol}


