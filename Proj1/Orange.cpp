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
    _length = radius * 3/4;
}

Orange::~Orange() {
    
}

void Orange::draw() {
    
    glPushMatrix();
    glTranslatef(_position.getX(), _position.getY(), _position.getZ()+_radius);
    //Sphere
    glPushMatrix();
    glColor3ub(255, 128, 0);
    glutSolidSphere(_radius, 20, 20);
    glPopMatrix();
    //Leaf
	glPushMatrix();
	glTranslatef(0, _length / 2, _radius * 2);
	glScalef(0.5, 1, 0.01);
	glColor3ub(0, 255, 0);
	glutSolidSphere(_length, 15, 15);
	glPopMatrix();
	//Stem
	glPushMatrix();
	glTranslatef(0, 0, _radius * 2);
	glRotated(45, 0, 1, 0);
	glRotated(45, 1, 0, 0);
	glScalef(1, 1, 5);
	glColor3ub(0, 255, 0);
	glutSolidCube(_radius / 100);
    glPopMatrix();

    glPopMatrix();
}
