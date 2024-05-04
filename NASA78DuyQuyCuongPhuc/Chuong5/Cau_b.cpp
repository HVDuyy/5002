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

    
    double tinhKetQua() {
        switch (pheptoan) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return (double)a / b;
        default:
            return 0;
        }
    }
};

int main2() {
    int diem = 0;
    int soCauHoi = 5; 
    int capDoKho = 10; 

    cout << "Chao mung den voi tro choi!" << endl;
    cout << "Ban se co " << soCauHoi << " cau hoi de tra loi. Moi cau hoi co cap do kho " << capDoKho << "." << endl;

    
    for (int i = 0; i < soCauHoi; ++i) {
        BieuthucSohoc bieuThuc;
        cout << "\nCau hoi " << i + 1 << ":" << endl;
        bieuThuc.nhapBieuthuc();
        double ketqua = bieuThuc.tinhKetQua();

        double dapAn;
        cout << "Nhap ket qua du doan cua ban: ";
        cin >> dapAn;

        
        if (dapAn == ketqua) {
            diem += capDoKho; 
            cout << "Chinh xac! Ket qua la: " << ketqua << endl;
        }
        else {
            cout << "Sai roi! Ket qua dung la: " << ketqua << endl;
        }
    }

    cout << "\nTong so diem cua ban la: " << diem << endl;
    cout << "Cam on ban da choi!" << endl;

    return 0;
}
