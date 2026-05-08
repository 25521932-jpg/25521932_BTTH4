#include "Polynomial.h"
#include <cmath>

// Constructor
Polynomial::Polynomial(int deg) {
    degree = deg;
    coeff.resize(degree + 1, 0);
}

// Input
void Polynomial::input() {
    cout << "Nhap bac da thuc: ";
    cin >> degree;

    coeff.resize(degree + 1);

    for (int i = degree; i >= 0; i--) {
        cout << "He so bac " << i << ": ";
        cin >> coeff[i];
    }
}

// Output
void Polynomial::output() const {

    bool first = true;

    for (int i = degree; i >= 0; i--) {

        if (coeff[i] == 0)
            continue;

        if (!first && coeff[i] > 0)
            cout << " + ";

        if (coeff[i] < 0)
            cout << " - ";

        double value = abs(coeff[i]);

        if (i == 0)
            cout << value;
        else if (i == 1)
            cout << value << "x";
        else
            cout << value << "x^" << i;

        first = false;
    }

    if (first)
        cout << "0";
}

// Evaluate
double Polynomial::evaluate(double x) const {

    double result = 0;

    for (int i = 0; i <= degree; i++) {
        result += coeff[i] * pow(x, i);
    }

    return result;
}

// +
Polynomial Polynomial::operator+(const Polynomial& p) const {

    int maxDeg = max(degree, p.degree);

    Polynomial result(maxDeg);

    for (int i = 0; i <= maxDeg; i++) {

        double a = (i <= degree) ? coeff[i] : 0;
        double b = (i <= p.degree) ? p.coeff[i] : 0;

        result.coeff[i] = a + b;
    }

    return result;
}

// -
Polynomial Polynomial::operator-(const Polynomial& p) const {

    int maxDeg = max(degree, p.degree);

    Polynomial result(maxDeg);

    for (int i = 0; i <= maxDeg; i++) {

        double a = (i <= degree) ? coeff[i] : 0;
        double b = (i <= p.degree) ? p.coeff[i] : 0;

        result.coeff[i] = a - b;
    }

    return result;
}

// *
Polynomial Polynomial::operator*(const Polynomial& p) const {

    Polynomial result(degree + p.degree);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= p.degree; j++) {
            result.coeff[i + j] += coeff[i] * p.coeff[j];
        }
    }

    return result;
}

// >>
istream& operator>>(istream& is, Polynomial& p) {

    cout << "Nhap bac da thuc: ";
    is >> p.degree;

    p.coeff.resize(p.degree + 1);

    for (int i = p.degree; i >= 0; i--) {
        cout << "He so bac " << i << ": ";
        is >> p.coeff[i];
    }

    return is;
}

// <<
ostream& operator<<(ostream& os, const Polynomial& p) {

    bool first = true;

    for (int i = p.degree; i >= 0; i--) {

        if (p.coeff[i] == 0)
            continue;

        if (!first && p.coeff[i] > 0)
            os << " + ";

        if (p.coeff[i] < 0)
            os << " - ";

        double value = abs(p.coeff[i]);

        if (i == 0)
            os << value;
        else if (i == 1)
            os << value << "x";
        else
            os << value << "x^" << i;

        first = false;
    }

    if (first)
        os << "0";

    return os;
}

