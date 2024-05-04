#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "PhanMemQuanLy.h"
using namespace std;
int main() {
    vector<SinhVien> danhSachSV;
   
    danhSachSV.push_back(SinhVien("SV001", "Nguyen Van A", 3, 8.5, 7.5));
    danhSachSV.push_back(SinhVien("SV002", "Tran Thi B", 6, 6.0, 8.0));
    danhSachSV.push_back(SinhVien("SV003", "Le Van C", 2, 9.0, 6.5));
    danhSachSV.push_back(SinhVien("SV004", "Nguyen Thi D", 4, 7.5, 8.0));
    danhSachSV.push_back(SinhVien("SV005", "Hoang Van E", 8, 5.0, 7.0));

    xuatDanhSachDuDieuKien(danhSachSV);

    return 0;
}