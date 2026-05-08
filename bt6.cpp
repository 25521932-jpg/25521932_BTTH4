#include "CVector.h"

// Constructor
CVector::CVector(int size) {
    n = size;
    data.resize(n, 0);
}

// Input
void CVector::input() {

    cout << "Nhap so chieu vector: ";
    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Phan tu [" << i << "] = ";
        cin >> data[i];
    }
}

// Output
void CVector::output() const {

    cout << "(";

    for (int i = 0; i < n; i++) {

        cout << data[i];

        if (i != n - 1)
            cout << ", ";
    }

    cout << ")";
}

// +
CVector CVector::operator+(const CVector& v) const {

    CVector result(n);

    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return result;
    }

    for (int i = 0; i < n; i++) {
        result.data[i] = data[i] + v.data[i];
    }

    return result;
}

// -
CVector CVector::operator-(const CVector& v) const {

    CVector result(n);

    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return result;
    }

    for (int i = 0; i < n; i++) {
        result.data[i] = data[i] - v.data[i];
    }

    return result;
}

// * số thực
CVector CVector::operator*(double k) const {

    CVector result(n);

    for (int i = 0; i < n; i++) {
        result.data[i] = data[i] * k;
    }

    return result;
}

// Tích vô hướng
double CVector::dot(const CVector& v) const {

    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += data[i] * v.data[i];
    }

    return sum;
}

// ==
bool CVector::operator==(const CVector& v) const {

    if (n != v.n)
        return false;

    for (int i = 0; i < n; i++) {
        if (data[i] != v.data[i])
            return false;
    }

    return true;
}

// >>
istream& operator>>(istream& is, CVector& v) {

    cout << "Nhap so chieu vector: ";
    is >> v.n;

    v.data.resize(v.n);

    for (int i = 0; i < v.n; i++) {
        cout << "Phan tu [" << i << "] = ";
        is >> v.data[i];
    }

    return is;
}

// <<
ostream& operator<<(ostream& os, const CVector& v) {

    os << "(";

    for (int i = 0; i < v.n; i++) {

        os << v.data[i];

        if (i != v.n - 1)
            os << ", ";
    }

    os << ")";

    return os;
}
