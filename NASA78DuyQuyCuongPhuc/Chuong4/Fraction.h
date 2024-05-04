#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n) {
  
        numerator = rand() % n + 1;
        denominator = rand() % n + 1;
        simplify();
    }

    void simplify() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    
    Fraction operator+(const Fraction& other) const {
        Fraction result(1);
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

   
    Fraction operator-(const Fraction& other) const {
        Fraction result(1);
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }


    Fraction operator*(const Fraction& other) const {
        Fraction result(1);
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

 
    Fraction operator/(const Fraction& other) const {
        Fraction result(1);
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.simplify();
        return result;
    }

  
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

  
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

  
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

 
    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

