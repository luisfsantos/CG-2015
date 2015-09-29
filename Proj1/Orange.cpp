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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.0);
    glRotated((GLdouble) 0, 1.0, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 0.2, 0.0);
    glutSolidSphere(0.2, 1000, 10);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    
}
