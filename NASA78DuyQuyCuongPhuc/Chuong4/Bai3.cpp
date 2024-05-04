#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Fraction.h"

using namespace std;


int main111() {
    int n;
    cout << "Enter the upper limit (n): ";
    cin >> n;

    srand(time(NULL));
    vector<Fraction> fractions;

   
    for (int i = 0; i < 100; ++i) {
        Fraction frac(n);
        fractions.push_back(frac);
    }

    cout << "Fractions less than or equal to 1/2:" << endl;
    for (const auto& frac : fractions) {
        if (frac < Fraction(1)) {
            cout << frac << endl;
        }
    }


    sort(fractions.begin(), fractions.end());
    fractions.erase(unique(fractions.begin(), fractions.end()), fractions.end());

 
    cout << "\nUnique fractions:" << endl;
    for (const auto& frac : fractions) {
        cout << frac << endl;
    }

    return 0;
}
