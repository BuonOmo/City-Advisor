/*
 * Event.h
 *
 *  Created on: 20 oct. 2015
 *      Author: ulysse
 */

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

class Event
{
public:
	Event * getNext() const;

	bool hasNext() const;

	bool is(char trafic = 'A', int wDay = -1, int hour = -1, int minute = -1);

	Event (int aYear, int aMonth, int aDay, int anHour, int aMinute, int aWDay, char aTrafic, Event * root);
	Event();
	virtual ~Event ();

private:
	Event * next;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int wDay;
	char trafic;
};

#endif /* SRC_EVENT_H_ */
