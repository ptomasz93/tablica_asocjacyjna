/*
 * main.cpp
 *
 *  Created on: 20-04-2014
 *      Author: tomek
 */

#include "element.hh"
#include <fstream>
#include "tablica.hh"
#include "stoper.hh"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


int  main()
{
	fstream wynik;
	czas zegar;
	int problem=5000000;
	wynik.open("wynik_haszujace.txt",ios::out);
	double czas;
	srand( time( NULL ) );
	element testowy;
	string klucz;
	tablica tab(100000000);
	for(int i=0;i<30;i++)
	{
		for(int a=0;a<500000;a++)
			{
			cin>>testowy;
			if(a=0.5*5000000)
			klucz=testowy.klucz;
			tab.dodaj(testowy);

			}
		zegar.start();
		for(int b=0;b<1000000;b++)	tab.znajdz(klucz);
		zegar.stop();
		zegar.wynik();
		zegar.zapisz(wynik,problem);
		problem+=5000000;
	}
	wynik.close();

}
