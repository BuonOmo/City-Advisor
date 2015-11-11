//============================================================================
// Name        : TP2.2cpp
// Author      : Ulysse, Adrien
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>

#include "City.h"
#include "Sensor.h"

using namespace std;

int main(void)
{
	int id, yyyy, mm, dd, h, m, d7;
	char trafic;
	string str, line;

	City LA;

	/* placer ici la déclaration de votre liste ainsi que
	* son initialisation */




	while (cin.peek() != 'E') {
		getline(cin, str,' ');
		if (str.compare("ADD")==0) {
			getline(cin, str, ' ');
			id = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');
			yyyy = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');
			mm = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');
			dd = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');
			h = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');
			m = atoi(str.c_str());
			//cout << "#" << str << endl;

			getline(cin, str, ' ');

			d7 = atoi(str.c_str())-1;
			//cout << "#" << str << endl;

			getline(cin, str);
			trafic = str[0];
			//cout << "#" << str << endl;

			LA.addEvent(id, yyyy, mm, dd, h, m, d7, trafic);

		} else if (str.compare("JAM_DH")==0)
		{
			getline(cin, str);
			LA.jamDay(atoi(str.c_str()));
		} else if (str.compare("STATS_D7")==0)
		{
			getline(cin, str);
			LA.statDay(atoi(str.c_str())-1);
		} else if (str.compare("STATS_C")==0)
		{
			getline(cin, str);
			LA.statSensor(atoi(str.c_str()));
		}else if (str.compare("OPT")==0)
		{
			cout << "tp2 OPT"<<endl;

			int wDay;
			int hourStart;
			int hourEnd;
			int rideLength;
			long* idSensors;

			getline(cin, str,' ');
			wDay=atoi(str.c_str())-1;

			getline(cin, str,' ');
			hourStart=atoi(str.c_str());


			getline(cin, str,' ');
			hourEnd=atoi(str.c_str());

			getline(cin, str,' ');
			rideLength=atoi(str.c_str());
			idSensors = new long[rideLength];

			for (int SensorIndex =0 ; SensorIndex<rideLength-1; SensorIndex++ )
			{
				getline(cin, str,' ');
				idSensors[SensorIndex]=atoi(str.c_str());
			}
			getline(cin, str);
			idSensors[rideLength]=atoi(str.c_str());

			LA.opt(wDay, hourStart, hourEnd,rideLength, idSensors);
			LA.opt(wDay,hourStart,hourEnd,rideLength, idSensors);
		}
		cin.clear();
		str.clear();
	}

	return 0;
}
