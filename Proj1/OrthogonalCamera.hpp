//
//  OrthogonalCamera.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef OrthogonalCamera_hpp
#define OrthogonalCamera_hpp

#include <stdio.h>
#include "Camera.hpp"

class OrthogonalCamera : public Camera
{
private:
    double _left;
    double _right;
    double _bottom;
    double _top;
public:
    OrthogonalCamera(double, double, double, double, double, double);
    ~OrthogonalCamera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
};

#endif /* OrthogonalCamera_hpp */
