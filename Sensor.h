/*************************************************************************
                           Sensor  -  description
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
	// Mode d'emploi :
	// Compte les évenement précisé d’un capteur. les valeurs par défaut indiquent
	// que la methode compte le nombre d'évenement pour tout les valeurs (exemple si
	// minute = -1 on compte pour minute = 0 à 59)

	int count(char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1)const;
	// Contract :
    // les donés sont sencés : 0 <= minute <60 ect... .


	// Mode d'emploi :
	// Compte les évenement précisé de tout un arbre dont la racine est donné en paramétre.
	//les valeurs par défaut indiquent que la methode compte le nombre d'évenement pour tout
	//les valeurs (exemple si minute = -1 on compte pour minute = 0 à 59).
	static int countInAllSensor(Sensor*  rootSensorTree, char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1);
	// Contract :
    // les donés sont sencés : 0 <= minute <60 ect... .

	// Mode d'emploi :
	// ajoute un evenement au capteur
	void add(int year, int month, int day, int hour, int minute, int wDay, char trafic);
    // les donés sont sencés : 0 <= minute <60 ect... .


	// Mode d'emploi :
	// trouve un Capteur dans un arbre de capteurs dont la rasinne est donné en paramétre
	// rand NULL si il néxiste pas.
	static Sensor* find(long idSensor,Sensor*  rootSensorTree);
	// Contract
	//l'arbre est trié ce qui est assurér par le constructeur de Capteur (Sensor)


	//-------------------------------------------- Constructeurs - destructeur
	// Mode d'emploi :
	// Crée un capteur (Sensor) et l'ajoute dans l'arbre (tel que l'arbre soit encore trié).
	Sensor (long idSensor, Sensor*&  rootSensorTree);

	// Mode d'emploi :(constructeur de copie)
	// copie un capteur et tout ce qui le suive dans l'arbre dont il est extrais.
	Sensor ( const Sensor & aSensor );

	Sensor ();
	// Mode d'emploi :
	// détruit un capteur et tout ce qui le suive dans l'arbre dont il est extrais.
	virtual ~Sensor ();
	//------------------------------------------------------------------ PRIVE
private:
	long id;
	Sensor * previus;
	Sensor * nextR;
	Sensor * nextL;
	int eventMatrix [60][24][7][4];
};

#endif /* SRC_SENSOR_H_ */
