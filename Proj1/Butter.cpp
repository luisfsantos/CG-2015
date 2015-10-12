//
//  Butter.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Butter.hpp"

Butter::Butter() {
    setAccel(0);
    setDirection(90);
    setSpeed(0,0,0);
}

Butter::~Butter() {
    
}

void Butter::draw() {
    glPushMatrix();
    glColor3ub(253, 228, 85);
    glTranslated(_position.getX(), _position.getY(), _position.getZ());
    glRotated(_direction, 1, 0, 0);
    glScaled(1.628*1.628, 1, 1.628);
    glutSolidCube(_position.getZ()/2*8);
    glPopMatrix();
}
