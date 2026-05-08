#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

class SoPhuc {
private:
    double thuc, ao;

public:
    // Constructor duy nhất với tham số mặc định
    // Cho phép: SoPhuc(), SoPhuc(r), SoPhuc(r, i)
    SoPhuc(double r = 0, double i = 0);

    // Các toán tử số học
    SoPhuc operator+(const SoPhuc& khac) const;
    SoPhuc operator-(const SoPhuc& khac) const;
    SoPhuc operator*(const SoPhuc& khac) const;
    SoPhuc operator/(const SoPhuc& khac) const;

    // Các toán tử so sánh
    bool operator==(const SoPhuc& khac) const;
    bool operator!=(const SoPhuc& khac) const;

    // Toán tử nhập/xuất (friend)
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
};

#endif
