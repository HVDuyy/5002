#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Abstract base class for arithmetic expressions
class BieuThucSoHoc {
public:
    virtual int evaluate() const = 0;
    virtual void display() const = 0;
    virtual ~BieuThucSoHoc() {} // Virtual destructor to ensure proper cleanup
};

// Class for addition expression
class BieuThucCong : public BieuThucSoHoc {
private:
    const BieuThucSoHoc* left;
    const BieuThucSoHoc* right;
public:
    BieuThucCong(const BieuThucSoHoc* l, const BieuThucSoHoc* r) : left(l), right(r) {}

    int evaluate() const override {
        return left->evaluate() + right->evaluate();
    }

    void display() const override {
        left->display();
        cout << " + ";
        right->display();
    }

    ~BieuThucCong() {
        delete left;
        delete right;
    }
};

// Class for subtraction expression
class BieuThucTru : public BieuThucSoHoc {
private:
    const BieuThucSoHoc* left;
    const BieuThucSoHoc* right;
public:
    BieuThucTru(const BieuThucSoHoc* l, const BieuThucSoHoc* r) : left(l), right(r) {}

    int evaluate() const override {
        return left->evaluate() - right->evaluate();
    }

    void display() const override {
        left->display();
        cout << " - ";
        right->display();
    }

    ~BieuThucTru() {
        delete left;
        delete right;
    }
};

// Class for multiplication expression
class BieuThucNhan : public BieuThucSoHoc {
private:
    const BieuThucSoHoc* left;
    const BieuThucSoHoc* right;
public:
    BieuThucNhan(const BieuThucSoHoc* l, const BieuThucSoHoc* r) : left(l), right(r) {}

    int evaluate() const override {
        return left->evaluate() * right->evaluate();
    }

    void display() const override {
        left->display();
        cout << " * ";
        right->display();
    }

    ~BieuThucNhan() {
        delete left;
        delete right;
    }
};

// Class for simple arithmetic expression
class BieuThucSoHocDonGian : public BieuThucSoHoc {
private:
    int value;
public:
    explicit BieuThucSoHocDonGian(int val) : value(val) {}

    int evaluate() const override {
        return value;
    }

    void display() const override {
        cout << value;
    }
};

// Function to generate random expression
BieuThucSoHoc* generateRandomExpression(int difficulty) {
    if (difficulty == 1) {
        // Generate simple expressions
        int a = rand() % 10;
        int b = rand() % 10;
        return new BieuThucCong(new BieuThucSoHocDonGian(a), new BieuThucSoHocDonGian(b));
    }
    else {
        // Generate more complex expressions
        // You can define your own complex expression generation logic here
        return nullptr;
    }
}

int main() {
    srand(time(nullptr));

    // Example usage
    BieuThucSoHoc* expression = generateRandomExpression(1); // Generate simple expression
    expression->display();
    cout << " = " << expression->evaluate() << endl;

    // Clean up memory
    delete expression;

    return 0;
}
