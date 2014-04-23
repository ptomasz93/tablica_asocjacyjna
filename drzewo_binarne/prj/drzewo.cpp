/*
 * drzewo.cpp
 *
 *  Created on: 10-04-2014
 *      Author: tomek
 */
#include "drzewo.hh"

drzewo::drzewo()
:wierzcholek(NULL)
{
}

/**
 * \brief funkcja znajduje element w drzewie po ktorym nalezy wstawic element nowy.
 * \details funkcja dziala rekurenycjnie
 * @param nowy element dla ktorego szukamy miejsca w drzewie
 * @param wyzej przy pierwzym wywolaniu nalezy wskazac wierzcholek drzewa.
 * @return zwraca wskaznik na element po ktorym nalezy wstawic nowy element
 */
element* drzewo::znajdz_pozycje(element* nowy, element *wyzej)
{
	element *szukany;
	if(nowy->klucz<wyzej->klucz&&wyzej->lewy==NULL)return wyzej;
	if(nowy->klucz<wyzej->klucz&&wyzej->lewy!=NULL)szukany=znajdz_pozycje(nowy,wyzej->lewy);
	if(nowy->klucz>wyzej->klucz&&wyzej->prawy==NULL)return wyzej;
	if(nowy->klucz>wyzej->klucz&&wyzej->prawy!=NULL)szukany=znajdz_pozycje(nowy,wyzej->prawy);
	if(*nowy==*wyzej)szukany=wyzej;

	return szukany;
}

/**
 * \brief funkcja wstawia w strukture drzewa nowy element
 * @param nowy element ktory nalezy wstawic
 */
void drzewo::dodaj(element * nowy)
{
	element* wyzej;
	if(wierzcholek==NULL)
	{
		wierzcholek=nowy;
		return;
	}
	wyzej=znajdz_pozycje(nowy, wierzcholek);
	if(*nowy==*wyzej)
	{
		wyzej->wartosc=nowy->wartosc;
	}
	if(*nowy<*wyzej)
	{
		wyzej->lewy=nowy;
		nowy->wyzej=wyzej;
	}
	if(*nowy>*wyzej)
	{
		wyzej->prawy=nowy;
		nowy->wyzej=wyzej;
	}
}

/**
 * \brief funkcja znajduje w drzewie element o podanym kluczu
 * @param klucz klucz szukanego elementu
 * @param wyzej nalezy podac wierzcholek przeszukiwanego drzewa
 * @return zwraca wskanzik na szukany element
 */

element* drzewo::znajdz(string klucz, element* wyzej)
{
	element * szukany;
	if(klucz==*wyzej)return wyzej;
	if(klucz<*wyzej)szukany=znajdz(klucz, wyzej->lewy);
	if(klucz>*wyzej)szukany=znajdz(klucz, wyzej->prawy);
	return szukany;
}
/**
 * \brieffunkcja znajduje nastepnik podanego elementu
 * @param tego element ktorego nastepnik trzeba znalesc
 * @return zwraca adres nastepnika zadenaego elemntu
 */
element * drzewo::znajdz_nastepnik(element * tego)
{
	element * pomocniczy=NULL;
	pomocniczy=tego->prawy;
	while(pomocniczy->lewy!=NULL)
	pomocniczy=pomocniczy->lewy;
	return pomocniczy;
}

/**
 * \brief usuwa element o zadanym kluczu
 * @param klucz klucz elementu ktory nalezy usunac;
 */
void drzewo::usun(string klucz)
{
	element * usuwany ;
	usuwany=znajdz(klucz, wierzcholek);
	if(usuwany->lewy==NULL&&usuwany->prawy==NULL)
	{
		if(*usuwany<*usuwany->wyzej)usuwany->wyzej->lewy=NULL;
		if(*usuwany>*usuwany->wyzej)usuwany->wyzej->prawy=NULL;
		delete usuwany;
	}
	else if(usuwany->lewy!=NULL&&usuwany->prawy==NULL)
	{
			if(*usuwany<*usuwany->wyzej)usuwany->wyzej->lewy=usuwany->lewy;
			if(*usuwany>*usuwany->wyzej)usuwany->wyzej->prawy=usuwany->lewy;
			delete usuwany;
		}
	else if(usuwany->lewy==NULL && usuwany->prawy!=NULL)
		{
				if(*usuwany<*usuwany->wyzej)usuwany->wyzej->lewy=usuwany->prawy;
				if(*usuwany>*usuwany->wyzej)usuwany->wyzej->prawy=usuwany->prawy;
				delete usuwany;
			}
	else if(usuwany->lewy!=NULL&&usuwany->prawy!=NULL)
		{
		element nastepnik;
		nastepnik=*znajdz_nastepnik(usuwany);
		usun(nastepnik.klucz);
		usuwany->klucz=nastepnik.klucz;
		usuwany->wartosc=nastepnik.wartosc;

			}
}

