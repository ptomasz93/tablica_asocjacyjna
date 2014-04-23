/*
 * generator.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
using namespace std;

#include "generator.hh"

/**
 * \brief generuje plik *.txt o zadanej ilosci danych i nazwie
 * \details W pliku umieszczane sa liczby naturalne od 1 wzwyrz
 * w pierwszym wierszu umieszczana jest liczba mowiaca o ilosci wierszy danych.
 * @param nazwa - utworzonego pliku
 * @param rozmiar - ilosc wierszy sanych
 */

string generuj()
{
	string nowy;
	int il;
	il=rand()%10+1;

	int los;
	for(int i=0; i<il; i++)
	{
		los=(rand()%(122-97))+97;
		nowy.push_back((char)los);
	}
	return nowy;
}


