#include <iostream>
#include "pbma.h"
using namespace std;

BigInt power_a_iterativ(BigInt n, int p) {
	BigInt result = n;
	if (n >= 1 && p >= 0) {
		for (int i = 1; i < p; ++i) {
			result = result * n;
		}
		return result;
	} else if (n >= 1 && p == 0) {
		return 1;
	} else {
		throw runtime_error("Invalid Numbers!");
	}
}

BigInt power_a_rekursiv(BigInt n, int p) {
	if (n < 1 || p < 0) {
		throw runtime_error("Invalid Numbers!");
	}

	if (p == 0) {
		return 1;
	}

	BigInt erg = power_a_rekursiv(n, p - 1);
	erg = n * erg;
	return erg;
}

BigInt power_a_endrekursiv(BigInt n, int p, BigInt erg = 1) {
	if (n < 1 || p < 0) {
		throw runtime_error("Invalid Numbers!");
	}

	if(p == 0){
		return erg;
	}

	erg = erg * n;
	return power_a_endrekursiv(n, p-1, erg);
}

int main() {
	cout << power_a_iterativ(3, 5) << endl;
	cout << power_a_rekursiv(3, 5) << endl;
	cout << power_a_endrekursiv(3, 5) << endl;
}
