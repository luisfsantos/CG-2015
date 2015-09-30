
//
//  Car.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Car.hpp"

Car::Car() {
    
}

Car::~Car() {
    
}

void Car::draw() {
    int scale = 10;
    glPushMatrix();
    glTranslated(_position.getX(), _position.getY(), _position.getZ()); //move car around
    glScaled(scale, scale, scale);
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 0.2, 0.0);
    glTranslated(1, 0.5, 0.5);
    glScaled(3, 5, 0.5);
    glutSolidCube(1);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    glPopMatrix();
}

