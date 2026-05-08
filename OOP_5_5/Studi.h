/*
 * Studi.h
 *
 *  Created on: 06.05.2026
 *      Author: n3030503
 */


#ifndef STUDI_H_
#define STUDI_H_
using namespace std;
class Studi {
public:
	long get_matnr() const;
	string get_vorname() const;
	string get_nachname() const;

	void set_matnr(long matnr);
	void set_vorname(string vorname);
	void set_nachname(string nachname);

	void out();
private:
	long matnr;
	string vorname;
	string nachname;
};

#endif /* STUDI_H_ */
