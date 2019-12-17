#include "MyQuaternion.h"

MyQuaternion::MyQuaternion() {
    for (int i = 0; i < 4; i++) {
        this->e[i] = 0;
    }
}

MyQuaternion::MyQuaternion(const MyQuaternion &Q) {
    for (int i = 0; i < 4; i++) {
        this->e[i] = Q[i];
    }
}

MyQuaternion::MyQuaternion(double e_1, double e_2, double e_3, double e_4) {
    this->e[0] = e_1;
    this->e[1] = e_2;
    this->e[2] = e_3;
    this->e[3] = e_4;
}

MyQuaternion MyQuaternion::operator+ (const MyQuaternion &other) {
    return MyQuaternion(this->e[0] + other[0], this->e[1] + other[1], this->e[2] + other[2], this->e[3] + other[3]);
}

MyQuaternion MyQuaternion::operator- (const MyQuaternion &other) {
    return MyQuaternion(this->e[0] - other[0], this->e[1] - other[1], this->e[2] - other[2], this->e[3] - other[3]);
}

double& MyQuaternion::operator[](int i) {
    //  .at() does bounds-checking so we dont need to do it ourselves
    return this->e.at(i);
}

const double& MyQuaternion::operator[](int i) const {
    return this->e.at(i);
}

MyQuaternion& MyQuaternion::operator= (const MyQuaternion &rhs) {
    this->e = rhs.e;
    return *this;
}

MyQuaternion& MyQuaternion::operator= (double scalar) {
    this->e = {0, 0, 0, scalar};
    return *this;
}

MyQuaternion MyQuaternion::conj() const {
    return MyQuaternion(-this->e[0], -this->e[1], -this->e[2], this->e[3]);
}

MyQuaternion MyQuaternion::operator* (const MyQuaternion &Q) {
    const std::array<double, 4> &a = this->e;
    const std::array<double, 4> &b = Q.e;

    MyQuaternion ret = {0, 0, 0, 0};

    ret[0] = a[0]*b[3] + a[3]*b[0] - a[1]*b[2] + a[2]*b[1];
    ret[1] = a[1]*b[3] + a[3]*b[1] - a[2]*b[0] + a[0]*b[2];
    ret[2] = a[2]*b[3] + a[3]*b[2] - a[0]*b[1] + a[1]*b[0];
    ret[3] = a[3]*b[3] - a[0]*b[0] - a[1]*b[1] - a[2]*b[2];
    return ret;
}

MyQuaternion MyQuaternion::operator* (double scale) {
    return MyQuaternion(scale*this->e[0], scale*this->e[1], scale*this->e[2], scale*this->e[3]);
}

bool operator==(const MyQuaternion &lhs, const MyQuaternion &rhs) {
    return lhs.e == rhs.e;
}

bool operator!=(const MyQuaternion &lhs, const MyQuaternion &rhs) {
    return !(lhs == rhs);
}

// Überladung vom << operator 
std::ostream &operator<<(std::ostream &os, MyQuaternion const &m) {
    return os << "{" << m[0] << ", " << m[1] << ", " << m[2] << ", " << m[3] << "}";
}