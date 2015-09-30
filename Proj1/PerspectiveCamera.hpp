//
//  PerspectiveCamera.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef PerspectiveCamera_hpp
#define PerspectiveCamera_hpp

#include <stdio.h>
#include "Camera.hpp"

class PerspectiveCamera : public Camera
{
private:
    double _fovy;
    double _aspect;
public:
    PerspectiveCamera(double, double, double, double);
    ~PerspectiveCamera();
    void update(GLint, GLint);
    void computeProjectionMatrix(GLint, GLint);
    void computeVisualizationMatrix(GLint, GLint);

};


#endif /* PerspectiveCamera_hpp */
