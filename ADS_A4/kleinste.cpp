#include "kleinste.h"
#include <limits>
#include <vector>
using namespace std;

int kleinste(const vector<int>& a){
	if (a.empty()){
	return numeric_limits<int>::max();
	}

	int kleinste = a[0];
	for (unsigned int i = 0; i < a.size(); i++){
		if(a[i] < kleinste){
			kleinste = a[i];
	}
}
	return kleinste;
}