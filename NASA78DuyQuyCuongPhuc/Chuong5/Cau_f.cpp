#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
    }

    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

class ExpressionFraction {
private:
    Fraction fraction1;
    Fraction fraction2;
    char operation;

public:
    ExpressionFraction(const Fraction& frac1, const Fraction& frac2, char op) : fraction1(frac1), fraction2(frac2), operation(op) {}

    Fraction evaluate() {
        switch (operation) {
        case '+':
            return add();
        case '-':
            return subtract();
        case '*':
            return multiply();
        case '/':
            return divide();
        default:
            throw runtime_error("Invalid operation");
        }
    }

    Fraction add() const {
        int num = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
        int denom = fraction1.getDenominator() * fraction2.getDenominator();
        return Fraction(num, denom);
    }

    Fraction subtract() const {
        int num = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
        int denom = fraction1.getDenominator() * fraction2.getDenominator();
        return Fraction(num, denom);
    }

    Fraction multiply() const {
        int num = fraction1.getNumerator() * fraction2.getNumerator();
        int denom = fraction1.getDenominator() * fraction2.getDenominator();
        return Fraction(num, denom);
    }

    Fraction divide() const {
        if (fraction2.getNumerator() == 0)
            throw runtime_error("Division by zero error");
        int num = fraction1.getNumerator() * fraction2.getDenominator();
        int denom = fraction1.getDenominator() * fraction2.getNumerator();
        return Fraction(num, denom);
    }
};

int main6() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);
    char op = '+';

    ExpressionFraction expr(frac1, frac2, op);
    Fraction result = expr.evaluate();

    cout << "Result: " << result << endl;

    return 0;
}
