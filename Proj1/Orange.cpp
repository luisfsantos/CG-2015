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

Orange::~Orange() {
    
}

void Orange::draw() {
    
    glPushMatrix();
    glTranslatef(_position.getX(), _position.getY(), _position.getZ());
    glRotated((GLdouble) 0, 1.0, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 0.2, 0.0);
    glutSolidSphere(20, 100, 10);
    glPopMatrix();
    
}
