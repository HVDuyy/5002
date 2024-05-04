#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BieuthucSohoc {
protected:
    int a, b;
    char pheptoan;

public:
   
    BieuthucSohoc() {
        srand(time(NULL));
        a = rand() % 100; 
        b = rand() % 100; 
    }

   
    void xuatBieuthuc() {
        cout << "Bieu thuc: " << a << " " << pheptoan << " " << b << endl;
    }

   
    virtual double tinhKetQua() = 0;
};

class BieuthucCong : public BieuthucSohoc {
public:
    
    BieuthucCong() {
        pheptoan = '+';
    }

  
    double tinhKetQua() override {
        return a + b;
    }
};

class BieuthucTru : public BieuthucSohoc {
public:
   
    BieuthucTru() {
        pheptoan = '-';
    }

    double tinhKetQua() override {
        return a - b;
    }
};

class BieuthucNhan : public BieuthucSohoc {
public:
  
    BieuthucNhan() {
        pheptoan = '*';
    }

 
    double tinhKetQua() override {
        return a * b;
    }
};

int main4() {
    int n1, n2, n3; 
    cout << "Nhap so luong bieu thuc chi gom phep cong: ";
    cin >> n1;
    cout << "Nhap so luong bieu thuc chi gom phep tru: ";
    cin >> n2;
    cout << "Nhap so luong bieu thuc chi gom phep nhan: ";
    cin >> n3;

    int diem = 0;

   
    for (int i = 0; i < n1; ++i) {
        BieuthucCong cong;
        double ketqua = cong.tinhKetQua();

        double dapAn;
        cout << "\nNhap ket qua du doan cua ban cho bieu thuc chi gom phep cong: ";
        cin >> dapAn;

     
        if (dapAn == ketqua) {
            diem++; 
        }
    }

   
    for (int i = 0; i < n2; ++i) {
        BieuthucTru tru;
        double ketqua = tru.tinhKetQua();

        double dapAn;
        cout << "\nNhap ket qua du doan cua ban cho bieu thuc chi gom phep tru: ";
        cin >> dapAn;

     
        if (dapAn == ketqua) {
            diem++; 
        }
    }

   
    for (int i = 0; i < n3; ++i) {
        BieuthucNhan nhan;
        double ketqua = nhan.tinhKetQua();

        double dapAn;
        cout << "\nNhap ket qua du doan cua ban cho bieu thuc chi gom phep nhan: ";
        cin >> dapAn;

       
        if (dapAn == ketqua) {
            diem++;
        }
    }

    cout << "\nTong so diem cua ban la: " << diem << endl;

    return 0;
}
