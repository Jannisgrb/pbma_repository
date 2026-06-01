#ifndef COMMON_VECTOR_H
#define COMMON_VECTOR_H

#include <iostream>
#include <stdexcept>

template<typename T, std::size_t len>
class CommonVector {
private:
	T *elements;

public:
	CommonVector() {
		elements = new T[len] { };
	}

	~CommonVector() {
		delete[] elements;
	}

	size_t size() const {
		return len;
	}

	T& operator[](size_t idx) {
		if (idx >= len) {
			throw std::runtime_error("idx ungültig");
		}
		return elements[idx];
	}

	const T& operator[](size_t idx) const {
		if (idx >= len) {
			throw std::runtime_error("idx ungültig");
		}
		return elements[idx];
	}

	void out(void) const {
		std::cout << "[ ";
		for (std::size_t i = 0; i < len; i += 1) {
			if (i > 0 && i % 10 == 0) {
				std::cout << std::endl << " ";
			}
			std::cout << elements[i] << " ";
		}
		std::cout << "]";
	}
};

#endif
