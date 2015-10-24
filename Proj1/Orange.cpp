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
<<<<<<< HEAD
    _position.set(x, y, z);
    setBoundingBox(_radius, _radius);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
=======
    _direction = 0;
>>>>>>> refs/remotes/origin/pedro
}

Orange::~Orange() {
    
}

<<<<<<< HEAD
void Orange::draw() {
	float lengh = _radius * 3/4;
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ()+_radius);
	//Sphere
	glPushMatrix();
=======
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
/*
void Orange::checkMagnitude() {
	double w = _direction;
	double x = _right.getX();
	double y = _right.getY();
	double z = _right.getZ();
	if((w*w + x*x + y*y + z*z) < 0.9999 || 1.0001 < (w*w + x*x + y*y + z*z)) normalize();
}

double Orange::getMagnitude() {
	double w = _direction;
	double x = _right.getX();
	double y = _right.getY();
	double z = _right.getZ();
	return sqrt(w*w + x*x + y*y + z*z);
}

void Orange::normalize() {
	double m = getMagnitude();
	_direction /= m;
	_right.set(_right.getX()/m, _right.getY()/m, _right.getZ()/m);
}

void Orange::addRotation(Vector3 local, double angle) {
	double lr1 = cosf(angle/2);
	Vector3 lr2;
	lr2.set(	
		local.getX() * sinf(angle/2),
	   	local.getY() * sinf(angle/2),
	   	local.getZ() * sinf(angle/2));
	_direction = (
		lr1*_direction - 
		lr2.getX()*_right.getX() - 
		lr2.getY()*_right.getY() - 
		lr2.getZ()*_right.getZ());
	_right.setX(
		lr1*_right.getX() + 
		lr2.getX()*_direction + 
		lr2.getY()*_right.getZ() - 
		lr2.getZ()*_right.getY());
	_right.setY(
		lr1*_right.getY() - 
		lr2.getX()*_right.getZ() + 
		lr2.getY()*_direction + 
		lr2.getZ()*_right.getX());
	_right.setZ(
		lr1*_right.getZ() + 
		lr2.getX()*_right.getY() - 
		lr2.getY()*_right.getX() + 
		lr2.getZ()*_direction);
	checkMagnitude();
}*/

void Orange::draw() {    
	double lengh = _radius * 3/4;
	//last Rotation matrix
	/*const GLdouble a = 1 - 2*(_right.getY()*_right.getY()) - 2*(_right.getZ()*_right.getZ());
	//Matrix4 rot(
	const GLdouble *m = {
		(const GLdouble)a, 
		(const GLdouble)(2*(_right.getX()*_right.getY()) 	+ 2*(_direction*_right.getZ())), 
		(const GLdouble)(2*(_right.getX()*_right.getZ()) 	- 2*(_direction*_right.getY())), 
		(const GLdouble)0, 
>>>>>>> refs/remotes/origin/pedro

		(const GLdouble)(2*(_right.getX()*_right.getY())		- 2*(_direction*_right.getZ())), 
		(const GLdouble)(1 - 2*(_right.getX()*_right.getX())	- 2*(_right.getZ()*_right.getZ())), 
		(const GLdouble)(2*(_right.getY()*_right.getZ()) 	- 2*(_direction*_right.getX())), 
		(const GLdouble)0, 

		(const GLdouble)(2*(_right.getX()*_right.getZ())		+ 2*(_direction*_right.getY())), 
		(const GLdouble)(2*(_right.getY()*_right.getZ())		+ 2*(_direction*_right.getX())), 
		(const GLdouble)(1 - 2*(_right.getX()*_right.getX())	- 2*(_right.getY()*_right.getY())), 
		(const GLdouble)0,

		(const GLdouble)0, (const GLdouble)0, (const GLdouble)0, (const GLdouble)1};*/ 


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
