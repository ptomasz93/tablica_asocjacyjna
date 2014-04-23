/*
 * element.cpp
 *
 *  Created on: 20-04-2014
 *      Author: tomek
 */

#include "element.hh"



using namespace std;

ostream & operator <<(ostream & wyjsciowe, element & wysylany)
{

			wyjsciowe<<"klucz : "<<wysylany.klucz<<endl;
			wyjsciowe<<"wartosc :"<<wysylany.wartosc<<endl;
			wyjsciowe<<"indeks :"<<wysylany.indeks<<endl;
			return wyjsciowe;

}

istream & operator >>(istream &wejscie, element &wpisywany)
{
	string klucz=generuj();
	//cout<<"podaj klucz:";
	//wejscie>>wpisywany.klucz;
	wpisywany.klucz=klucz;
	//cout<<"podaj wartosc:";
	//wejscie>>wpisywany.wartosc;
	wpisywany.wartosc=klucz;
	return wejscie;
}

/**
 * \brief zeruje wartosci elementu
 */
void element::czysc()
{
	klucz.clear();
	wartosc.clear();
	zajety=false;
	nastepny==NULL;
}
