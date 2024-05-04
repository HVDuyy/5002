#include <iostream>
#include "phanSo.h"
using namespace std;
int main2() {
    int tuSo1, mauSo1, tuSo2, mauSo2;
    cout << "Day la chuong trinh Phan So!" << endl;
    cout << endl;
    cout << "Nhap tu so cua phan so thu nhat: ";
    cin >> tuSo1;
    cout << "Nhap mau so cua phan so thu nhat: ";
    cin >> mauSo1;

    
    cout << "Nhap tu so cua phan so thu hai: ";
    cin >> tuSo2;
    cout << "Nhap mau so cua phan so thu hai: ";
    cin >> mauSo2;

   
    PhanSo ps1(tuSo1, mauSo1);
    PhanSo ps2(tuSo2, mauSo2);

    
    PhanSo tong = ps1.cong(ps2);
    cout << "Tong cua hai phan so la: ";
    tong.inPhanSo();

    return 0;
}
