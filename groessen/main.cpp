#include <iostream>
#include "pbma.h"
#include <vector>
using namespace std;

struct Person {
	const char* vorname; // 8 Byte
	const char* nachname; // 8 Byte
	unsigned int alter; // 4 Byte
	int punkte[10];	// 10 * 4 Byte
};

void person_out(Person p){
		cout << p.vorname << " " << p.nachname << " " << p.alter << ": ";
		for(int i = 0; i < 10; i++){
			cout << p.punkte[i] << " ";
		}
		cout << endl;;
}

Person person_in(int age, vector<int> *zahlen, int startindex){
	Person p;
	p.vorname = "Susi";
	p.nachname = "Sinnlos";
	p.alter = age;
	for(int i = 0; i<10; i++){
		p.punkte[i] = zahlen->at(startindex * 10 + i);
	}

	return p;
}

int p_sum(Person p){
	int sum = 0;
	for(int i = 0; i < 10; i++){
		sum = sum + p.punkte[i];
	}
	return sum;
}

int beste_susi(vector<Person> *p){
	int best_age = p->at(1).alter;
	int best_score = 0;

	for(int i = 0; i < 17; i++){
		if(p_sum(p->at(i)) > best_score){
			best_score = p_sum(p->at(i));
			best_age = p->at(i).alter;
		}
	}
	return best_age;
}


int main(){
	vector<int> zahlen = create_same_randints(170, 0, 20);
	vector<Person> personen;

	for(int i = 0; i < 17; i++){
		personen.push_back(person_in(i+18, &zahlen, i));
	}

	for (size_t i = 0; i < 17; i++){
		person_out(personen[i]);
	}

	cout << "Die beste Susi hat das Alter: " << beste_susi(&personen) << endl;


}
