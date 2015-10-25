//
//  Camera.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include <stdlib.h>
#include <stdio.h>
#if defined(__APPLE__)|| defined(MACOSX)
    #include <GLUT/GLUT.h>
#else
    #include <GL/glut.h>
#endif
#include "Entity.hpp"

class Camera : public Entity
{
protected:
    double _near;
    double _far;
public:
    Camera(double, double);
    Camera();
    ~Camera();
    virtual void update();
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
};


#endif /* Camera_hpp */
