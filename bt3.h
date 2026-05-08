#ifndef CTIME_H
#define CTIME_H

#include <iostream>
using namespace std;

class CTime {
private:
    int hour;
    int minute;
    int second;

    void normalize();

public:
    // Constructor
    CTime(int h = 0, int m = 0, int s = 0);

    // Toán tử cộng trừ giây
    CTime operator+(int sec);
    CTime operator-(int sec);

    // ++time
    CTime& operator++();

    // time++
    CTime operator++(int);

    // --time
    CTime& operator--();

    // time--
    CTime operator--(int);

    // Nhập xuất
    friend istream& operator>>(istream& in, CTime& t);
    friend ostream& operator<<(ostream& out, const CTime& t);
};

#endif
