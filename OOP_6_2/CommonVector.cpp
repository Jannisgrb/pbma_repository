#include "CommonVector.h"
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

template <typename T, size_t len> size_t CommonVector<T, len>::size() const {
	return len;
}

template <typename T, size_t len>
T &CommonVector<T, len>::operator[](size_t idx) {
	if (idx >= len) {
		throw std::runtime_error("CommonVector: idx out of bounds");
	}
	return elements[idx];
}

template <typename T, size_t len>
const T &CommonVector<T, len>::operator[](size_t idx) const {
	if (idx >= len) {
		throw std::runtime_error("const CommonVector: idx out of bounds");
	}
	return elements[idx];
}

template <typename T, size_t len> CommonVector<T, len>::CommonVector() {
	elements = new T[len]{};
}

template <typename T, size_t len> CommonVector<T, len>::~CommonVector() {
	delete[] elements;
}

template <typename T, std::size_t len>
void CommonVector<T, len>::out(void) const {
	std::cout << "[ ";
	for (std::size_t i = 0; i < len; i += 1) {
		if (i > 0 && i % 10 == 0) {
			std::cout << std::endl << " ";
		}
		std::cout << elements[i] << " ";
	}
	std::cout << "]";
}

template <typename T, size_t len> 
CommonVector<T, len>::CommonVector(const CommonVector &other) {
	elements = new T[len];
	
	for(size_t i = 0; i < other.size(); ++i){
		elements[i] = other.elements[i];
	}
}

template<typename T, std::size_t len>
CommonVector<T, len>& CommonVector<T, len>::operator=(const CommonVector& other){
	if(this != &other){
		delete[] elements;
	
		elements = new T[len];
		for(size_t i = 0; i < len; ++i){
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

// Explizite Instanziierungen für den Linker
template class CommonVector<int, 10>;
template class CommonVector<char, 25>;
template class CommonVector<char *, 4>;
