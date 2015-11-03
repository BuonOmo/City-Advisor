//============================================================================
// Name        : TP2.cpp
// Author      : Ulysse, Adrien
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "City.h"

using namespace std;

int stringToInt(string s)
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}


int main(void)
{
   int id, yyyy, mm, dd, h, m, d7;
   char trafic;
   string str;

   City LA;

   /* placer ici la déclaration de votre liste ainsi que
    * son initialisation */

   getline(cin, str,' ');
   while (str.compare("bye")!=0) {
      if (str.compare("ADD")==0) {
    	  getline(cin, str, ' ');
    	  id = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  yyyy = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  mm = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  dd = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  h = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  m = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  d7 = stringToInt(str);
    	  cout << str << endl;

    	  getline(cin, str);
    	  trafic = str[0];
    	  cout << str << endl;

    	  LA.addEvent(id, yyyy, mm, dd, h, m, d7, trafic);
    	  LA.statSensor(id);

      } else if (str.compare("JAM_DH")==0) {

      } else if (str.compare("STATS_D7")==0) {

      } else if (str.compare("STATS_C")==0) {

      }
      getline(cin,str);
   }


   return 0;
}
