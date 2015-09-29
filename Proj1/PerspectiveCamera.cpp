

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

void PerspectiveCamera::computeProjectionMatrix() {
    
}

void PerspectiveCamera::computeVisualizationMatrix() {
    
}

void PerspectiveCamera::update() {
    
}


