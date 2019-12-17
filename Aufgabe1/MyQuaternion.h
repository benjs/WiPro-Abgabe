#ifndef MY_QUATERNION
#define MY_QUATERNION

#include <array>

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
};

#endif