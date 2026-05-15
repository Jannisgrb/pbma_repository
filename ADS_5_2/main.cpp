#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

int main(){
	vector<int> P = read_ints("maxsub.dat");

	int Mitte = P.size() / 2;

	vector<int> L;
	vector<int> R;

	for(int i = 0; i < Mitte; i++){
		L.push_back(P[i]);
	}

	for(int i = Mitte; i < P.size(); i++){
		R.push_back(P[i]);
	}

	for()

}
