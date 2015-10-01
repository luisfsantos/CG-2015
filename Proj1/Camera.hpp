//
//  Camera.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#if defined(__APPLE__)|| defined(MACOSX)
    #include <GLUT/GLUT.h>
#else
    #include <GL/glut.h>
#endif
#include <stdio.h>
#include "Entity.hpp"


class Camera : public Entity
{
protected:
    double _near;
    double _far;
    double _xwindow = 1280;
    double _ywindow = 720;
public:
    Camera(double, double);
    Camera();
    ~Camera();
    virtual void update(GLint, GLint);
    virtual void computeProjectionMatrix(GLint, GLint);
    virtual void computeVisualizationMatrix(GLint, GLint);
};


#endif /* Camera_hpp */
