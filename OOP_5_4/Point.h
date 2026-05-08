#ifndef POINT_H_
#define POINT_H_
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0);
	int& get_x();
	int& get_y();
	int get_x() const;
	int get_y() const;
	Point& operator+=(const Point &other);
	bool operator==(const Point &other) const;
};



#endif /* POINT_H_ */
