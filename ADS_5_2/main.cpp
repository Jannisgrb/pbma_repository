#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

int main() {
	vector<int> P = read_ints("maxsub.dat");

	int Mitte = P.size() / 2;

	vector<int> L;
	vector<int> R;

	for (int i = 0; i < Mitte; i++) {
		L.push_back(P[i]);
	}

	for (size_t i = Mitte; i < P.size(); i++) {
		R.push_back(P[i]);
	}

	int maxsub_y = R[0];
	for (size_t ende = 0; ende < R.size(); ++ende) {
		int aktuelle_Randsumme = R[0];
		aktuelle_Randsumme += R[ende];
		if (aktuelle_Randsumme > maxsub_y) {
			maxsub_y = aktuelle_Randsumme;
		}
	}

	int maxsub_x = L[L.size()];
	for (size_t ende = L.size(); ende == 0; --ende) {
		int aktuelle_Randsumme = L[L.size()];
		aktuelle_Randsumme += L[ende];
		if (aktuelle_Randsumme > maxsub_x) {
			maxsub_x = aktuelle_Randsumme;
		}
	}

	int maxsub_a = L[0];
	for (size_t start = 0; start < L.size(); ++start) {
		int aktuelle_summe = 0;
		for (size_t ende = start; ende < L.size(); ++ende) {
			aktuelle_summe += L[ende];
			if (aktuelle_summe > maxsub_a) {
				maxsub_a = aktuelle_summe;
			}
		}
	}

	int maxsub_b = R[0];
	for (size_t start = 0; start < R.size(); ++start) {
		int aktuelle_summe = 0;
		for (size_t ende = start; ende < R.size(); ++ende) {
			aktuelle_summe += R[ende];
			if (aktuelle_summe > maxsub_b) {
				maxsub_b = aktuelle_summe;
			}
		}
	}

	int Lsg = max(maxsub_a, maxsub_b);
	Lsg = max(Lsg, maxsub_x + maxsub_y);
	cout << Lsg << endl;

//	for(size_t i = 0; i < L.size(); i++){
//		cout << L[i] << endl;
//	}
//
//	for(size_t i = 0; i < R.size(); i++){
//		cout << R[i] << endl;
//	}

}
