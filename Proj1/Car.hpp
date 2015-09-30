//
//  Car.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "DynamicObject.hpp"

class Car : public DynamicObject
{
public:
    Car();
    ~Car();
    virtual void draw();
};
#endif /* Car_hpp */


