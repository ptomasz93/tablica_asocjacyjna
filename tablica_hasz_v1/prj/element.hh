/*
 * element.hh
 *
 *  Created on: 20-04-2014
 *      Author: tomek
 */

#ifndef ELEMENT_HH_
#define ELEMENT_HH_

#include <string>
#include <iostream>

#include "generator.hh"

using namespace std;
/**
 * \class klasa modeluje pojedynczy element tablicy haszujacej
 * \details przechowuje dane o kluczu wartosci oraz indeksie elementu
 */
class element
{
private:
	string wartosc;

public:
	string klucz;
	element *nastepny;
	element *poprzedni;
	int indeks;
	bool zajety;
	element()
	:zajety(NULL), nastepny(NULL)
	{
	}

	void czysc();
	friend class tablica;
	friend ostream & operator <<(ostream & wejsciowe, element & wysylany);
	friend istream & operator >>(istream &wyjscie, element &wpisywany);
};

#endif /* ELEMENT_HH_ */
