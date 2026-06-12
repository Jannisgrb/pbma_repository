#include <iostream>
#include <vector>
#include <algorithm>
#include "pbma.h"
using namespace std;

int max_xy(const vector<int>& P, int low, int mid, int high){
	int max_x = P[mid]; 
	int aktuelle_summe = 0;
	for(int i = mid; i >= low; --i){
		aktuelle_summe += P[i];
		if(aktuelle_summe > max_x){
			max_x = aktuelle_summe;
		}
	}

	int max_y = P[mid + 1];
	aktuelle_summe = 0;
	for(int i = mid + 1; i <= high; ++i){
		aktuelle_summe += P[i];
		if(aktuelle_summe > max_y){
			max_y = aktuelle_summe;
		}
	}

	return max_x + max_y;
}

int maxsub_rekurviv(const vector<int>& P, int low, int high){
	if (low == high){
		return P[low];
	}

	int mid = low + (high - low) / 2;

	int max_a = maxsub_rekurviv(P, low, mid);
	int max_b = maxsub_rekurviv(P, mid + 1, high);

	int max_xy_result = max_xy(P, low, mid, high);

	return max(max(max_a, max_b), max_xy_result);
}

int main() {
	vector<int> P = read_ints("maxsubverylarge.dat");

	if (P.empty()) {
		cout << "Die Datei ist leer." << endl;
		return 1;
	}

	int maxsub = maxsub_rekurviv(P, 0, P.size() - 1);

	cout << "Das maxsub ist: " << maxsub << endl;
}
