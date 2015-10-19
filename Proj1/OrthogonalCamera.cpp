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

void OrthogonalCamera::update(GLint w, GLint h){
    glViewport( 0, 0, w, h);
    computeProjectionMatrix(w,h);
    computeVisualizationMatrix(w,h);
}

void OrthogonalCamera::computeProjectionMatrix(GLint w, GLint h){
    glMatrixMode( GL_PROJECTION);
    glLoadIdentity();
}

void OrthogonalCamera::computeVisualizationMatrix(GLint w, GLint h){
    float xmin = _left, xmax = _right, ymin = _bottom, ymax = _top;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float) w / h;
    float xscale =(xmax-xmin)/_right, yscale=(ymax-ymin)/_top;
    float c = (xmax + xmin) * .5;
    xmax = c + xscale * w * .5;
    xmin = c - xscale * w * .5;
    c = (ymax + ymin) * .5;
    ymax = c + yscale * h * .5;
    ymin = c - yscale * h * .5;
    glOrtho(xmin, xmax, ymin, ymax, _near, _far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}