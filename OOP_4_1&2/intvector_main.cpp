#include <iostream>
#include "intvector.h"
using namespace std;

void klappt();
void crash();
void copyassign();

int main(int argc, char *argv[]) {
	if (argc > 1 && string(argv[1]) == "-crash") {
		crash();
	} else {
		klappt();
		copyassign();
	}
	return 0;
}

void klappt() {
	IntVector vec = IntVector(17);
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i] = (int) i;
	}

	cout << "Das Feld ist " << vec.size() << " lang" << endl;
	vec.out();

	for (size_t i = 0; i < vec.size(); i++) {
		if (i % 2 == 0) {
			vec[i] += 42;
		}
	}

	cout << "\nDas Feld ist " << vec.size() << " lang" << endl;
	vec.out();
}

void crash() {
	cout << "Crash-Test:" << endl;
	IntVector vec = IntVector(17);
	cout << vec[42] << endl;
}

void copyassign() {
	IntVector v1(17);
	for (size_t i = 0; i < v1.size(); ++i) {
		v1[i] = (int) i;
	}
	cout << "v1: " << endl;
	v1.out();

	IntVector v2(v1);
	cout << "v2: " << endl;
	v2.out();

	IntVector v3(10);
	v3 = v2;
	cout << "v3: " << endl;
	v3.out();

	v3.remove(5);
	v3.out();

}
