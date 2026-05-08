#include <iostream>
#include "Studi.h"
using namespace std;

long Studi::get_matnr() const{
	return matnr;
}
string Studi::get_vorname() const{
	return vorname;
}

string Studi::get_nachname() const{
	return nachname;
}

void Studi::set_matnr(long matnr){
	this->matnr = matnr;
}

void Studi::set_vorname(string vorname){
	this->vorname = vorname;
}

void Studi::set_nachname(string nachname){
	this->nachname = nachname;
}

void Studi::out(){
	cout << matnr << " " << vorname << " " << nachname << endl;
}
