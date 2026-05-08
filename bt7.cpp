#include "CMatrix.h"

// ================= VECTOR =================

// Constructor
CVector::CVector(int size) {
    n = size;
    data.resize(n, 0);
}

// Lấy số chiều
int CVector::size() const {
    return n;
}

// Lấy phần tử
double CVector::get(int i) const {
    return data[i];
}

// Gán phần tử
void CVector::set(int i, double value) {
    data[i] = value;
}

// Nhập vector
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

// Xuất vector
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

// ================= MATRIX =================

// Constructor
CMatrix::CMatrix(int r, int c) {

    rows = r;
    cols = c;

    data.resize(rows, vector<double>(cols, 0));
}

// Nhập ma trận
istream& operator>>(istream& is, CMatrix& m) {

    cout << "Nhap so dong: ";
    is >> m.rows;

    cout << "Nhap so cot: ";
    is >> m.cols;

    m.data.resize(m.rows, vector<double>(m.cols));

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {

            cout << "a[" << i << "][" << j << "] = ";
            is >> m.data[i][j];
        }
    }

    return is;
}

// Xuất ma trận
ostream& operator<<(ostream& os, const CMatrix& m) {

    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << "\t";
        }

        os << endl;
    }

    return os;
}

// +
CMatrix CMatrix::operator+(const CMatrix& m) const {

    CMatrix result(rows, cols);

    if (rows != m.rows || cols != m.cols) {
        cout << "Khong cung kich thuoc!\n";
        return result;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + m.data[i][j];
        }
    }

    return result;
}

// -
CMatrix CMatrix::operator-(const CMatrix& m) const {

    CMatrix result(rows, cols);

    if (rows != m.rows || cols != m.cols) {
        cout << "Khong cung kich thuoc!\n";
        return result;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - m.data[i][j];
        }
    }

    return result;
}

// Nhân ma trận
CMatrix CMatrix::operator*(const CMatrix& m) const {

    if (cols != m.rows) {
        cout << "Khong the nhan hai ma tran!\n";
        return CMatrix();
    }

    CMatrix result(rows, m.cols);

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            result.data[i][j] = 0;

            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }

    return result;
}

// Ma trận * vector
CVector CMatrix::multiplyVector(const CVector& v) const {

    if (cols != v.size()) {
        cout << "Khong the nhan ma tran voi vector!\n";
        return CVector();
    }

    CVector result(rows);

    for (int i = 0; i < rows; i++) {

        double sum = 0;

        for (int j = 0; j < cols; j++) {
            sum += data[i][j] * v.get(j);
        }

        result.set(i, sum);
    }

    return result;
}

