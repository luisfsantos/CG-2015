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
}

Orange::~Orange() {
    
}

void Orange::draw() {    
	lengh = _radius * 3/4;
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ()+_radius);
	//Sphere
	glPushMatrix();

	glColor3ub(255, 128, 0);
	glutSolidSphere(_radius, 20, 20);
	glPopMatrix();   
	//Leaf
	glPushMatrix();
	glTranslatef(0, lengh / 2, _radius * 2);
	glScalef(0.5, 1, 0.01);
	glColor3ub(65, 235, 49);
	glutSolidSphere(lengh, 15, 15);
	glPopMatrix();
	//Stem
	glPushMatrix();
	glTranslated(0, 0, _radius * 2);
	glRotated(45, 0, 1, 0);
	glRotated(45, 1, 0, 0);
	glScaled(1, 1, 5);
	glColor3ub(45, 181, 33);
	glutSolidCube(_radius / 20);
	glPopMatrix();

	glPopMatrix();
}
