#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int& Point::get_x() {
	return x;
}

int& Point::get_y() {
	return y;
}

int Point::get_x() const {
	return x;
}

int Point::get_y() const {
	return y;
}

Point& Point::operator+=(const Point &other) {
	this->x += other.x;
	this->y += other.y;

	return *this;
}

bool Point::operator==(const Point &other) const {
	if (x == other.x && y == other.y) {
		return true;
	} else {
		return false;
	}
}

