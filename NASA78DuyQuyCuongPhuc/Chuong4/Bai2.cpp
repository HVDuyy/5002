#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Point.h"


int main000() {
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Khong the mo file.\n";
        return 1;
    }

    int numberOfPoints;
    inputFile >> numberOfPoints;

    std::vector<Point> points;
    double x, y;
    for (int i = 0; i < numberOfPoints; ++i) {
        inputFile >> x >> y;
        points.emplace_back(x, y);
    }

    inputFile.close();

    
    std::sort(points.begin(), points.end(), comparePoints);

    std::cout << "Cac diem da duoc sap xep tang dan theo khoang cach den goc toa do:\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << "(" << points[i].x << ", " << points[i].y << ") - Khoang cach: " << points[i].distance << '\n';
    }

    return 0;
}
