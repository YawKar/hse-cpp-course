//
// Created by yawkar on 11.10.22.
//

#ifndef HSE_CPP_COURSE_VEC3D_H
#define HSE_CPP_COURSE_VEC3D_H


class Vec3D {
public:

    Vec3D() {
        _x = _y = _z = 0;
    }

    Vec3D(double x, double y, double z);

    Vec3D(double x, double y);

    explicit Vec3D(double x);

    Vec3D(const Vec3D &other);

    double x() const;
    double y() const;
    double z() const;

    double operator*(const Vec3D &other) const;
    Vec3D operator&(const Vec3D &other) const;
private:
    double _x, _y, _z;
};


#endif //HSE_CPP_COURSE_VEC3D_H
