#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class SinhVien {
private:
    string maSV;
    string hoTen;
    int soBuoiVang;
    float diemTH;
    float diemGK;

public:
    SinhVien(string _maSV, string _hoTen, int _soBuoiVang, float _diemTH, float _diemGK) {
        maSV = _maSV;
        hoTen = _hoTen;
        soBuoiVang = _soBuoiVang;
        diemTH = _diemTH;
        diemGK = _diemGK;
    }

    string getMaSV() const {
        return maSV;
    }

    string getHoTen() const {
        return hoTen;
    }

    int getSoBuoiVang() const {
        return soBuoiVang;
    }

    float getDiemTH() const {
        return diemTH;
    }

    float getDiemGK() const {
        return diemGK;
    }

    float tinhDiemQT() const {
        if (soBuoiVang <= 5)
            return (10 - soBuoiVang * 2) * 0.2 + diemTH * 0.3 + diemGK * 0.5;
        else
            return 0;
    }
};

void nhapDanhSach(vector<SinhVien>& danhSach) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string maSV, hoTen;
        int soBuoiVang;
        float diemTH, diemGK;
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << ":\n";
        cout << "Ma SV: ";
        cin >> maSV;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "So buoi vang: ";
        cin >> soBuoiVang;
        cout << "Diem TH: ";
        cin >> diemTH;
        cout << "Diem GK: ";
        cin >> diemGK;
        danhSach.push_back(SinhVien(maSV, hoTen, soBuoiVang, diemTH, diemGK));
    }
}

void xuatDanhSach(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien:\n";
    cout << "Ma SV\tHo ten\tSo buoi vang\tDiem QT\n";
    for (const auto& sv : danhSach) {
        float diemQT = sv.tinhDiemQT();
        cout << sv.getMaSV() << "\t" << sv.getHoTen() << "\t" << sv.getSoBuoiVang() << "\t\t" << diemQT << endl;
    }
}

void xuatDanhSachDuDieuKien(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien du dieu kien du thi:\n";
    cout << "Ma SV\tHo ten\tSo buoi vang\tDiem QT\n";
    for (const auto& sv : danhSach) {
        float diemQT = sv.tinhDiemQT();
        if (diemQT >= 3)
            cout << sv.getMaSV() << "\t" << sv.getHoTen() << "\t" << sv.getSoBuoiVang() << "\t\t" << diemQT << endl;
    }
}

void xuatDanhSachNguyen(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien co ho la 'Nguyen':\n";
    cout << "Ma SV\tHo ten\tSo buoi vang\tDiem QT\n";
    for (const auto& sv : danhSach) {
        if (sv.getHoTen().find("Nguyen") != string::npos)
            cout << sv.getMaSV() << "\t" << sv.getHoTen() << "\t" << sv.getSoBuoiVang() << "\t\t" << sv.tinhDiemQT() << endl;
    }
}

void xuatDanhSachCungTen(const vector<SinhVien>& danhSach) {
    cout << "Danh sach sinh vien co cung ten voi mot sinh vien khac:\n";
    cout << "Ho ten\tSo luong\n";
    vector<string> hoTenList;
    for (const auto& sv : danhSach) {
        hoTenList.push_back(sv.getHoTen());
    }
    sort(hoTenList.begin(), hoTenList.end());
    string currentName = hoTenList[0];
    int count = 1;
    for (size_t i = 1; i < hoTenList.size(); ++i) {
        if (hoTenList[i] == currentName) {
            count++;
        }
        else {
            if (count > 1)
                cout << currentName << "\t" << count << endl;
            currentName = hoTenList[i];
            count = 1;
        }
    }
    if (count > 1)
        cout << currentName << "\t" << count << endl;
}