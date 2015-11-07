//
//  LightSource.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef LightSource_hpp
#define LightSource_hpp
#include <stdlib.h>
#include <stdio.h>
#include "Vector3.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

class LightSource
{
private:
    Vector3 _direction;
    Vector3 _position;
    GLfloat _ambient[4];
    GLfloat _diffuse[4];
    GLfloat _specular[4];
    double _cut_off;
    double _exponent;
    GLenum _num;
    bool _state;
    
public:
    LightSource (GLenum);
    ~LightSource ();
    bool getState ();
    bool setState (bool);
    GLenum getNum ();
    void setPosition (const Vector3&);
    void setDirection (const Vector3&);
    void setCutOff (double);
    void setExponent (double);
    void setAmbient (const Vector3&);
    void setAmbient (GLfloat, GLfloat, GLfloat, GLfloat);
    void setDiffuse (const Vector3&);
    void setDiffuse (GLfloat, GLfloat, GLfloat, GLfloat);
    void setSpecular (const Vector3&);
    void setSpecular (GLfloat, GLfloat, GLfloat, GLfloat);
    void draw();
    
};

#endif /* LightSource_hpp */


