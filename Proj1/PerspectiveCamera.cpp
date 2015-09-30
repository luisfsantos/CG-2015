

//
//  PerspectiveCamera.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "PerspectiveCamera.hpp"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar)
: Camera(zNear, zFar)
{
    _fovy = fovy;
    _aspect = aspect;
}

PerspectiveCamera::~PerspectiveCamera() {
    
}

void PerspectiveCamera::update(GLint w, GLint h){
    glViewport( 0, 0, w, h);
    computeProjectionMatrix(w,h);
    computeVisualizationMatrix(w,h);
}

void PerspectiveCamera::computeProjectionMatrix(GLint w, GLint h){
    float aspect = (float) w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspect, 0.01, 50);
}

void PerspectiveCamera::computeVisualizationMatrix(GLint w, GLint h){
    float aspect = (float) w / h;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-12.0,-12.0,0);
    //gluLookAt (_eye.getX(), _eye.getY(), _eye.getZ(),
      //         _at.getX(), _at.getY(), _at.getZ(),
        //       _up.getX(), _up.getY(), _up.getZ());
}


