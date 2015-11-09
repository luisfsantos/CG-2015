//
//  Candle.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright  2015 Luis Santos. All rights reserved.
//

#ifndef Candle_hpp
#define Candle_hpp
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "StaticObject.hpp"
#include "LightSource.hpp"


#ifndef M_PI
#define M_PI	3.14
#endif

class Candle : public StaticObject
{
private:
    LightSource* _flame;
public:
    Candle(LightSource*);
    Candle(double, double, double, LightSource*, Vector3);
    ~Candle();
    virtual void draw();
    void update(double);
};

#endif /* Candle_hpp */

