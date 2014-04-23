/*
 * struktura.hh
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef STRUKTURA_HH_
#define STRUKTURA_HH_

#include <string>
#include "generator.hh"
using namespace std;
/**
 * \brief clasa służy do przechowywania zestawu danych tworzacych jeden element w tablicy
 * \details zawiera również przeładowania operatorów, potrzebne do pracy elementem.
 */
template <typename Twartosci>
class element
{
	public:
	string klucz;
	Twartosci wartosc;

friend ostream & operator <<  (ostream &wyjscie,  element<Twartosci> &dana)
{
	string a="klucz :";
	string b="wartosc :";
	wyjscie<<a<<dana.klucz<<"\n";
	wyjscie<<b<<dana.wartosc<<"\n";
	return wyjscie;
}

friend istream & operator >> (istream &wejscie,  element<Twartosci> &dana)
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

};
//============================Przeładowania operatorów===========================

template<typename Twartosci>
bool operator <(element<Twartosci> & a, element<Twartosci> & b)
{
	if(a.klucz<b.klucz)return true;
	return false;
}

template<typename Twartosci>
bool operator <(string & a, element<Twartosci> & b)
{
	if(a<b.klucz)return true;
	return false;
}

template<typename Twartosci>
bool operator >(string & a, element<Twartosci> & b)
{
	if(a>b.klucz)return true;
	return false;
}

template<typename Twartosci>
bool operator ==(string & a, element<Twartosci> & b)
{
	if(a==b.klucz)return true;
	return false;
}

template<typename Twartosci>
bool operator >(element<Twartosci> & a, element<Twartosci> & b)
{
	if(a.klucz>b.klucz)return true;
	return false;
}

#endif /* STRUKTURA_HH_ */
