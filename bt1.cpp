#include "SoPhuc.h"

// Constructor
SoPhuc::SoPhuc(double r, double i) : thuc(r), ao(i) {}

// Phép cộng
SoPhuc SoPhuc::operator+(const SoPhuc& khac) const {
    return SoPhuc(thuc + khac.thuc, ao + khac.ao);
}

// Phép trừ
SoPhuc SoPhuc::operator-(const SoPhuc& khac) const {
    return SoPhuc(thuc - khac.thuc, ao - khac.ao);
}

// Phép nhân: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
SoPhuc SoPhuc::operator*(const SoPhuc& khac) const {
    return SoPhuc(thuc * khac.thuc - ao * khac.ao, 
                  thuc * khac.ao + ao * khac.thuc);
}

// Phép chia
SoPhuc SoPhuc::operator/(const SoPhuc& khac) const {
    double mau = khac.thuc * khac.thuc + khac.ao * khac.ao;
    // Lưu ý: Trong thực tế nên kiểm tra mau == 0
    return SoPhuc((thuc * khac.thuc + ao * khac.ao) / mau, 
                  (ao * khac.thuc - thuc * khac.ao) / mau);
}

// So sánh bằng
bool SoPhuc::operator==(const SoPhuc& khac) const {
    return (thuc == khac.thuc && ao == khac.ao);
}

// So sánh khác
bool SoPhuc::operator!=(const SoPhuc& khac) const {
    return !(*this == khac);
}

// Xuất dữ liệu
std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    os << sp.thuc << (sp.ao >= 0 ? " + " : " - ") << (sp.ao >= 0 ? sp.ao : -sp.ao) << "i";
    return os;
}

// Nhập dữ liệu
std::istream& operator>>(std::istream& is, SoPhuc& sp) {
    std::cout << "Nhap phan thuc: "; is >> sp.thuc;
    std::cout << "Nhap phan ao: "; is >> sp.ao;
    return is;
}
