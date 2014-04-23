/*
 * drzewo.hh
 *
 *  Created on: 10-04-2014
 *      Author: tomek
 */

#ifndef DRZEWO_HH_
#define DRZEWO_HH_
/**
 * \brief clasa sluzy do obslugi struktury drzewa wyszukiwan binarnych
 */
#include "clasa.hh"
class drzewo
{
public:
	element *wierzcholek;
	element* znajdz_nastepnik(element * tego);
	element* znajdz_pozycje(element * nowy, element *wyzej);
	void dodaj(element * nowy);
	element *znajdz(string klucz, element* wierzcholek);
	drzewo();
	void usun(string klucz);

};


#endif /* DRZEWO_HH_ */
