#include "CTime.h"
#include <iomanip>

CTime::CTime(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
    normalize();
}

void CTime::normalize() {
    int total = hour * 3600 + minute * 60 + second;

    // xử lý âm
    total = ((total % 86400) + 86400) % 86400;

    hour = total / 3600;
    total %= 3600;

    minute = total / 60;
    second = total % 60;
}

CTime CTime::operator+(int sec) {
    CTime temp(hour, minute, second);
    temp.second += sec;
    temp.normalize();
    return temp;
}

CTime CTime::operator-(int sec) {
    CTime temp(hour, minute, second);
    temp.second -= sec;
    temp.normalize();
    return temp;
}

// ++time
CTime& CTime::operator++() {
    second++;
    normalize();
    return *this;
}

// time++
CTime CTime::operator++(int) {
    CTime temp = *this;
    second++;
    normalize();
    return temp;
}

// --time
CTime& CTime::operator--() {
    second--;
    normalize();
    return *this;
}

// time--
CTime CTime::operator--(int) {
    CTime temp = *this;
    second--;
    normalize();
    return temp;
}

istream& operator>>(istream& in, CTime& t) {
    cout << "Nhap gio: ";
    in >> t.hour;

    cout << "Nhap phut: ";
    in >> t.minute;

    cout << "Nhap giay: ";
    in >> t.second;

    t.normalize();
    return in;
}

ostream& operator<<(ostream& out, const CTime& t) {
    out << setw(2) << setfill('0') << t.hour << ":"
        << setw(2) << setfill('0') << t.minute << ":"
        << setw(2) << setfill('0') << t.second;

    return out;
}
