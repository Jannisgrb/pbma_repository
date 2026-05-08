#include "intvector.h"
#include <iostream>
using namespace std;

IntVector::IntVector(size_t length) {
	this->length = length;
	Array = new int[length];
}

IntVector::~IntVector() {
	delete[] Array;
}

size_t IntVector::size() const {
	return length;
}

int& IntVector::operator[](size_t idx) {
	if (idx >= 0 && idx < length) {
		return Array[idx];
	} else {
		throw runtime_error("Index out of range");
	}
}

void IntVector::out() const {
	for (size_t i = 0; i < length; i++) {
		cout << Array[i] << endl;
	}
}

IntVector::IntVector(const IntVector &other) {
	length = other.length;
	Array = new int[length];
	for (size_t i = 0; i < length; ++i) {
		Array[i] = other.Array[i];
	}
}

IntVector& IntVector::operator=(const IntVector &other) {
	if (this != &other) {
		delete[] Array;

		length = other.length;
		Array = new int[length];
		for (size_t i = 0; i < length; ++i) {
			Array[i] = other.Array[i];
		}
	}

	return *this;
}

void IntVector::remove(int idx) {
	if (idx > 0 && idx <= (int) length) {
		for (int i = idx; i < (int) length; ++i) {
			Array[i] = Array[i + 1];
		}
		length--;
	} else {
		throw runtime_error("idx nicht valid");
	}
}
