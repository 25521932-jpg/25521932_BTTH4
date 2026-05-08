#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    int degree;
    vector<double> coeff;

public:
    Polynomial(int deg = 0);

    void input();
    void output() const;

    double evaluate(double x) const;

    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;

    friend istream& operator>>(istream& is, Polynomial& p);
    friend ostream& operator<<(ostream& os, const Polynomial& p);
};

#endif

