#include <iostream>
#include "Line.h"
using namespace std;

Line::Line(Point start, Point ende) {
	this->start = start;
	this->ende = ende;
}

Point& Line::get_start() {
	return start;
}

Point& Line::get_end() {
	return ende;
}

Line& Line::operator+=(const Point &other) {
	this->start += other;
	this->ende += other;

	return *this;
}

bool Line::operator==(const Line &other) {
	if (this->start == other.start && this->ende == other.ende) {
		return true;
	} else {
		return false;
	}
}
