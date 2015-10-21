//
//  Orange.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Orange.hpp"

Orange::Orange() {
    
}

Orange::Orange(double radius) {
    _radius = radius;
}

Orange::~Orange() {
    
}

void Orange::draw() {
    glPushMatrix();
    glTranslatef(_position.getX(), _position.getY(), _position.getZ()+_radius);
    glColor3ub(255, 128, 0);
    glutSolidSphere(_radius, 20, 20);
    glPopMatrix();
    
}
