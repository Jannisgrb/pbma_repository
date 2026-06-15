#ifndef SEQUENCE_CPP
#define SEQUENCE_CPP

#include "Sequence.h"
#include <vector>

// Konstruktor
template<typename T>
Sequence<T>::Sequence(size_t cap) :
		_cap { cap }, _size { 0 } {
	// Sicherstellen, dass die Kapazität mindestens 1 ist, um Divisionen/Fehler bei 0 zu vermeiden
	if (_cap == 0)
		_cap = 1;
	_array = new T[_cap];
}

// Destruktor
template<typename T>
Sequence<T>::~Sequence() {
	delete[] _array;
}

// Kopierkonstruktor
template<typename T>
Sequence<T>::Sequence(const Sequence &other) :
		_cap { other._cap }, _size { other._size } {
	_array = new T[_cap];
	for (size_t i = 0; i < _size; ++i) {
		_array[i] = other._array[i];
	}
}

// Zuweisungsoperator (Copy-and-Swap)
template<typename T>
Sequence<T>& Sequence<T>::operator=(const Sequence &other) {
	Sequence tmp { other };
	std::swap(_cap, tmp._cap);
	std::swap(_size, tmp._size);
	std::swap(_array, tmp._array);
	return *this;
}

// Hilfsmethode zur Speicherreallokation
template<typename T>
void Sequence<T>::reserve(size_t new_cap) {
	if (new_cap < _size)
		return; // Kann nicht kleiner als aktuelle Elementanzahl werden

	T *new_array = new T[new_cap];
	for (size_t i = 0; i < _size; ++i) {
		new_array[i] = _array[i];
	}
	delete[] _array;
	_array = new_array;
	_cap = new_cap;
}

// clear setzt die logische Größe auf 0 zurück (Speicher bleibt intakt)
template<typename T>
void Sequence<T>::clear() {
	_size = 0;
}

// trim schrumpft die Kapazität exakt auf die aktuelle Elementanzahl
template<typename T>
void Sequence<T>::trim() {
	size_t new_cap = (_size == 0) ? 1 : _size;
	if (_cap > new_cap) {
		reserve(new_cap);
	}
}

// Getter-Methoden
template<typename T>
size_t Sequence<T>::size() const {
	return _size;
}

template<typename T>
size_t Sequence<T>::capacity() const {
	return _cap;
}

template<typename T>
bool Sequence<T>::is_empty() const {
	return _size == 0;
}

template<typename T>
bool Sequence<T>::is_full() const {
	return _size == _cap;
}

// Index-Zugriffsoperatoren (mit striktem Bounds-Check für den Test)
template<typename T>
T& Sequence<T>::operator[](size_t pos) {
	if (pos >= _size) {
		throw std::runtime_error("Sequence::operator[]: pos out of bounds");
	}
	return _array[pos];
}

template<typename T>
const T& Sequence<T>::operator[](size_t pos) const {
	if (pos >= _size) {
		throw std::runtime_error(
				"const Sequence::operator[]: pos out of bounds");
	}
	return _array[pos];
}

// Element einfügen (Vergrößert nun bei Bedarf dynamisch den Speicher!)
template<typename T>
void Sequence<T>::insert(size_t pos, const T &ele) {
	if (pos > _size) {
		throw std::runtime_error("Sequence::insert: pos out of bounds");
	}

	// WICHTIG: Wenn voll, Kapazität verdoppeln!
	if (is_full()) {
		reserve(_cap * 2);
	}

	// Elemente nach hinten verschieben
	for (size_t idx = _size; idx > pos; idx -= 1) {
		_array[idx] = _array[idx - 1];
	}
	_array[pos] = ele;
	_size += 1;
}

// Element am Ende anfügen
template<typename T>
void Sequence<T>::push_back(const T &ele) {
	insert(_size, ele);
}

// Element an bestimmter Position löschen
template<typename T>
void Sequence<T>::remove(size_t pos) {
	if (pos >= _size) {
		throw std::runtime_error("Sequence::remove: pos out of bounds");
	}
	for (size_t idx = pos; idx < _size - 1; ++idx) {
		_array[idx] = _array[idx + 1];
	}
	_size -= 1;
}

// Element nach Wert löschen
template<typename T>
bool Sequence<T>::remove_ele(const T &ele) {
	for (size_t i = 0; i < _size; ++i) {
		if (_array[i] == ele) {
			remove(i);
			return true;
		}
	}
	return false;
}

// Gleichheitsoperator für EXPECT_EQ
template<typename T>
bool Sequence<T>::operator==(const Sequence &other) const {
	if (_size != other._size) {
		return false;
	}
	for (size_t i = 0; i < _size; ++i) {
		if (_array[i] != other._array[i]) {
			return false;
		}
	}
	return true;
}



#endif // SEQUENCE_CPP
