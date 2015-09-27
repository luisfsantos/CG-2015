//
//  Camera.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Entity.hpp"
#endif /* Camera_hpp */


class Camera : public Entity
{
protected:
    double _near;
    double _far;
public:
    Camera(double, double);
    ~Camera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
};