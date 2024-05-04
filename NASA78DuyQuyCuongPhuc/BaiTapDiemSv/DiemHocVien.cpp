#include <iostream>
#include <string>
#include <vector>

class DiemHocVien {
private:
    std::string hoTen;
    int namSinh;
    float diemMon1;
    float diemMon2;
    float diemMon3;

public:

    DiemHocVien(std::string ten, int sinh, float mon1, float mon2, float mon3)
        : hoTen(ten), namSinh(sinh), diemMon1(mon1), diemMon2(mon2), diemMon3(mon3) {}


    ~DiemHocVien() {}

    std::string getHoTen() const { return hoTen; }
    int getNamSinh() const { return namSinh; }
    float getDiemMon1() const { return diemMon1; }
    float getDiemMon2() const { return diemMon2; }
    float getDiemMon3() const { return diemMon3; }


    bool passedThesis() const {
        float avg = (diemMon1 + diemMon2 + diemMon3) / 3;
        return (avg > 7) && (diemMon1 >= 5) && (diemMon2 >= 5) && (diemMon3 >= 5);
    }


    bool passedGraduation() const {
        float avg = (diemMon1 + diemMon2 + diemMon3) / 3;
        return (avg <= 7) && (diemMon1 >= 5) && (diemMon2 >= 5) && (diemMon3 >= 5);
    }

    bool needRetake() const {
        return (diemMon1 < 5) || (diemMon2 < 5) || (diemMon3 < 5);
    }

    void printInfo() const {
        std::cout << "Ho ten: " << hoTen << std::endl;
        std::cout << "Nam sinh: " << namSinh << std::endl;
        std::cout << "Diem mon 1: " << diemMon1 << std::endl;
        std::cout << "Diem mon 2: " << diemMon2 << std::endl;
        std::cout << "Diem mon 3: " << diemMon3 << std::endl;
    }
};

void countStudents(const std::vector<DiemHocVien>& students, int& thesisPassed, int& graduationPassed, int& retakeRequired) {
    for (const auto& student : students) {
        if (student.passedThesis()) {
            thesisPassed++;
        }
        else if (student.passedGraduation()) {
            graduationPassed++;
        }
        else if (student.needRetake()) {
            retakeRequired++;
        }
    }
}

int main() {
    DiemHocVien sv1("Nguyen Van A", 1998, 8, 7, 9);
    DiemHocVien sv2("Tran Thi B", 1997, 6, 5, 4);
    DiemHocVien sv3("Hoang Thi C", 1999, 7, 7, 7);
    DiemHocVien sv4("Le Van D", 1996, 4, 5, 6);
    DiemHocVien sv5("Pham Van E", 2000, 9, 8, 9);
    DiemHocVien sv6("Do Thi F", 1995, 5, 6, 7);

    std::vector<DiemHocVien> danhSachSV = { sv1, sv2, sv3, sv4, sv5, sv6 };


    for (const auto& sv : danhSachSV) {
        sv.printInfo();
        std::cout << std::endl;
    }


    int thesisPassed = 0;
    int graduationPassed = 0;
    int retakeRequired = 0;
    countStudents(danhSachSV, thesisPassed, graduationPassed, retakeRequired);


    std::cout << "So hoc vien lam luan van tot nghiep: " << thesisPassed << std::endl;
    std::cout << "So hoc vien thi tot nghiep: " << graduationPassed << std::endl;
    std::cout << "So hoc vien phai thi lai: " << retakeRequired << std::endl;

    return 0;
}
