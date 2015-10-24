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

Orange::Orange(double x, double y, double z, double radius) {
    _radius = radius;
    _position.set(x, y, z);
    setBoundingBox(_radius, _radius);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
    _direction = 0;
}

Orange::~Orange() {
    
}

void Orange::update(double delta_t) {
	//setSpeed(cos((getDirection() * M_PI ) / 180.0 ) * getAbsSpeed(), sin((getDirection() * M_PI ) / 180.0 )* getAbsSpeed(), 0);
	_position = _position + _speed * delta_t;
	setAbsSpeed(sqrt(_speed.getX()*_speed.getX() + _speed.getY()*_speed.getY()));
	_direction += ((_absSpeed * delta_t) / _radius) * (180/M_PI);
	//addRotation(_right, angle);
	if(_direction >= 360) {
		_direction -= 360;
		if(_direction < 360) _direction = 0;
	}
}

void Orange::setSpeed(const Vector3& speed) {
    _speed = speed;
    _right.set(_speed.getY(), -_speed.getX(), 0);
    //checkMagnitude();
}

void Orange::setSpeed(double x, double y, double z) {
    _speed.set(x, y, z);
    _right.set(-y, x, z);
    //checkMagnitude();
}

void Orange::draw() {    
	double lengh = _radius * 3/4;
	glPushMatrix();
	glTranslated(_position.getX(), _position.getY(), _position.getZ()+_radius);
	//glMultMatrixd(m);
	glRotated(_direction, _right.getX(), _right.getY(), _right.getZ());
		//Sphere
		glPushMatrix();
		glColor3ub(255, 128, 0);
		glutSolidSphere(_radius, 20, 20);
		glPopMatrix();   
		//Leaf
		glPushMatrix();
		glTranslated(0, lengh / 2, _radius);
		glScaled(0.5, 1, 0.1);
		glColor3ub(65, 235, 49);
		glutSolidSphere(lengh/2, 15, 15);
		glPopMatrix();
		//Stem
		glPushMatrix();
		glTranslated(0, 0, _radius);
		glRotated(-30, 0, 0, 1);
		glRotated(-30, 1, 0, 0);
		glScaled(1, 1, 5);
		glColor3ub(45, 181, 33);
		glutSolidCube(_radius / 10);
		glPopMatrix();
	glPopMatrix();
}

void Orange::collide(GameObject* car) {
    ((DynamicObject*)car)->setPosition(105, 300, 0);
    ((DynamicObject*)car)->setAbsSpeed(0);
    ((DynamicObject*)car)->setDirection(90);
    ((DynamicObject*)car)->setMovement(false, false, false, false);
}
