#include <iostream>
#include "pbma.h"
using namespace std;

struct Person {
	const char* vorname; // 8 Byte
	const char* nachname; // 8 Byte
	unsigned int alter; // 4 Byte
	int punkte[10];	// 10 * 4 Byte
};

void person_out(Person p){
	for(int i = 0; i < 17; i++){
		cout << p.vorname << p.nachname << p.alter << ": " << p.punkte << endl;
	}
}

int person_in(Person b){

}


int main(){
	vector<int> zahlen = create_same_randints(170, 0, 20);
	vector<Person> personen;
	for(unsigned int i = 0; i < 17; i++){
		personen[i] = Person{"Susi", "Sinnlos", i+18};
		for(int j = 0; j < 10; j++){
			personen[i].punkte[j] = zahlen[j];
		}
	}

	for (size_t i = 0; i < 17; i++){
		person_out(personen[i]);
	}


}
