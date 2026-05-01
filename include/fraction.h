#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Decimal {
public:
    virtual double convertToDecimal() const = 0;
    virtual ~Decimal() = default;
};

class Fraction : public Decimal {
private:
    int* num;
    int* den;

    void checkNull() const;

public:
    Fraction();
    Fraction(int n, int d);
    Fraction(const Fraction& other);
    Fraction(Fraction&& other) noexcept;

    Fraction& operator=(const Fraction& other);
    Fraction& operator=(Fraction&& other) noexcept;

    ~Fraction();

    double convertToDecimal() const override;

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif
