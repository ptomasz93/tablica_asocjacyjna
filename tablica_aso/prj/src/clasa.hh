/*
 * clasa.hh
 *
 *  Created on: 10-03-2014
 *      Author: root
 */

#ifndef CLASA_HH_
#define CLASA_HH_
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

#include "struktura.hh"

using namespace std;
//#define TYP string
/**
 * \brief definicja kalsy obsługującej tablicę asocjacyjna
 * \details klasa zawiera wektor sluzacy do przechowywania danych
 * oraz funkcje niezbedne do ich obslugi
 */
template<class Twartosci>
class tablica
{
private:
	 ///zmienna pomocnicza wykorzystywana w funkcji znajdz
	int pozycja;

public:
	/// wektor przechwoywujacy klucz oraz wartosc
	vector <element <Twartosci> > tab;

	/**
	 * \brief przeładowanie strumeinia wyjscia
	 * @param wyjscie
	 * @param wektor
	 * @return
	 */
	friend ostream & operator << (ostream& wyjscie, tablica<Twartosci>& wektor)
	{
		element<Twartosci> pomocniczy;
		for(int i=0; i<wektor.tab.size(); i++)
		{
			cout<<wektor.tab[i];
		}
		return wyjscie;
	}
/**
 * \brief funkcja dodaje element do tablicy,
 * lub zmienia wartosc juz istniejacego elementu
 * @param pomocniczy element ktory ma zostac dodany
 */
		void dodaj(element<Twartosci> pomocniczy)
	{
		if(tab.size()&&znajdz(pozycja,pomocniczy.klucz,0,tab.size()-1))
			tab[pozycja]=pomocniczy;
		else
	//		tab.insert((tab.begin()+wyznacz_poz(pomocniczy)),pomocniczy);
			tab.push_back(pomocniczy);
		quick(0,tab.size()-1);
	}



	/**
	 * \brief funkcja zamienia elementy o podanym indexie
	 * \details elementy indexowane sa od 0,
	 * @param a element pierwszy
	 * @param b element drugi
	 * @return zwraca false jesli index jest zbyt duzy
	 */
	bool  Zamien_elementy(int a,int b)
	{
		if(a==b)return true;
		if(a>tab.size()||b>tab.size())return false;
		element<Twartosci> zmienna_a, zmienna_b;
		zmienna_a=tab[a];
		zmienna_b=tab[b];
		tab[a]=zmienna_b;
		tab[b]=zmienna_a;
		return true;
	}
/**
 * \brief algorytm sortowania szybkiego;
 * @param lewy poczatek zbioru
 * @param prawy koniec zbioru
 */
	void  quick(int lewy, int prawy)
	{
	  int i,j;
	  element<Twartosci> srodek;
	  i = (lewy + prawy) / 2;
	  srodek = tab[i];
	  Zamien_elementy(prawy, i);
	  for(j = i = lewy; i < prawy; i++)
	  {
		  if(tab[i] < srodek)
		  {
			Zamien_elementy(i,j);
			j++;
		  }
	  }
	 Zamien_elementy(j,prawy);
	   if(lewy < j - 1)  quick(lewy, j-1 );
	  if(j + 1 < prawy) quick( j + 1, prawy);
	}

	/**
	 * \brief funkcja wyszukuje binarnie zadanego elementu;
	 * \details wykorzystujemy fakt ze vektor jest posortowany.
	 * @param klucz poszukiwany element
	 * @return
	 */

	bool  znajdz(int & piwot, string szukany,int lewy, int prawy)
	{
		if(szukany==tab[0])
		{
			pozycja=0;
			return true;
		}
		if(szukany==tab[tab.size()-1])
		{
			pozycja=tab.size()-1;
			return true;
		}
		piwot=(prawy+lewy)/2;
		if(szukany==tab[piwot])return true;
		if(piwot==lewy||piwot==prawy)return false;
		if(szukany>tab[piwot])znajdz(piwot,szukany,piwot,prawy);
		if(szukany<tab[piwot])znajdz(piwot,szukany,lewy,piwot);
		return false;
	}
/**
 * \brief funkcja usuwa element o zadanym kluczu
 * @param klucz klucz elementu któwy ma zostać usunięty
 * @return
 */
	bool  usun(string klucz)
	{
		if(znajdz(pozycja,klucz,0,tab.size()))
		{
			tab.erase(tab.begin()+pozycja);
			return true;
		}
		return false;
	}

	/**
	 * \brief funkcja wyswietla element o zadanym kluczu
	 * @param klucz -elementu który ma zostać wyświetlony
	 */
	void wyswietl(string klucz)
	{
		znajdz(pozycja,klucz,0,tab.size()-1);
		//cout<<tab[pozycja];
		//else cout<<"nie ma takiego elementu";
	}

};


#endif /* CLASA_HH_ */
