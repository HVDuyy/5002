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

    
    void nhapBieuthuc() {
        cout << "Nhap bieu thuc (vi du: a + b): ";
        cin >> a >> pheptoan >> b;
    }

    
    virtual double tinhKetQua() = 0;

   
    void xuatBieuthuc() {
        cout << "Bieu thuc: " << a << " " << pheptoan << " " << b << endl;
    }
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

int main3() {
    BieuthucCong cong;
    BieuthucTru tru;
    BieuthucNhan nhan;

    cout << "Cac bieu thuc duoc sinh ngau nhien:" << endl;

   
    cong.xuatBieuthuc();
    cout << "Ket qua: " << cong.tinhKetQua() << endl;

    
    tru.xuatBieuthuc();
    cout << "Ket qua: " << tru.tinhKetQua() << endl;

   
    nhan.xuatBieuthuc();
    cout << "Ket qua: " << nhan.tinhKetQua() << endl;

    return 0;
}
