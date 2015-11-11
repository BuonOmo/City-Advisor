/*************************************************************************
                           City  -  description
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
// Rôle de la classe City
//conient les la racine d'un arbre de capteurs et réalise des annalys sur ces
//derniés.
//langue : progamation en Anglais, commentaire Frasais.
//------------------------------------------------------------------------

class City
{

public:

//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
	//ajout un événement a a capteur et crée le capteur si il n'existe pas.
	//
    	void addEvent(long IDSensor, int year,int month,int day, int hour, int minute, int wDay,char trafic);
    // Contrat :
    // les donés sont sencés : 0 <= minute <60 ect...
    //


    // Mode d'emploi :
    // affiche les statistiques du jour de la seumaine
    	void statDay (int wDay);
    // Contrat :
    //0<=wDAy<7


	// Mode d'emploi :
	// affiche le pourcentage de bouchon par heur de tout les capteur pour le jour de la
	//seumaien entré en paramétre.
		void jamDay(int wDay);
	// Contrat :
	// 0<=wDAy<7


    // Mode d'emploi :
    // affiche les statistiques d'un capteur dont l'identifient est entré en paramétre.
		void statSensor(int Idsensor);
    // Contrat :
    //un évenement a été enregitré pas le capteur dont l'identifient est Idsensor.




//-------------------------------------------- Constructeurs - destructeur
    City ( const City & unCity );
    // Mode d'emploi (constructeur de copie) :
    // copie une Ville icomprie  les capteur qu'elle contien.


    City ( );
    // Mode d'emploi : Crée une ville sans capteur


    virtual ~City ( );
    // Mode d'emploi : détruit une Ville icomprie  les capteur qu'elle contien.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    // Mode d'emploi :
    // ajout un capteur dans l'abre des capteurs.
	void addSensor (long idSensor);

    // Mode d'emploi :
	// rechres et retourne un pointeur de capteur a partire de sont identifiant
	// retourne NULL si le capteur n'existe pas.
	Sensor* find(int idSensor);

//----------------------------------------------------- Attributs protégés
	Sensor* root;

};

//--------------------------- Autres définitions dépendantes de <City>

#endif // ${include_guard_symbol}


