/*
 * Line.h
 *
 *  Created on: 06.05.2026
 *      Author: n3030503
 */

#ifndef LINE_H_
#define LINE_H_
#include "Point.h"
using namespace std;

class Line {
private:
	Point start;
	Point ende;
public:
	Line(Point start = Point(0,0), Point ende = Point(0,0));
	Point& get_start();
	Point& get_end();
	Line& operator+=(const Point& other);
	bool operator==(const Line& other);
};

#endif /* LINE_H_ */
