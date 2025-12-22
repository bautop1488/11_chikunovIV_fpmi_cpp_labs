//#pragma once
#ifndef MYCLASS_H
#define MYCLASS_H

struct Fraction{
    int num__;
    int denom__;

    Fraction();
    Fraction(int n, int d);

    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);

    Fraction& operator+=(const Fraction);
    Fraction& operator-=(const Fraction);
    Fraction& operator*=(const Fraction);
    Fraction& operator/=(const Fraction);
    Fraction& operator=(const Fraction);

    bool operator==(const Fraction);
    bool operator>(const Fraction);
    bool operator<(const Fraction);
    bool operator>=(const Fraction);
    bool operator<=(const Fraction);

    void Print();
};

#endif