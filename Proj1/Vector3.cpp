//
//  Vector3.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Vector3.hpp"

Vector3::Vector3() {}

Vector3::~Vector3() {

}

Vector3::Vector3(double x, double y, double z) {
    set(x, y, z);
}

void Vector3::set(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

double Vector3::getX() {
    return _x;
}
double Vector3::getY() {
    return _y;
}
double Vector3::getZ() {
    return _z;
}

void Vector3::setX(double x) {
    _x = x;
}
void Vector3::setY(double y) {
    _y = y;
}
void Vector3::setZ(double z) {
    _z = z;
}

Vector3 Vector3::operator=(const Vector3& vec) {
    this->Vector3::_x = vec._x;
    this->Vector3::_y = vec._y;
    this->Vector3::_z = vec._z;
    return *this;
}

Vector3 Vector3::operator*(double num) {
    double x1, y1, z1;
    x1 = this->Vector3::_x * num;
    y1 = this->Vector3::_y * num;
    z1 = this->Vector3::_z * num;
    Vector3 aux(x1, y1, z1);
    return aux;
}

Vector3 Vector3::operator+(const Vector3& vec) {
    double x1, y1, z1;
    x1 = this->Vector3::_x + vec._x;
    y1 = this->Vector3::_y + vec._y;
    z1 = this->Vector3::_z + vec._z;
    Vector3 aux(x1, y1, z1);
    return aux;
}

Vector3 Vector3::operator-(const Vector3& vec) {
    double x1, y1, z1;
    x1 = this->Vector3::_x - vec._x;
    y1 = this->Vector3::_y - vec._y;
    z1 = this->Vector3::_z - vec._z;
    Vector3 aux(x1, y1, z1);
    return aux;
}

double Vector3::dot(Vector3 vector) {
    return _x*vector.getX() + _y*vector.getY();
}

Vector3* Vector3::perp() {
    return  new Vector3(-_y, _x, 0);
}



