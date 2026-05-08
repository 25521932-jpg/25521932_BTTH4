#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
    int n;
    vector<double> data;

public:
    CVector(int size = 0);

    void input();
    void output() const;

    // Phép cộng vector
    CVector operator+(const CVector& v) const;

    // Phép trừ vector
    CVector operator-(const CVector& v) const;

    // Nhân vector với số thực
    CVector operator*(double k) const;

    // Tích vô hướng
    double dot(const CVector& v) const;

    // So sánh
    bool operator==(const CVector& v) const;

    // Nhập xuất
    friend istream& operator>>(istream& is, CVector& v);
    friend ostream& operator<<(ostream& os, const CVector& v);
};

#endif
