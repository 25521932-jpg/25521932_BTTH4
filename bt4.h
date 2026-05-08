#ifndef CDATE_H
#define CDATE_H

#include <iostream>
using namespace std;

class CDate {
private:
    int day;
    int month;
    int year;

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    bool isLeapYear() const;
    int daysInMonth() const;

    long long toDays() const;
    void fromDays(long long totalDays);

    // cộng trừ số ngày
    CDate operator+(int days);
    CDate operator-(int days);

    // khoảng cách giữa 2 ngày
    long long operator-(const CDate& other);

    // ++date
    CDate& operator++();

    // date++
    CDate operator++(int);

    // --date
    CDate& operator--();

    // date--
    CDate operator--(int);

    friend istream& operator>>(istream& in, CDate& d);
    friend ostream& operator<<(ostream& out, const CDate& d);
};

#endif

