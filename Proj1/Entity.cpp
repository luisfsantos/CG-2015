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


Vector3* Entity::getPosition() {
    return &_position;
}

Vector3* Entity::setPosition(double x, double y, double z) {
    _position.set(x, y, z);
    return &_position;
}

Vector3* Entity::setPosition(Vector3 p) {
    Vector3 aux(0,0,0);
    _position = (aux) + p;
    return &_position;
}

void Entity::setBoundingBox(double halfHeight, double halfWidth) {
    _Height = _halfHeight = halfHeight;
    _Width = _halfWidth = halfWidth;
}

bool Entity::isIntersecting(Entity object) {
    bool test1 = false, test2 = false;
    
    test1 = (_position.getX() + _halfWidth >= object._position.getX() - object._halfWidth
             &&
             _position.getY() + _halfHeight >= object._position.getY() - object._halfHeight);
    
    test2 = (object._position.getX() + object._halfWidth >= _position.getX() - _halfWidth
             &&
             object._position.getY() + object._halfHeight >= _position.getY() - _halfHeight);
    
    return test1 && test2;
}

double Entity::getHalfWidth() {
    return _halfWidth;
}

double Entity::getHalfHeight() {
    return _halfHeight;
}
