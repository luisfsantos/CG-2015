//
//  LightSource.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef LightSource_hpp
#define LightSource_hpp

#include <stdio.h>
#include "Vector3.hpp"

#endif /* LightSource_hpp */

class LightSource
{
private:
    Vector3 _direction;
    Vector3 _position;
    double _ambient[4];
    double _difuse[4];
    double _specular[4];
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
    void setDifuse (const Vector3&);
    void setSpecular (const Vector3&);
    void draw();

};