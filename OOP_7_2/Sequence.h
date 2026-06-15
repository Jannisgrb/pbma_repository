#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstddef>     // Für size_t
#include <stdexcept>    // Für std::runtime_error
#include <string>
#include <algorithm>   // Für std::swap

template <typename T>
class Sequence {
public:
    // Standardkonstruktor mit initialer Startkapazität
    Sequence(size_t cap = 10);
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& other);
    ~Sequence();

    size_t size() const;
    size_t capacity() const;
    bool is_empty() const;
    bool is_full() const;

    void clear();
    void trim();

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    void insert(size_t pos, const T& ele);
    void push_back(const T& ele);
    void remove(size_t pos);
    bool remove_ele(const T& ele);

    bool operator==(const Sequence& other) const;

private:
    void reserve(size_t new_cap);

    T* _array;
    size_t _cap;
    size_t _size;
};

typedef struct {
    int matrikelnummer;
    std::string vorname;
    std::string nachname;

    bool operator==(const studi&other) const {
        return matrikelnummer == other.matrikelnummer;
    }

    bool operator!=(const studi&other) const {
        return matrikelnummer != other.matrikelnummer;
    }

} studi;

#include "sequence.cpp"

#endif // SEQUENCE_H
