//
//  Entity.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity() {}

Entity::~Entity() {}


Vector3 Entity::getPosition() {
    return _position;
}

Vector3 Entity::setPosition(double x, double y, double z) {
    _position.set(x, y, z);
    return _position;
}

Vector3 Entity::setPosition(const Vector3& vec) {
    _position.set(vec.getX(), vec.getY(), vec.getZ());
}