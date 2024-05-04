#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class cauHoiTn {
private:
	string noiDung;
	string dapAnA;
	string dapAnB;
	char cauTraLoi;
	static char answerOfUser;
public:
	void nhap();
	void docFile(ifstream& f);
	void ghiFile(ostream& f);
	void kiemTra();
	void xuat();
	friend bool giongNhau(cauHoiTn cau1, cauHoiTn cau2);
	
	void taoDeThi(vector<cauHoiTn>& danhSachCauHoi);
	void themCauHoi(vector<cauHoiTn>& danhSachCauHoi);
	void inDanhSachCauHoi(vector<cauHoiTn>& danhSachCauHoi);
	void luuDanhSachVaoFile(vector<cauHoiTn>& danhSachCauHoi, const string& tenFile);
	void docNoiDungFile(vector<cauHoiTn>& danhSachCauHoi, const string& tenFile);
	void choThiVaTinhSoCau(vector<cauHoiTn>& danhSachCauHoi);
};
void cauHoiTn::nhap() {
	cout << "nhap noi dung: "; getline(cin, noiDung);
	cout << "nhap dap an A: "; getline(cin, dapAnA);
	cout << "nhap dap An B: "; getline(cin, dapAnB);
	cout << "nhap cau tra loi: "; cin >> cauTraLoi;
	cin.ignore();
}
void cauHoiTn::docFile(ifstream &f) {
	getline(f, noiDung);
	getline(f, dapAnA);
	getline(f, dapAnB);
	f >> cauTraLoi;
	f.ignore();
}
void cauHoiTn::ghiFile(ostream& f) {
	f << noiDung << endl;
	f << dapAnA << endl;
	f << dapAnB << endl;
	f << cauTraLoi << endl;
}
void cauHoiTn::kiemTra() {
	cout << noiDung << endl;
	cout << "Dap an A: " << dapAnA << endl;
	cout << "Dap an B: " << dapAnB << endl;
	cout << "Dap an cua ban la A hay B: "; cin >> answerOfUser;
	if (toupper(cauTraLoi) == toupper(answerOfUser)) {
		cout << "ban tra loi dung!";
	}
	else {
		cout << "ban tra loi sai!";
	}
}
void cauHoiTn::xuat() {
	cout << noiDung << endl;
	cout << "dap an dung la: " << cauTraLoi << "(";
	if (cauTraLoi == 'A') {
		cout << dapAnA;
	}
	else {
		cout << dapAnB;
	}
}
bool giongNhau(cauHoiTn cau1, cauHoiTn cau2) {
	return cau1.noiDung == cau2.noiDung &&
		   cau1.dapAnA == cau2.dapAnA &&
		   cau1.dapAnB == cau2.dapAnB &&
		   cau1.cauTraLoi == cau2.cauTraLoi;
}
void cauHoiTn::taoDeThi(vector<cauHoiTn>& danhSachCauHoi) {
	cauHoiTn cauHoi;
	cauHoi.nhap();
	danhSachCauHoi.push_back(cauHoi);
}
void cauHoiTn::themCauHoi(vector<cauHoiTn>& danhSachCauHoi) {
	cauHoiTn cauHoi;
	cauHoi.nhap();
	danhSachCauHoi.push_back(cauHoi);
}
void cauHoiTn::inDanhSachCauHoi(vector<cauHoiTn>& danhSachCauHoi) {
    for (int i = 0; i < danhSachCauHoi.size(); i++) {
        cout << "Cau hoi " << i + 1 << ": ";
        danhSachCauHoi[i].xuat(); 
        cout << endl;
    }
}
void cauHoiTn::luuDanhSachVaoFile(vector<cauHoiTn>& danhSachCauHoi, const string& tenFile) {
	ofstream f(tenFile);
	if (f.is_open()) {
		for (auto& cauHoi : danhSachCauHoi) {
			cauHoi.ghiFile(f);
		}
		f.close();
		cout << "Da luu danh sach cau hoi vao file " << tenFile << endl;
	}
	else {
		cout << "Khong the mo file " << tenFile << " de ghi!" << endl;
	}
}
void cauHoiTn::docNoiDungFile(vector<cauHoiTn>& danhSachCauHoi, const string& tenFile) {
	ifstream f(tenFile);
	if (f.is_open()) {
		cauHoiTn cauHoi;
		while (!f.eof()) {
			cauHoi.docFile(f);
			danhSachCauHoi.push_back(cauHoi);
		}
		f.close();
		cout << "Da doc noi dung tu file " << tenFile << endl;
	}
	else {
		cout << "Khong the mo file " << tenFile << " de doc!" << endl;
	}
}
void cauHoiTn::choThiVaTinhSoCau(vector<cauHoiTn>& danhSachCauHoi) {
	int soCauDung = 0;
	for (auto& cauHoi : danhSachCauHoi) {
		cauHoi.kiemTra(); 
		if (toupper(cauHoi.cauTraLoi) == toupper(answerOfUser)) { 
			soCauDung++; 
		}
	}
	cout << "So cau tra loi dung: " << soCauDung << "/" << danhSachCauHoi.size() << endl;
}