//
//  DynamicObject.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "DynamicObject.hpp"

DynamicObject::DynamicObject () {
    setSpeed(0, 0, 0);
    setMovement(false, false, false, false);
    setDirection(0);
    setAbsSpeed(0);
    _accelaration = 0.2;
    _turnSpeed = 2;
    _maxSpeed = 5;
}

DynamicObject::~DynamicObject() {
    
}

void DynamicObject::update(double delta_t) {
    
}


void DynamicObject::setSpeed(const Vector3& speed) {
    _speed = speed;
}

void DynamicObject::setSpeed(double x, double y, double z) {
    _speed.set(x, y, z);
}

Vector3 DynamicObject::getSpeed() {
    return _speed;
}

double DynamicObject::getDirection() {
    return _direction;
}

void DynamicObject::setDirection(double direction) {
    _direction = direction;
}

double DynamicObject::getAbsSpeed() {
    return _absSpeed;
}

void DynamicObject::setAbsSpeed (double absSpeed) {
    _absSpeed = absSpeed;
}

void DynamicObject::accelarate(double rate) {
    if (_absSpeed<_maxSpeed) {
        _absSpeed += rate*_accelaration;
    } else {
        _absSpeed = _maxSpeed;
    }
    
}

void DynamicObject::brake(double rate){
    if (_absSpeed > -_maxSpeed*0.75) {
        _absSpeed -= rate*_accelaration;
    } else {
        _absSpeed = -_maxSpeed*0.75;
    }
}

void DynamicObject::turn(int direction) {
    _direction += direction*_turnSpeed;
}

void DynamicObject::setRotation(double rotation) {
    _rotation = rotation;
}

void DynamicObject::setMovement(bool up, bool down, bool left, bool right) {
    _movement[UP] = up;
    _movement[DOWN] = down;
    _movement[LEFT] = left;
    _movement[RIGHT] = right;
}




