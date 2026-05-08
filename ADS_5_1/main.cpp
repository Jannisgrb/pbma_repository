#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

int sum(size_t start, size_t ende, vector<int> file);

int main() {
	vector<int> file = read_ints("maxsub.dat");

	int maxsub = file[0];

	for (size_t start = 0; start < file.size(); ++start) {
		for (size_t ende = 0; ende < file.size(); ++ende) {
			if(sum(start, ende, file) > maxsub){
				maxsub = sum(start, ende, file);
			}
		}
	}

	cout << "Das maximale maxsub ist " <<  maxsub << endl;
}

int sum(size_t start, size_t ende, vector<int> file) {
	int sum = 0;

	for (size_t i = start; i < ende; ++i) {
		sum += file[i];
	}

	return sum;
}

// for schleife für start, darin for schleife für ende, in der endschleife funktion für summe aufrufen und vergleichen was größte ist
