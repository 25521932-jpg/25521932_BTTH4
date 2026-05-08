#include "PhanSo.h"

using namespace std;

// UCLN
int PhanSo::UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// Constructor
PhanSo::PhanSo(int t, int m) {
    tu = t;

    if (m == 0)
        mau = 1;
    else
        mau = m;

    rutGon();
}

// Rút gọn
void PhanSo::rutGon() {
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    // Đưa dấu âm lên tử
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

// +
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    return PhanSo(
        tu * ps.mau + ps.tu * mau,
        mau * ps.mau
    );
}

// -
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    return PhanSo(
        tu * ps.mau - ps.tu * mau,
        mau * ps.mau
    );
}

// *
PhanSo PhanSo::operator*(const PhanSo& ps) const {
    return PhanSo(
        tu * ps.tu,
        mau * ps.mau
    );
}

// /
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    return PhanSo(
        tu * ps.mau,
        mau * ps.tu
    );
}

// ==
bool PhanSo::operator==(const PhanSo& ps) const {
    return (tu == ps.tu && mau == ps.mau);
}

// >
bool PhanSo::operator>(const PhanSo& ps) const {
    return tu * ps.mau > ps.tu * mau;
}

// <
bool PhanSo::operator<(const PhanSo& ps) const {
    return tu * ps.mau < ps.tu * mau;
}

// <<
ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1)
        os << ps.tu;
    else
        os << ps.tu << "/" << ps.mau;

    return os;
}

// >>
istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu: ";
    is >> ps.tu;

    cout << "Nhap mau: ";
    is >> ps.mau;

    if (ps.mau == 0)
        ps.mau = 1;

    ps.rutGon();

    return is;
}
