#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <algorithm>

template<typename T>
class Sequence {
public:
	Sequence(size_t cap = 10);
	Sequence(const Sequence &other);
	Sequence& operator=(const Sequence &other);
	~Sequence();

	size_t size() const;
	size_t capacity() const;
	bool is_empty() const;
	bool is_full() const;

	void clear();
	void trim();

	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;

	void insert(size_t pos, const T &ele);
	void push_back(const T &ele);
	void remove(size_t pos);
	bool remove_ele(const T &ele);

	bool operator==(const Sequence &other) const;

private:
	void reserve(size_t new_cap);

	T *_array;
	size_t _cap;
	size_t _size;
};

class studi {
private:
	int matrikelnummer = 0;
	std::string vorname = "";
	std::string nachname = "";
public:
	int get_matr() {
		return matrikelnummer;
	}

	std::string get_vn() {
		return vorname;
	}

	std::string get_nn() {
		return nachname;
	}

	int& set_matr() {
		return matrikelnummer;
	}

	std::string& set_vn() {
		return vorname;
	}

	std::string& set_nn() {
		return nachname;
	}

	void out(){
		std::cout << matrikelnummer << " " << vorname << " " << nachname << std::endl;
	}

	bool operator==(const studi &other) const {
		return matrikelnummer == other.matrikelnummer;
	}

	bool operator!=(const studi &other) const {
		return matrikelnummer != other.matrikelnummer;
	}

};

#include "sequence.cpp"

#endif // SEQUENCE_H
