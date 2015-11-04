//============================================================================
// Name        : TP2.cpp
// Author      : Ulysse, Adrien
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>

#include "City.h"

using namespace std;

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
    	  id = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  yyyy = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  mm = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  dd = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  h = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');
    	  m = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str, ' ');

    	  d7 = atoi(str.c_str());
    	  cout << str << endl;

    	  getline(cin, str);
    	  trafic = str[0];
    	  cout << str << endl;

    	  LA.addEvent(id, yyyy, mm, dd, h, m, d7, trafic);
    	  cout << "ça passe" << endl;
    	  LA.statSensor(id);

      } else if (str.compare("JAM_DH")==0) {

      } else if (str.compare("STATS_D7")==0) {

      } else if (str.compare("STATS_C")==0) {

      }
      getline(cin,str);
   }


   return 0;
}
