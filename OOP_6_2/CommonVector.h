#ifndef COMMON_VECTOR_H
#define COMMON_VECTOR_H
#include <iostream>

template<typename T, std::size_t len>
class CommonVector {
private:
	T *elements;

public:
	CommonVector();
	~CommonVector();
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;
	void out(void) const;
};

#include "CommonVector.cpp"
#endif
