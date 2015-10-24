//
//  Orange.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Orange_hpp
#define Orange_hpp
#include <stdlib.h>
#include <stdio.h>
#include "Obstacle.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include <math.h> 
#include <cmath>
//#include "C:\Users\Utilizador\Documents\IST\CG\Proj\matrix\src\Matrices.h"
#include "Vector3.hpp"

class Orange : public Obstacle
{
private:
    double _radius;
    Vector3 _right;
public:
    Orange();
    Orange(double, double, double, double);
    ~Orange();
    void update(double delta_t);
    void setSpeed(const Vector3& speed);
    void setSpeed(double x, double y, double z);
    //quaternion
    void checkMagnitude();							//checks if quaternion is unitary & normailzes if needed
	double getMagnitude();							//gets quaternion absulute value
    void normalize();								//sets quaternion to unit value
    void addRotation(Vector3 local, double angle);	//adds update rotation to total rotation
    //end quaternion
    virtual void draw();
    void collide(GameObject *);
    void reset();
};

#endif /* Orange_hpp */

