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
    _rotation = 0;
}

Orange::~Orange() {
    
}

void Orange::update(double delta_t) {
    std::vector<Vector3*>::iterator iter;
    int i = 0;
    _position = _position + _speed * delta_t;
	double modulo = sqrt(_speed.getX()*_speed.getX() + _speed.getY()*_speed.getY());
	_rotation += ((modulo * delta_t) / _radius) * (180/M_PI);
	//addRotation(_right, angle);
	if(_rotation >= 360) {
		_rotation -= 360;
		if(_rotation < 360) _rotation = 0;
	}
    for (iter = _vertices.begin(); iter != _vertices.end(); ++iter, i++) {
        double temp [4][2] = {{-_Width, _Height},{-_Width, -_Height},{_Width, -_Height},{_Width, _Height}};
        double tempX = temp[i][0];
        double tempY = temp[i][1];
        
        // translate back
        (*iter)->set(tempX + _position.getX(), tempY + _position.getY(), 0);
    }
}

void Orange::setSpeed(const Vector3& speed) {
    _speed = speed;
    _right.set(_speed.getY(), -_speed.getX(), 0);
    _absSpeed = sqrt(_speed.getX()*_speed.getX() + _speed.getY()*_speed.getY());
	_direction = atan(_speed.getY() / _speed.getX());
    //checkMagnitude();
}

void Orange::setSpeed(double x, double y, double z) {
    _speed.set(x, y, z);
    _right.set(-y, x, z);
    _absSpeed = sqrt(x*x + y*y);
	_direction = atan(y / x);
    //checkMagnitude();
}

void Orange::setAbsSpeed(double abs) {
    setSpeed(cos((getDirection() * M_PI) / 180.0) * abs, sin((getDirection() * M_PI) / 180.0)* abs, 0);
}

void Orange::draw() {
    double lengh = _radius * 3/4;
    GLfloat amb_leaf[]={0.03f,0.36f,0.16f,1.0f};
    GLfloat diff_leaf[]={0.0f,0.49f,0.0f,1.0f};
    GLfloat spec_leaf[]={0.28f,0.13f,0.0f,1.0f};
    GLfloat amb_orang[]={0.63f,0.36f,0.16f,1.0f};
    GLfloat diff_orang[]={1.0f,0.49f,0.0f,1.0f};
    GLfloat spec_orang[]={0.28f,0.13f,0.0f,1.0f};
    GLfloat amb_stem[]={0.31f,0.18f,0.02f,1.0f};
    GLfloat diff_stem[]={0.7f,0.4f,0.0f,1.0f};
    GLfloat spec_stem[]={0.28f,0.13f,0.0f,1.0f};
    GLfloat shine=88;
    
    glPushMatrix();
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_radius);
    glRotated(_rotation, _right.getX(), _right.getY(), _right.getZ());
    //Sphere
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb_orang);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff_orang);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec_orang);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    glPushMatrix();
    glColor3ub(255, 128, 0);
    glutSolidSphere(_radius, 20, 20);
    glPopMatrix();
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb_leaf);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff_leaf);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec_leaf);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    //Leaf
    glPushMatrix();
    glTranslated(0, lengh / 2, _radius);
    glScaled(0.5, 1, 0.1);
    glColor3ub(65, 235, 49);
    glutSolidSphere(lengh/2, 15, 15);
    glPopMatrix();
    //Stem
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb_stem);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff_stem);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec_stem);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
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

void Orange::reset(double abs) {
	double x;
	double y;
	do {
		x = rand() % 1280; 
	} while ( x < 0 || x > 1280);
	do {
		y = rand() % 1280; 
	} while ( y < 0 || y > 720);


	setPosition(x, y, 0);
	_direction = rand() % 360;
	setSpeed(cos((getDirection() * M_PI) / 180.0) * abs, sin((getDirection() * M_PI) / 180.0)* abs, 0);
}
