#include <cstdlib>
#include <iostream>
#include "at.h"
using namespace std;

int& at(int*vec, int len, int i){
	
	if(i >= len|| i < 0){
		throw out_of_range("index overflow");
	}
	
	return vec[i];
}