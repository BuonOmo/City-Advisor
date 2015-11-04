/*
 * Sensor.h
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "Event.h"

using namespace std;

class Sensor
{
public:
	int count(char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1);
	// compte les elements précisé d’un capteur, les valeurs par défaut indiquent
	// que la valeur n’importe pas.

	void add(int year, int month, int day, int hour, int minute, int wDay, char trafic);
	// ajoute un evenement au capteur

	Sensor * getNext() const;

	bool hasNext() const;

	long getId() const;

	Sensor (long anId, Sensor * aSensor);

	Sensor ();
	virtual ~Sensor ();
private:
	long id;
	Sensor * next;
	int size; //nombre d’evenements
	Event * root;
};

#endif /* SRC_SENSOR_H_ */
