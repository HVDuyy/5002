#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    double x;
    double y;
    double distance;

    Point(double _x, double _y) : x(_x), y(_y) {
        distance = std::sqrt(x * x + y * y);
    }
};


bool comparePoints(const Point& a, const Point& b) {
    return a.distance < b.distance;
}