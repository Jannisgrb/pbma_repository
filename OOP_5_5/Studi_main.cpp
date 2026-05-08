#include <iostream>
#include <vector>
#include "Studi.h"
#include "pbma.h"
using namespace std;

int main(int argc, const char *argv[]) {
	vector<string> file;

	file = read_words("studis.txt");

	vector<Studi> Studierende;
	for (size_t i = 0; i + 2 < file.size(); i += 3) {
		Studi s;

		s.set_matnr(stol(file[i]));
		s.set_vorname((string) file[i + 1]);
		s.set_nachname((string) file[i + 2]);

		Studierende.push_back(s);
	}

	for (size_t i = 0; i < Studierende.size(); ++i) {
		Studierende[i].out();
	}
}
