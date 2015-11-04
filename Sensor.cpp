/*
 * Sensor.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#include "Sensor.h"

int Sensor::count(char trafic, int wDay, int hour, int minute)
{
	int count(0);
	if (!(root -> hasNext()))
	{
		return -1;
	}
	Event * cur = root -> getNext();

	while (cur -> hasNext())
	{
		if (cur -> is(trafic, wDay, hour, minute))
		{
			count++;
		}
		cur = cur -> getNext();
	}

	return count;
}

void Sensor::add(int year, int month, int day, int hour, int minute, int wDay, char trafic)
{
	cout << "ça passe1" << endl;
	new Event(year, month, day, hour, minute, wDay, trafic, root);
	cout << "ça passe8" << endl;
	size++;
}

Sensor * Sensor::getNext() const
{
	return next;
}

long Sensor::getId() const
{
	return id;
}

bool Sensor::hasNext() const
{
	return !(next == NULL);
}

Sensor::Sensor (long anId, Sensor * aSensor) :
		id(anId), size(0), root(NULL)
{
	next = aSensor -> next;
	aSensor -> next = this;
}

Sensor::Sensor() :
		id(0), size(0), root(new Event())
{
	next = NULL;
}

Sensor::~Sensor ()
{
		//TODO reflechir à un destructeur
	delete this;
}

