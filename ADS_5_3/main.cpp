#include <iostream>
#include "pbma.h"
using namespace std;

BigInt add (BigInt x, BigInt y){
	if(x == 0){
		return y;
	}else if(y == 0){
		return x;
	}

	if(x >= 1){
		return add(--x, ++y);
	}else{
		return add(++x, --y);
	}
}

BigInt pm(BigInt x){
	if(x == 0){
		return 0;
	}
	if(x > 0){
		return pm(x-1)-1;
	}
	else if(x < 0){
		return pm(x+1)+1;
	}
}

BigInt mult (BigInt x, BigInt y){
	if(x == 0 || y == 0){
		return 0;
	}
	if (x > 1){
		return add(y, mult(x-1, y));
	}else if(x < -1){
		return mult(pm(x), pm(y));
	}else if(x == 1){
		return y;
	}else if(y == 1){
		return x;
	}
}

int main(){
	cout << add(0, 4) << endl;
	cout << mult(2, 4) << endl;
}
