#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

//int sum(size_t start, size_t ende, vector<int> file);

int main() {
	vector<int> file = read_ints("maxsub.dat");

	int maxsub = file[0];

	for (size_t start = 0; start < file.size(); ++start) {
		int aktuelle_summe = 0;
		for (size_t ende = start; ende < file.size(); ++ende) {
			aktuelle_summe += file[ende];
			if (aktuelle_summe > maxsub) {
				maxsub = aktuelle_summe;
			}
		}
	}

	cout << "Das maximale maxsub ist " << maxsub << endl;
}

//int sum(size_t start, size_t ende, vector<int> file) {
//	int sum = 0;
//
//	for (size_t i = start; i < ende; ++i) {
//		sum += file[i];
//	}
//
//	return sum;
//}
