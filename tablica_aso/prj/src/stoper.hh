/*
 * stoper.hh
 *
 *  Created on: 15-03-2014
 *      Author: root
 */

#ifndef STOPER_HH_
#define STOPER_HH_

#define CLOCKS_PER_SEC 1000000

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * \class
 * \brief klasa zawiera zmienne oraz funkcje potrzebne do obliczenia czasu dzialania algorytmu
 */
class czas
{
private:

	double time;
	clock_t poczatek, koniec;
public:
	/**
	 * \brief start pomiaru
	 * zapisuje stan zegara
	 */
	void start()
	{
		poczatek=clock();
	}
	/**
	 * \brief koniec pomiaru
	 * zapisuje stan zegara
	 */
	void stop()
	{
		koniec=clock();
	}
	/**
	 * \brief zwraca wynik pomiaru
	 * @return zwraca czas dzialania
	 */
	double wynik()
	{
		time=(double)(koniec-poczatek)/(double)CLOCKS_PER_SEC;
		return time;
	}
	/**
	 * \brief zapisuje wynik do pliku
	 * @param wynik pomiaru
	 * @param rozmiar rozmiar problemu
	 */
	void zapisz(fstream &wynik, int rozmiar)
	{
		cout<<rozmiar<<"  "<<time<<"\n";
		wynik<<rozmiar<<"  "<<time<<"\n";
	}

};


#endif /* STOPER_HH_ */
