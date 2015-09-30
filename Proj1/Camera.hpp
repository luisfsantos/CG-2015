//
//  Camera.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include <GLUT/GLUT.h>
#include <stdio.h>
#include "Entity.hpp"


class Camera : public Entity
{
protected:
    double _near;
    double _far;
    double _xwindow = 500;
    double _ywindow = 500;
public:
    Camera(double, double);
    Camera();
    ~Camera();
    virtual void update(GLint, GLint);
    virtual void computeProjectionMatrix(GLint, GLint);
    virtual void computeVisualizationMatrix(GLint, GLint);
};


#endif /* Camera_hpp */
