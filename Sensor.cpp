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
	new Event(year, month, day, hour, minute, wDay, trafic, root);
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

Sensor::~Sensor ()
{
		//TODO reflechir à un destructeur
	delete this;
}

