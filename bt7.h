#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
    int n;
    vector<double> data;

public:
    CVector(int size = 0);

    int size() const;

    double get(int i) const;

    void set(int i, double value);

    friend istream& operator>>(istream& is, CVector& v);

    friend ostream& operator<<(ostream& os, const CVector& v);
};

class CMatrix {
private:
    int rows, cols;
    vector<vector<double>> data;

public:
    CMatrix(int r = 0, int c = 0);

    friend istream& operator>>(istream& is, CMatrix& m);

    friend ostream& operator<<(ostream& os, const CMatrix& m);

    CMatrix operator+(const CMatrix& m) const;

    CMatrix operator-(const CMatrix& m) const;

    CMatrix operator*(const CMatrix& m) const;

    CVector multiplyVector(const CVector& v) const;
};

#endif
