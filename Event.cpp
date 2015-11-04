/*
 * Event.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#include "Event.h"

Event * Event::getNext() const
{
	return next;
}

bool Event::hasNext() const
{
	return !(next == NULL);
}

bool Event::is(char aTrafic, int aWDay, int anHour, int aMinute)
{
	if ((aTrafic == 'A'|| aTrafic == trafic) &&
				(aWDay == -1 || aWDay == wDay) &&
				(anHour == -1 || anHour == hour) &&
				(aMinute == -1 || aMinute == minute))
	{
		return true;
	}
	return false;
}
Event::Event (int aYear, int aMonth, int aDay, int anHour, int aMinute, int aWDay, char aTrafic, Event * root) :
	year(aYear), month(aMonth), day(aDay), hour(anHour), minute(aMinute), wDay(aWDay), trafic(aTrafic)
{
	next = root -> next;
	root -> next = this;
}

Event::Event () :
		year(0), month(0), day(0), hour(0), minute(0), wDay(0), trafic('V')
{
	next = NULL;
}

Event::~Event ()
{
	// TODO Auto-generated destructor stub
}

