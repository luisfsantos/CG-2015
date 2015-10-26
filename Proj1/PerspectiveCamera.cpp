

//
//  PerspectiveCamera.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "PerspectiveCamera.hpp"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, double eyeX, double eyeY, double eyeZ)
: Camera(zNear, zFar)
{
    _fovy = fovy;
    _aspect = aspect;
	_eyeX = eyeX;
	_eyeY = eyeY;
	_eyeZ = eyeZ;
}

PerspectiveCamera::~PerspectiveCamera() {
    
}


void PerspectiveCamera::setEye(double eyeX, double eyeY, double eyeZ){
	_eyeX = eyeX;
	_eyeY = eyeY;
	_eyeZ = eyeZ;
}

void PerspectiveCamera::update(){
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	computeProjectionMatrix();
    computeVisualizationMatrix();
}

void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix(){
	//gluLookAt(1280 / 2, -100, 1000, 1280 / 2, 720 / 2, 0, 0, 1, 0);
	gluLookAt(_position.getX(), _position.getY(), _position.getZ(), _eyeX, _eyeY, _eyeZ, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}