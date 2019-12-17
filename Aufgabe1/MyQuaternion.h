#ifndef MY_QUATERNION
#define MY_QUATERNION

#include <array>
#include <iostream>
#include <algorithm>

class MyQuaternion {
    private:
        std::array<double, 4> e;

    public:
        MyQuaternion();
        MyQuaternion(const MyQuaternion &other);
        MyQuaternion(double e_1, double e_2, double e_3, double e_4);

        MyQuaternion operator+ (const MyQuaternion &other);
        MyQuaternion operator- (const MyQuaternion &other);
        double& operator[](int i);
        const double& operator[](int i) const;
        MyQuaternion& operator= (const MyQuaternion &rhs);
        MyQuaternion& operator= (double scalar);

        MyQuaternion conj() const;

        MyQuaternion operator* (const MyQuaternion &Q);
        MyQuaternion operator* (double scale);

        // Damit man MyQuaternion vergleichen kann
        friend bool operator==(const MyQuaternion &lhs, const MyQuaternion &rhs);
        friend bool operator!=(const MyQuaternion &lhs, const MyQuaternion &rhs);

        // Damit man MyQuaternion mit cout benutzen kann
        friend std::ostream &operator<<(std::ostream &os, MyQuaternion const &m);

        MyQuaternion sortAscending() const;
};



#endif