#include <iostream>
#include "at.h"
using namespace std;

int& at(int*vec, int len, int i){
	
	if(i >= len || i < 0){
		cerr << "index overflow" << endl;
	}
	
	return vec[i];
}