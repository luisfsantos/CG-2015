//
//  Camera.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera(double near, double far) {
    _near = near;
    _far = far;
}

Camera::Camera () {
    
}

Camera::~Camera() {

}

void Camera::update(GLint, GLint) {
    //fill this in depending on what its supposed to do
}

void Camera::computeProjectionMatrix(GLint, GLint) {
    //fill this in depending on what its supposed to do
}

void Camera::computeVisualizationMatrix(GLint, GLint) {
    //fill this in depending on what its supposed to do
}
