#include "CDate.h"
#include <iomanip>
#include <cmath>

CDate::CDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

bool CDate::isLeapYear() const {
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

int CDate::daysInMonth() const {

    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && isLeapYear())
        return 29;

    return days[month];
}

long long CDate::toDays() const {

    long long total = 0;

    for (int y = 1; y < year; y++) {

        if ((y % 400 == 0) ||
            (y % 4 == 0 && y % 100 != 0))
            total += 366;
        else
            total += 365;
    }

    for (int m = 1; m < month; m++) {

        if (m == 2 &&
            ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0)))
            total += 29;

        else {
            int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            total += days[m];
        }
    }

    total += day;

    return total;
}

void CDate::fromDays(long long totalDays) {

    year = 1;

    while (true) {

        int daysOfYear =
            ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0))
            ? 366 : 365;

        if (totalDays > daysOfYear) {
            totalDays -= daysOfYear;
            year++;
        }
        else break;
    }

    month = 1;

    while (true) {

        int daysMonth;

        if (month == 2 &&
            ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0)))
            daysMonth = 29;

        else {
            int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            daysMonth = days[month];
        }

        if (totalDays > daysMonth) {
            totalDays -= daysMonth;
            month++;
        }
        else break;
    }

    day = totalDays;
}

CDate CDate::operator+(int days) {

    CDate temp = *this;

    long long total = temp.toDays();

    total += days;

    temp.fromDays(total);

    return temp;
}

CDate CDate::operator-(int days) {

    CDate temp = *this;

    long long total = temp.toDays();

    total -= days;

    temp.fromDays(total);

    return temp;
}

long long CDate::operator-(const CDate& other) {

    return llabs(this->toDays() - other.toDays());
}

CDate& CDate::operator++() {

    *this = *this + 1;

    return *this;
}

CDate CDate::operator++(int) {

    CDate temp = *this;

    *this = *this + 1;

    return temp;
}

CDate& CDate::operator--() {

    *this = *this - 1;

    return *this;
}

CDate CDate::operator--(int) {

    CDate temp = *this;

    *this = *this - 1;

    return temp;
}

istream& operator>>(istream& in, CDate& d) {

    cout << "Nhap ngay: ";
    in >> d.day;

    cout << "Nhap thang: ";
    in >> d.month;

    cout << "Nhap nam: ";
    in >> d.year;

    return in;
}

ostream& operator<<(ostream& out, const CDate& d) {

    out << setw(2) << setfill('0') << d.day << "/"
        << setw(2) << setfill('0') << d.month << "/"
        << d.year;

    return out;
}
