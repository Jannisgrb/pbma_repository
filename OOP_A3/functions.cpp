#include <iostream>
#include "header.h"
using namespace std;

int ggt1(int x, int y){
	if (x < y){
	y = y - x;

}

	if (y < x){
	x = x - y;

}

	if (y == x){
	return x;
}

return ggt1(x, y);
}

int ggt2(int x, int y){
	
	if (x < y){
	y = y % x;
}

	if (y < x){
	x = x % y;
}

	if (x == 0){
	return y;
}

	if (y == 0){
	return x;
}

return ggt2(x, y);
}