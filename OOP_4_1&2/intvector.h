#ifndef INTVECTOR_H_
#define INTVECTOR_H_
#include <iostream>
using namespace std;

class IntVector {
private:
	int *Array;
	size_t length;

public:
	IntVector(size_t length);
	~IntVector();
	IntVector& operator=(const IntVector&);
	IntVector(const IntVector&);
	size_t size() const;
	int& operator[](size_t idx);
	void out() const;
	void remove(int idx);
};

#endif /* INTVECTOR_H_ */
