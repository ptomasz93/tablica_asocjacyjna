/*
 * tablica.cpp
 *
 *  Created on: 20-04-2014
 *      Author: tomek
 */

#include "tablica.hh"
using namespace std;




ostream & operator << (ostream & wyjscie, tablica & tab)
	{
		int i=0;
		element pomocniczy;
		wyjscie<<"rozmiar tablicy :"<<tab.rozmiar<<endl;
		wyjscie<<"ilosc elementow :"<<tab.ilosc<<endl;
		for(i=0 ; i<tab.rozmiar ; i++)
		{
			pomocniczy=tab.poczatek[i];
			if(pomocniczy.klucz.size()!=0)
			{
			wyjscie<<pomocniczy;
			while(pomocniczy.nastepny!=NULL)
			{
				pomocniczy=*pomocniczy.nastepny;
				wyjscie<<pomocniczy;
			}
			}
		}
	}
/**
 * \brief funkcja dodaje przekazany element do tablicy
 * @param nowy element ktory ma zostać dodany
 */
void tablica::dodaj(element  nowy)
{
	haszuj(nowy);
	if(poczatek[nowy.indeks].zajety==NULL)
	{
		poczatek[nowy.indeks]=nowy;
		poczatek[nowy.indeks].zajety=true;
	}
	else if(poczatek[nowy.indeks].zajety==true)
	{
		element *nastepny=new element;
		*nastepny=nowy;
		element* pomocniczy=&poczatek[nowy.indeks];
		while(pomocniczy->zajety==true)
		{
			if(pomocniczy->klucz==nowy.klucz)
			{
				pomocniczy->wartosc=nowy.wartosc;
				return;
			}
			if(pomocniczy->nastepny!=NULL)
				{
				pomocniczy=pomocniczy->nastepny;
				}
			else break;
		}

		pomocniczy->nastepny=nastepny;
		nastepny->zajety=true;
	}
	ilosc+=1;
}

/**
 * \brief funkcja przetwarza klucz elementu na nr indeksu w tablicy
 * \details funkcja wymnaza kod ASCII znaku razy pozycje na ktorj znak sie znajduje
 * w stringu
 * @param nowy element ktorego klucz ma zostac przetworzony;
 */
void tablica::haszuj(element &nowy)
{
	int dlug=nowy.klucz.size();
	for(int i=0;i<dlug;i++)
	{
		nowy.indeks=(int)nowy.klucz[i]*(i+1)%(rozmiar);
	}
}
/**
 * \brief funkcja przetwarza klucz elementu na nr indeksu w tablicy
 * \details funkcja wymnaza kod ASCII znaku razy pozycje na ktorj znak sie znajduje
 * w stringu
 * @param klucz ktory ma zostac przetworzony;
 */
int tablica::haszuj(string klucz)
	{
		int indeks;
		int dlug=klucz.size();
		for(int i=0;i<dlug;i++)
		{
			indeks=(int)klucz[i]*(i+1)%(rozmiar);
		}
	return indeks;
	}

/**
 * \brief funkcja znajduje element o zadanym kluczu
 * @param klucz do ktorego pasujacy element ma byc znaleziony
 * @return zwraca wskaznik na szukany element
 */
element * tablica::znajdz(string klucz)
{
	element *pomocniczy;
	int indeks;
	indeks=haszuj(klucz);
	pomocniczy=&poczatek[indeks];
	if(pomocniczy->zajety==true)
	{
	if(pomocniczy->klucz==klucz)return pomocniczy;
	while(pomocniczy->nastepny!=NULL)
	{
		pomocniczy=pomocniczy->nastepny;
		if(pomocniczy->klucz==klucz)return pomocniczy;
	}
	}
}

/**
 * \brief funkcja usuwa element o podanym kluczu
 * @param klucz elementu ktory ma zostac usuniety;
 */
void tablica::usun_element(string klucz)
{
	element *nastepny;
	element * pomocniczy=znajdz(klucz);
	if(pomocniczy->nastepny==NULL)pomocniczy->czysc();
	else
	{

	nastepny=pomocniczy->nastepny;
	*pomocniczy=*pomocniczy->nastepny;
	delete nastepny;
	}
	ilosc-=1;

}
