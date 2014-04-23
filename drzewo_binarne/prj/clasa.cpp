/*
 * struktura.cpp
 *
 *  Created on: 10-04-2014
 *      Author: tomek
 */


#include "clasa.hh"
///konstruktor klasy, zeruje wszystkie adresy klasy
element::element()
:wyzej(NULL),lewy(NULL),prawy(NULL)
{
}

//============================Przeładowania operatorów===========================


bool operator <(string & a, element  & b)
{
	if(a<b.klucz)return true;
	return false;
}


bool operator >(string & a, element  & b)
{
	if(a>b.klucz)return true;
	return false;
}


bool operator ==(string & a, element & b)
{
	if(a==b.klucz)return true;
	return false;
}


bool operator >(element & a, element & b)
{
	if(a.klucz>b.klucz)return true;
	return false;
}

bool operator <(element & a, element  & b)
{
	if(a.klucz<b.klucz)return true;
	return false;
}

bool operator ==(element & a, element & b)
{
	if(a.klucz==b.klucz)return true;
	return false;
}
