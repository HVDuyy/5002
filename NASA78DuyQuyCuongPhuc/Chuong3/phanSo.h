#include <iostream>
using namespace std;
class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Constructor
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = mau;
    }


    PhanSo cong(const PhanSo& ps) const {
        int newTu = tuSo * ps.mauSo + ps.tuSo * mauSo;
        int newMau = mauSo * ps.mauSo;
        return PhanSo(newTu, newMau);
    }


    void inPhanSo() const {
        cout << tuSo << "/" << mauSo << endl;
    }
};