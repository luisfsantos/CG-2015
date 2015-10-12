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
    glTranslatef(_position.getX(), _position.getY(), _position.getZ()/2*5);
    glColor3ub(255, 128, 0);
    glutSolidSphere(_position.getZ()*5, 20, 20);
    glPopMatrix();
    
}
