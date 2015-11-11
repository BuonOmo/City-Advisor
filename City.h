/*************************************************************************
                           	   	   City
                             -------------------
    début                : 20/10/15
    copyright            : (C) 2015 par LEPIC/BUONOMO
*************************************************************************/

//---------- Interface de la classe <City> (fichier City.h) ------

#ifndef CITY_H
#define CITY_H



//------------------------------------------------------------------ Types
using namespace std;
//----------------------------------------------------------------Includes
#include "Sensor.h"
#include <string>
#include <iostream>

//------------------------------------------------------------------------
// Rôle de la classe City :
//conient la racine d'un arbre de capteurs et réalise des analyses sur ces
//derniers.
//langue : programmation en anglais, commentaires en français.
//------------------------------------------------------------------------

class City
{

public:

//----------------------------------------------------- Méthodes publiques

	void addEvent(long IDSensor, int year,int month,int day, int hour, int minute, int wDay,char trafic);
    // Mode d'emploi :
    // ajout un événement a un capteur ou crée le capteur s'il n'existe pas.
	// Contrat :
	// les données sont cohérentes (wDay dans [0 ; 6], hour dans [0 ; 59], etc) et trafic
	// peut prendre les valeurs V, J, R et N.

	void statDay (int wDay);
	// Mode d'emploi :
	// affiche les statistiques du jour de la semaine selon STATS_D7 du cahier des charges.
    // Contrat :
    // wDay dans [0 ; 6].

	void jamDay(int wDay);
	// Mode d'emploi :
	// affiche le pourcentage de bouchons par heure de tout les capteurs pour le jour de la
	// semaine entré en paramètre. Suit JAM_DH du cahier des charges.
	// Contrat :
	// wDay dans [0 ; 6].



	void statSensor(int idSensor);
	// Mode d'emploi :
	// affiche les statistiques d'un capteur dont l'identifiant est entré en paramètre.
	// Suit STATS_C du cahier des charges.
    // Contrat :
    // un évenement a été enregitré pas le capteur dont l'identifiant est idSensor.

	void opt(int wDay, int startHour, int endHour,int rideLength ,long* idSensors );


//-------------------------------------------- Constructeurs - destructeur

    City ( const City & unCity );
    // Mode d'emploi (constructeur de copie) :
    // copie une Ville y compris les capteurs qu'elle contient.

    City ( );
    // Mode d'emploi :
    // Crée une ville sans capteurs.


    virtual ~City ( );
    // Mode d'emploi : détruit une Ville y compris les capteurs qu'elle contient.

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

	void addSensor (long idSensor);
    // Mode d'emploi :
    // ajoute un capteur dans l'abre des capteurs.
	// Contrat :
	// l’idenfiant ne doit pas déjà être pris par un autre capteur.


	Sensor* find(long idSensor);
	// Mode d'emploi :
	// recherche et renvoi un pointeur de capteur à partir de son identifiant.
	// Renvoi NULL si le capteur n'existe pas.
	// Contrat :
	// l’idenfiant ne doit pas déjà être pris par un autre capteur.

//----------------------------------------------------- Attributs privés

	Sensor* root;

};

#endif // CITY_H


