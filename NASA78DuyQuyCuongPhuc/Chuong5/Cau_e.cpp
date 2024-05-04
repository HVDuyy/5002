#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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

  
    virtual void xuatBieuthuc() = 0;

  
    virtual double tinhKetQua() = 0;
};

class BieuthucBinhphuong : public BieuthucSohoc {
public:

    BieuthucBinhphuong() {
        pheptoan = '^';
    }

   
    double tinhKetQua() override {
        return pow(a, 2);
    }

    
    void xuatBieuthuc() override {
        cout << "Bieu thuc: " << a << " ^ 2" << endl;
    }
};

class BieuthucBinhphuongTong : public BieuthucSohoc {
public:
  
    BieuthucBinhphuongTong() {
        pheptoan = '+';
    }

  
    double tinhKetQua() override {
        return pow(a, 2) + pow(b, 2);
    }

 
    void xuatBieuthuc() override {
        cout << "Bieu thuc: " << a << "^2 + " << b << "^2" << endl;
    }
};

class BieuthucBangNhau : public BieuthucSohoc {
public:
  
    BieuthucBangNhau() {
        pheptoan = '#';
    }

   
    double tinhKetQua() override {
        return a * b;
    }

    
    void xuatBieuthuc() override {
        cout << "Bieu thuc: " << a << " #" << b << endl;
    }
};

class BieuthucBangNhauTich : public BieuthucSohoc {
public:
    
    BieuthucBangNhauTich() {
        pheptoan = '*';
    }

  
    double tinhKetQua() override {
        return pow(a * b, 2);
    }

   
    void xuatBieuthuc() override {
        cout << "Bieu thuc: (" << a << " #" << b << ") * (" << a << " #" << b << ")" << endl;
    }
};

int main5() {
    BieuthucBinhphuong bieuthuc1;
    BieuthucBinhphuongTong bieuthuc2;
    BieuthucBangNhau bieuthuc3;
    BieuthucBangNhauTich bieuthuc4;

    cout << "Cac bieu thuc duoc sinh ngau nhien:" << endl;

    
    bieuthuc1.xuatBieuthuc();
    cout << "Ket qua: " << bieuthuc1.tinhKetQua() << endl;

    
    bieuthuc2.xuatBieuthuc();
    cout << "Ket qua: " << bieuthuc2.tinhKetQua() << endl;

   
    bieuthuc3.xuatBieuthuc();
    cout << "Ket qua: " << bieuthuc3.tinhKetQua() << endl;

    
    bieuthuc4.xuatBieuthuc();
    cout << "Ket qua: " << bieuthuc4.tinhKetQua() << endl;

    return 0;
}
