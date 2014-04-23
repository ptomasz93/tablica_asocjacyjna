/*
 * main.cpp
 *
 *  Created on: 05-04-2014
 *      Author: tomek
 */
#include "stoper.hh"
#include "drzewo.hh"
#include <iostream>
#include <fstream>



//int main()
//{
//	element* nowy;
//	element *pomocniczy;
//	drzewo tab;
//	string szukany;
//	for(int i=0;i<4;i++)
//	{
//		nowy=new element;
//		cin>>*nowy;
//		tab.dodaj(nowy);
//	}
//	cout<<"usun";
//	cin>>szukany;
//	tab.usun(szukany);
//	cout<<"znajdz";
//	cin>>szukany;
//	pomocniczy=tab.znajdz(szukany,tab.wierzcholek);
//	cout<<*pomocniczy;
//}

int  main()
{
	element* nowy;
	fstream wynik;
	czas zegar;
	int problem=5000000;
	wynik.open("wynik_drzewo.txt",ios::out);
	double czas;
	srand( time( NULL ) );
	string klucz;
	drzewo tab;
	for(int i=0;i<30;i++)
	{
		for(int a=0;a<500000;a++)
			{
			nowy=new element;
			cin>>*nowy;
			if(a=0.5*5000000)
			klucz=nowy->klucz;
			tab.dodaj(nowy);
			}
		zegar.start();
		for(int b=0;b<1000000;b++)	tab.znajdz(klucz,tab.wierzcholek);
		zegar.stop();
		zegar.wynik();
		zegar.zapisz(wynik,problem);
		problem+=5000000;
	}
	wynik.close();

}
