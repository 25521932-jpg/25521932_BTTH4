#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
private:
    int tu, mau;

    int UCLN(int a, int b);

public:
    // Constructor
    // Cho phép:
    // PhanSo()
    // PhanSo(5)
    // PhanSo(2,3)
    PhanSo(int t = 0, int m = 1);

    void rutGon();

    // Toán tử số học
    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;

    // Toán tử so sánh
    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;

    // Nhập xuất
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
};

#endif
