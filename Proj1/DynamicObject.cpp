//
//  DynamicObject.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "DynamicObject.hpp"

DynamicObject::DynamicObject () {
    
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