#include "Menu.h"

int main() {
    Menu menu("Danh sach chuc nang");
    menu << "Chuc nang 0"
        << "Chuc nang 1"
        << "Chuc nang 2";

    int choice = menu.chon();
    cout << "Ban da chon: " << choice << endl;

    return 0;
}
