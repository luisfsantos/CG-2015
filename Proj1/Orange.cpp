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
    _lenght = radius * 3/4;
}

Orange::~Orange() {
    
}

void Orange::draw() {
    glPushMatrix();
    //Sphere
    glPushMatrix();
    glTranslatef(_position.getX(), _position.getY(), _position.getZ()+_radius);
    glColor3ub(255, 128, 0);
    glutSolidSphere(_radius, 20, 20);
    glPopMatrix();
    //Leaf
	glPushMatrix();
	glTranslatef(0, _lenght / 2, _radius * 2);
	glScalef(0.5, 1, 0.01);
	glColor3ub(0, 255, 0);
	glutSolidSphere(_lenght, 15, 15);
	glPopMatrix();
	//Stem
	glPushMatrix();
	glTranslatef(0, 0, _radius * 2);
	glRotate(45, 0, 1, 0);
	glRotate(45, 1, 0, 0);
	glScalef(1, 1, 5);
	glColor3ub(0, 255, 0);
	glutSolidCube(_radius / 100);
    glPopMatrix();

    glPopMatrix();
}
