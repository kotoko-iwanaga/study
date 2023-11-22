#include <cmath>
#include <iostream>

class Point {
private:
	double x,y;

public:
	Point(double x1, double y1) : x(x1), y(y1) {}
	int Angle() {
		if (x > 0 && y > 0) {
			return 1;
		}
		else if (x < 0 && y > 0) {
			return 2;
		}
		else if (x < 0 && y < 0) {
			return 3;
		}
		else if (x > 0 && y < 0) {
			return 4;
		}
		else {
			return 0;
		}
	}

	double operator + (const Point& c1)
	{
		return sqrt(pow((x - c1.x), 2) + pow((y - c1.y), 2));
	}
}; // 