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
    glColor3ub(255, 128, 0);
    glutSolidSphere(30, 20, 20);
    glPopMatrix();
    
}
