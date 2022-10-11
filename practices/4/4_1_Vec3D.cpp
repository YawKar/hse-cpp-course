//
// Created by yawkar on 11.10.22.
//

#include "4_1_Vec3D.h"

Vec3D::Vec3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vec3D::Vec3D(double x, double y) : Vec3D(x, y, 0) {}

Vec3D::Vec3D(double x) : Vec3D(x, 0) {}

Vec3D::Vec3D(const Vec3D &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

double Vec3D::x() const { return _x; }

double Vec3D::y() const { return _y; }

double Vec3D::z() const { return _z; }

double Vec3D::operator*(const Vec3D &other) const {
    return _x * other._x + _y * other._y + _z * other._z;
}

Vec3D Vec3D::operator&(const Vec3D &other) const {
    return {_y * other._z - _z * other._y,
                 _z * other._x - _x * other._z,
                 _x * other._y - _y * other._x};
}
