/*
 * main.cpp
 *
 *  Created on: 05-04-2014
 *      Author: tomek
 */
#include "clasa.hh"
#include <iostream>
#include <fstream>
#include "stoper.hh"

using namespace std;

//int main()
//{
//	tablica<string> tab1;
//	element<string> pomocniczy;
//for(int i=0;i<3;i++)
//	{
//	cin >>pomocniczy;
//	tab1.dodaj(pomocniczy);
//	}
//	string szukany;
//	cout<<"Podaj klucz elementu do wyświetlenia:\n";
//	cin>>szukany;
//	tab1.wyswietl(szukany);
//	cout<<"Podaj klucz elementu do usunięcia:\n";
//	cin>>szukany;
//	tab1.usun(szukany);
//	cout<<tab1;
//	cout<<"Zmiana wartosci elementu\n";
//	cin>>pomocniczy;
//	tab1.dodaj(pomocniczy);
//	cout<<tab1;
//
//}
int  main()
{
	tablica<string> tab1;
	element<string> pomocniczy;
	fstream wynik;
	czas zegar;
	int problem=5000000;
	wynik.open("wynik_wyszuk_binarne.txt",ios::out);
	double czas;
	srand( time( NULL ) );
	string klucz;
	for(int i=0;i<30;i++)
	{
		for(int a=0;a<500000;a++)
			{
			cin>>pomocniczy;
			if(a=0.5*5000000)
			klucz=pomocniczy.klucz;
			tab1.dodaj(pomocniczy);
			}
		zegar.start();
		for(int b=0;b<1000000;b++)	tab1.wyswietl(klucz);
		zegar.stop();
		zegar.wynik();
		zegar.zapisz(wynik,problem);
		problem+=5000000;
	}
	wynik.close();

}


