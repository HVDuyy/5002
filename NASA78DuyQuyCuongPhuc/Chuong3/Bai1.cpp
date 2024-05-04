#include <iostream>
#include "Rectangle.h"
using namespace std;
int main() {
    cout << "Day la chuong trinh hinh chu nhat! " << endl;
    CRectangle rect1, * rect2;

    // Setting values for rect1
    rect1.setHeight(3);
    rect1.setWidth(4);

    // Displaying information for rect1
    cout << "Chieu cao: " << rect1.getHeight() << endl;
    cout << "Chieu rong: " << rect1.getWidth() << endl;
    cout << "Hinh 1: " << rect1.area() << endl;
    cout << endl;

    // Creating rect2 dynamically
    rect2 = new CRectangle();

    // Setting values for rect2
    rect2->setHeight(5);
    rect2->setWidth(4);

    // Displaying information for rect2
    cout << "Chieu cao: " << rect2->getHeight() << endl;
    cout << "Chieu rong: " << rect2->getWidth() << endl;
    cout << "Hinh 2: " << rect2->area() << endl;

    // Don't forget to deallocate memory for dynamically allocated object
    delete rect2;

    return 0;
}
