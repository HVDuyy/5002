#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DeThiTracNghiem.h"
using namespace std;
char cauHoiTn::answerOfUser = ' ';
int main11() {
    cauHoiTn cauHoi;
    vector<cauHoiTn> danhSachCauHoi;
    int choice;
    string tenFile;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tao mot de thi trac nghiem moi" << endl;
        cout << "2. Them mot cau hoi moi vao de thi hien hanh" << endl;
        cout << "3. In danh sach cau hoi hien co trong de thi" << endl;
        cout << "4. Luu danh sach cau hoi vao file" << endl;
        cout << "5. Doc noi dung file" << endl;
        cout << "6. Cho thi va tinh so cau tra loi dung" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cauHoi.taoDeThi(danhSachCauHoi);
            break;
        case 2:
            cauHoi.themCauHoi(danhSachCauHoi);
            break;
        case 3:
            cauHoi.inDanhSachCauHoi(danhSachCauHoi);
            break;
        case 4:
            tenFile = "CN2301E.ttn";
            getline(cin, tenFile);
            cauHoi.luuDanhSachVaoFile(danhSachCauHoi, tenFile);
            break;
        case 5:
            tenFile = "CN2301E.ttn";
            getline(cin, tenFile);
            cauHoi.docNoiDungFile(danhSachCauHoi, tenFile);
            break;
        case 6:
            cauHoi.choThiVaTinhSoCau(danhSachCauHoi);
            break;
        case 0:
            cout << "Tam biet!";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}