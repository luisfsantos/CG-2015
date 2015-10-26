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
	double _eyeX;
	double _eyeY;
	double _eyeZ;
public:
    PerspectiveCamera(double, double, double, double,double, double, double);
    ~PerspectiveCamera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
	void setEye(double, double, double);

};


#endif /* PerspectiveCamera_hpp */
