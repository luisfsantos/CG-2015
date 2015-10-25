

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

void PerspectiveCamera::update(GLint w, GLint h){
    glViewport( 0, 0, w, h);
    computeProjectionMatrix(w,h);
    computeVisualizationMatrix(w,h);
}

void PerspectiveCamera::computeProjectionMatrix(GLint w, GLint h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix(GLint w, GLint h){
	//gluLookAt(1280 / 2, -100, 1000, 1280 / 2, 720 / 2, 0, 0, 1, 0);
	gluLookAt(_position.getX(), _position.getY(), _position.getZ(), _eyeX, _eyeY, _eyeZ, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}