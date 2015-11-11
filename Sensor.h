/*************************************************************************
                           Sensor  -  classe des capteurs
                             -------------------
    début                : 20/10/15
    copyright            : (C) 2015 par LEPIC/BUONOMO
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ------

#ifndef SENSOR_H
#define SENSOR_H
//------------------------------------------------------------------ Types
using namespace std;
//----------------------------------------------------------------Includes

#include <iostream>
//------------------------------------------------------------------------
// Rôle de la classe Sensor
//

class Sensor
{
public:
	//----------------------------------------------------- Méthodes publiques

	int count(char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1)const;
	// Mode d'emploi :
	// Compte les évenement d’un capteur selon les critères choisis. les valeurs par
	// defaut indiquent que la methode ne tient pas compte du paramètre en valeur par
	// defaut, i.e (wDay = -1) <=> (wDay = [1, .. , 7])
	// Contrat :
	// les données sont cohérentes (wDay dans [0 ; 6], hour dans [0 ; 59], etc) et trafic
	// peut prendre les valeurs V, J, R et N.



	static int countInAllSensor(Sensor*  rootSensorTree, char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1);
	// Mode d'emploi :
	// Compte les évenement de tous les capteurs d’un arbre en partant de la racine entrée,
	// selon les critères choisis. les valeurs par defaut indiquent que la methode ne tient
	// pas compte du paramètre en valeur par defaut, i.e (wDay = -1) <=> (wDay = [1, .. , 7])
	// Contrat :
	// les données sont cohérentes (wDay dans [0 ; 6], hour dans [0 ; 59], etc) et trafic
	// peut prendre les valeurs V, J, R et N.



	void add(int year, int month, int day, int hour, int minute, int wDay, char trafic);
    // Mode d'emploi :
	// ajoute un evenement au capteur
	// Contrat :
	// les données sont cohérentes (wDay dans [0 ; 6], hour dans [0 ; 59], etc) et trafic
	// peut prendre les valeurs V, J, R et N.



	static Sensor* find(long idSensor,Sensor*  rootSensorTree);
	// Mode d'emploi :
	// trouve un capteur selon son identifiant dans un arbre de capteurs dont la racine
	// est donnée en paramètre. Renvoi NULL s'il n'existe pas.
	// Contract :
	//l'arbre est trié. Ceci est assuré par le constructeur de Sensor


	//-------------------------------------------- Constructeurs - destructeur

	Sensor (long idSensor, Sensor*&  rootSensorTree);
	// Mode d'emploi :
	// Crée un capteur (Sensor) et l'ajoute dans un arbre (tel qu'il soit encore trié).
	// Contract :
	// idSensor n’est l’identifiant d'aucun capteur déjà existant.

	Sensor ( const Sensor & aSensor );
	// Mode d'emploi :(constructeur de copie)
	// copie un capteur et toutes dans l'arbre dont il est extrais.


	virtual ~Sensor ();
	// Mode d'emploi :
	// détruit un capteur et toutes ses branches dans l'arbre dont il est extrait.

	//------------------------------------------------------------------ PRIVE
private:

	long id;
	// idenfiant

	Sensor * nextR;
	Sensor * nextL;
	// branches droites et gauches

	int eventMatrix [60][24][7][4];
	// tableau recensant tout les evenements du capteur
};

#endif // SENSOR_H
