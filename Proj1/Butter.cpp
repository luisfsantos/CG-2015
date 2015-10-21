//
//  Butter.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Butter.hpp"

Butter::Butter() {
    setAbsSpeed(0);
    setDirection(0);
    setSpeed(0,0,0);
    _height = 25;
}

Butter::Butter(double height) {
    setAbsSpeed(0);
    setDirection(0);
    setSpeed(0,0,0);
    _height = height;
}

Butter::~Butter() {
    
}

void Butter::draw() {
    glPushMatrix();
    glColor3ub(253, 228, 85);
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_height/2);
    glRotated(_direction, 0, 0, 1);
    glScaled(1.628*1.628, 1.628, 1);
    glutSolidCube(_height);
    glPopMatrix();
}
