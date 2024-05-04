#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu {
private:
    string tieude;
    vector<string> dsLuachon;

public:
    Menu(string tieude);
    Menu& operator<<(const string& luachon); 
    void xuat();
    int chon();
};

Menu::Menu(string tieude) {
    this->tieude = tieude;
}

Menu& Menu::operator<<(const string& luachon) {
    dsLuachon.push_back(luachon);
    return *this;
}

void Menu::xuat() {
    cout << "\n-----" << tieude << "-----\n";
    for (int i = 0; i < dsLuachon.size(); i++)
        cout << i << ". " << dsLuachon[i] << endl;
}

int Menu::chon() {
    int ch;
    do {
        xuat();
        cout << "Moi chon?";
        cin >> ch;
      
        string tmp;
        getline(cin, tmp);
        if (ch < 0 || ch >= dsLuachon.size())
            cout << "Chon sai, moi chon lai!!!\n";
    } while (ch < 0 || ch >= dsLuachon.size()); 
    return ch;
}
