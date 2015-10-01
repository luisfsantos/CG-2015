
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
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    Vector3::Vector3 lbWheel(-2, -2.3, 0);
    Vector3::Vector3 lfWheel(-2, 2, 0);
    Vector3::Vector3 rbWheel(2, -2.3, 0);
    Vector3::Vector3 rfWheel(2, 2, 0);
    int scale = 10;
    
    glPushMatrix();
    glTranslated(_position.getX(), _position.getY(), _position.getZ()); //move car around
    glScaled(scale, scale, scale);
    //glRotated(90, 0, 0, 1);
    //glRotated(90, 0, 1, 0);
    
    // main blue strip
    glPushMatrix();
    glColor3ub(0, 157, 224);
    glTranslated(0, 0, 0.3);
    glScaled(3, 7, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    //head of driver
    glPushMatrix();
    glColor3ub(236, 238, 239);
    glTranslated(0, 0.2, 1.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    
    //red top strip
    glPushMatrix();
    glColor3ub(70, 85, 95);
    glTranslated(0, -2, 1.5);
    glScaled(3, 3, 1.4);
    glutSolidCube(1);
    glPopMatrix();
    
    //two white strips on either side of the driver
    //1
    glPushMatrix();
    glColor3ub(70, 85, 95);
    glTranslated(-1.1, 1.45, 0.95);
    glScaled(0.3, 3.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();
    //2
    glPushMatrix();
    glColor3ub(70, 85, 95);
    glTranslated(1.1, 1.45, 0.95);
    glScaled(0.3, 3.9, 0.3);
    glutSolidCube(1);
    glPopMatrix();
    
    
    
    this->drawWheel(lbWheel, 0.85);
    this->drawWheel(lfWheel, 0.65);
    this->drawWheel(rbWheel, 0.85);
    this->drawWheel(rfWheel, 0.65);
    
    glPopMatrix();
}

void Car::drawWheel (Vector3 translate, double width) {
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(width, 0.75, 0.75);
    glRotated(90, 0, 1, 0);
    glutSolidTorus(0.5, 1, 20, 20);
    glPopMatrix();
}