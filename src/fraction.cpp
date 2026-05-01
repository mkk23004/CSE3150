#include "../include/fraction.h"

void Fraction::checkNull() const {
    if (!num || !den) {
        throw std::runtime_error("can't dereference null pointers");
    }
}

Fraction::Fraction() {
    std::cout << "I am in the default constructor\n";
    num = new int(0);
    den = new int(1);
}

Fraction::Fraction(int n, int d) {
    std::cout << "I am in the custom constructor\n";
    if (d == 0) throw std::runtime_error("Can't divide by zero!");
    num = new int(n);
    den = new int(d);
}

Fraction::Fraction(const Fraction& other) {
    std::cout << "I am in the copy constructor\n";
    other.checkNull();
    num = new int(*other.num);
    den = new int(*other.den);
}

Fraction::Fraction(Fraction&& other) noexcept {
    std::cout << "I am in the move constructor\n";
    num = other.num;
    den = other.den;
    // Nullify the moved-from object's pointers
    other.num = nullptr;
    other.den = nullptr;
}

Fraction& Fraction::operator=(const Fraction& other) {
    std::cout << "I am in the assignment operator (lvalue)\n";
    if (this != &other) {
        other.checkNull();
        if (!num) num = new int;
        if (!den) den = new int;
        *num = *other.num;
        *den = *other.den;
    }
    return *this;
}

Fraction& Fraction::operator=(Fraction&& other) noexcept {
    std::cout << "I am in the assignment operator (rvalue)\n";
    if (this != &other) {
        // Free existing memory before taking ownership
        delete num;
        delete den;
        num = other.num;
        den = other.den;
        other.num = nullptr;
        other.den = nullptr;
    }
    return *this;
}

Fraction::~Fraction() {
    std::cout << "I am in the destructor\n";
    delete num;
    delete den;
}

double Fraction::convertToDecimal() const {
    std::cout << "I am in the convertToDecimal\n";
    checkNull();
    // Static cast prevents integer division truncation
    return static_cast<double>(*num) / static_cast<double>(*den);
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the plus operator\n";
    lhs.checkNull();
    rhs.checkNull();
    int n = (*lhs.num * *rhs.den) + (*rhs.num * *lhs.den);
    int d = *lhs.den * *rhs.den;
    return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the multiplication operator\n";
    lhs.checkNull();
    rhs.checkNull();
    int n = *lhs.num * *rhs.num;
    int d = *lhs.den * *rhs.den;
    return Fraction(n, d);
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    std::cout << "I am in the << operator\n";
    frac.checkNull();
    os << *frac.num << "/" << *frac.den;
    return os;
}
