/*
 * tablica.hh
 *
 *  Created on: 20-04-2014
 *      Author: tomek
 */

#ifndef TABLICA_HH_
#define TABLICA_HH_

#include "element.hh"
#include <iostream>

class tablica
{
private:
	element * poczatek;
	int rozmiar;
	int ilosc;
public:
	tablica(int il)
	:ilosc(0)
	{
		poczatek=new element[il];
		rozmiar=il;
	}

	friend class element;
	friend ostream & operator << (ostream & wejscie, tablica & tab);
	void dodaj(element  nowy);
	element* znajdz(string klucz);
	int haszuj(string klucz);
	void haszuj(element & nowy);
	void usun_element(string klucz);
};



#endif /* TABLICA_HH_ */
