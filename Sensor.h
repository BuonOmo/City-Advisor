/*
 * Sensor.h
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

using namespace std;

class Sensor
{
public:
	int count(char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1)const;
	// compte les elements précisé d’un capteur, les valeurs par défaut indiquent
	// que la valeur n’importe pas.

	static int countInAllSensor(Sensor*  arrayRoot, char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1);

	void add(int year, int month, int day, int hour, int minute, int wDay, char trafic);
	// ajoute un evenement au capteur

	Sensor * getNext() const;

	bool hasNext() const;

	long getId() const;

	static Sensor* find(long idSensor,Sensor*  arrayRoot);

	Sensor (long anId, Sensor*&  arrayRoot);

	Sensor ();

	virtual ~Sensor ();
private:
	long id;
	Sensor * previus;
	Sensor * nextR;
	Sensor * nextL;
	int eventMatrix [61][24][7][4];
};

#endif /* SRC_SENSOR_H_ */
