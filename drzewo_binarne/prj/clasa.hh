/*
 * struktura.hh
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef CLASA_HH_
#define CLASA_HH_

#include <string>
#include <iostream>
#include "generator.hh"
using namespace std;
/**
 * \brief clasa służy do przechowywania zestawu danych tworzacych jeden element w drzewie
 * \details zawiera również przeładowania operatorów, potrzebne do pracy z elementem.
 */

class element
{
public:
	element *wyzej;
	element* lewy;
	element* prawy;

	string wartosc;

	string klucz;
	/**
	 * \brief przeladowanie operatora wyjscia
	 * \details pozwala na wypisywanie danych z elementu do strumienia wyjscia
	 * @param wyjscie strumien wyjscia
	 * @param dana elemnt ktory mazostac wysany
	 * @return
	 */
friend ostream & operator <<  (ostream &wyjscie,  element  &dana)
{
	string a="klucz :";
	string b="wartosc :";
	string klucz=dana.klucz;
	string wartosc=dana.wartosc;
	wyjscie<<a<<klucz<<endl;
	wyjscie<<b<<wartosc<<endl;
	return wyjscie;
}

/**
 * \brief przeladowanie operatora wejscia
 * \details obsluguje wpisywanie zmiennych do elementu
 * @param wejscie strumien wejsciowy
 * @param dana element
 * @return
 */
friend istream & operator >> (istream &wejscie,  element  &dana)
{
	string klucz=generuj();
	//cout<<"podaj klucz\n";
	//wejscie>>dana.klucz;
	dana.klucz=klucz;
//	cout<<"podaj wartosc\n";
//	wejscie>>dana.wartosc;
	dana.wartosc=klucz;
	return wejscie;
}
element();


};

/**
 * Przeladowania operatorow;
 */
bool operator <(element & a, element  & b);

bool operator <(string & a, element  & b);

bool operator >(string & a, element  & b);

bool operator ==(string & a, element & b);

bool operator ==(element & a, element & b);

bool operator >(element & a, element & b);
#endif /* CLASA_HH_ */
