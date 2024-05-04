#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BieuthucSohoc {
private:
    int a, b;
    char pheptoan;

public:
    
    BieuthucSohoc() {
        srand(time(NULL));
        a = rand() % 100; 
        b = rand() % 100; 
        pheptoan = "+-*/"[rand() % 4]; 
    }

   
    void nhapBieuthuc() {
        cout << "Nhap bieu thuc (vi du: a + b): ";
        cin >> a >> pheptoan >> b;
    }

  
    void xuatBieuthuc() {
        cout << "Bieu thuc: " << a << " " << pheptoan << " " << b << endl;
    }

    
    bool kiemTraCauTraLoi(double ketqua) {
        double result;
        switch (pheptoan) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = (double)a / b;
            break;
        }
        return ketqua == result;
    }
};

int main1() {
    BieuthucSohoc bieuThuc;

    
    bieuThuc.nhapBieuthuc();

    
    bieuThuc.xuatBieuthuc();

    double ketqua;
    cout << "Nhap ket qua du doan cua ban: ";
    cin >> ketqua;
    if (bieuThuc.kiemTraCauTraLoi(ketqua)) {
        cout << "Chinh xac! Ket qua la: " << ketqua << endl;
    }
    else {
        cout << "Sai roi! Ket qua dung la: " << ketqua << endl;
    }

    return 0;
}
