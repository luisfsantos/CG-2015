//
//  OrthogonalCamera.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "OrthogonalCamera.hpp"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far)
: Camera(near, far){
    _left = left;
    _right = right;
    _bottom = bottom;
    _top = top;
}

OrthogonalCamera::~OrthogonalCamera() {
    
}

void OrthogonalCamera::update(){
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	computeProjectionMatrix( );
	computeVisualizationMatrix( );
}

void OrthogonalCamera::computeProjectionMatrix(){
    glMatrixMode( GL_PROJECTION);
    glLoadIdentity();
}

void OrthogonalCamera::computeVisualizationMatrix(){
    float xmin = _left, xmax = _right, ymin = _bottom, ymax = _top;
    float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    float xscale =(xmax-xmin)/_right, yscale=(ymax-ymin)/_top;
    float c = (xmax + xmin) * .5;
	xmax = c + xscale * glutGet(GLUT_WINDOW_WIDTH) * .5;
	xmin = c - xscale * glutGet(GLUT_WINDOW_WIDTH) * .5;
    c = (ymax + ymin) * .5;
	ymax = c + yscale * glutGet(GLUT_WINDOW_HEIGHT) * .5;
	ymin = c - yscale * glutGet(GLUT_WINDOW_HEIGHT) * .5;
    glOrtho(xmin, xmax, ymin, ymax, _near, _far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}