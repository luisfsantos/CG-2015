//
//  Entity.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity() {
}

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
    
    if (test1 && test2) {
        return isIntersecting2(object);
    }
    return false;
}

double Entity::getHalfWidth() {
    return _halfWidth;
}

double Entity::getHalfHeight() {
    return _halfHeight;
}

std::vector<Vector3*> Entity::getAxis() {
    std::vector<Vector3*> axis;
    std::vector<Vector3*>::iterator iter;
    for ( iter = _vertices.begin() ; iter != _vertices.end(); ++iter){
        // get the current vertex
        Vector3 *p1 = *iter;
        // get the next vertex
        Vector3 *p2 = *(iter + 1 == _vertices.end() ? _vertices.begin() : iter + 1);
        // subtract the two to get the edge vector
        Vector3 edge = *p1 - *p2;
        // get either perpendicular vector
        Vector3 *normal = edge.perp();
        // the perp method is just (x, y) => (-y, x) or (y, -x)
        axis.push_back(normal);
    }
    return axis;
}

bool Entity::isIntersecting2(Entity object) {
    std::vector<Vector3*> axis1 = getAxis();
    std::vector<Vector3*> axis2 = object.getAxis();
    // loop over the axes1
    std::vector<Vector3*>::iterator iter;
    
    for ( iter = axis1.begin() ; iter != axis1.end(); ++iter){
        Vector3 *axis = *iter;
        // project both shapes onto the axis
        Projection p1 = project(*axis);
        Projection p2 = object.project(*axis);
        // do the projections overlap?
        if (!p1.overlap(p2)) {
            // then we can guarantee that the shapes do not overlap
            return false;
        }
    }
    for ( iter = axis2.begin() ; iter != axis2.end(); ++iter){
        Vector3 *axis = *iter;
        // project both shapes onto the axis
        Projection p1 = project(*axis);
        Projection p2 = object.project(*axis);
        // do the projections overlap?
        if (!p1.overlap(p2)) {
            // then we can guarantee that the shapes do not overlap
            return false;
        }
    }

    // if we get here then we know that every axis had overlap on it
    // so we can guarantee an intersection
    return true;
}

Projection Entity::project(Vector3 axis) {
    std::vector<Vector3*>::iterator iter;
    double min = axis.dot(**_vertices.begin());
    double max = min;
    for (iter = _vertices.begin() +1 ; iter != _vertices.end(); ++iter) {
        // NOTE: the axis must be normalized to get accurate projections
        double p = axis.dot(**iter);
        if (p < min) {
            min = p;
        } else if (p > max) {
            max = p;
        }
    }
    Projection *proj = new Projection(min, max);
    return *proj;
}


