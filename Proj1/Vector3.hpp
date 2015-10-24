//
//  Vector3.hpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>

class Vector3
{
protected:
    double _x;
    double _y;
    double _z;
    
public:
    Vector3 ();
    Vector3 (double, double, double);
    ~Vector3 ();
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void set(double, double, double);
    Vector3 operator=(const Vector3&);
    Vector3 operator*(double);
    Vector3 operator+(const Vector3&);
    Vector3 operator-(const Vector3&);
    double dot(Vector3);
    Vector3* perp();
};

#endif /* Vector3_hpp */

