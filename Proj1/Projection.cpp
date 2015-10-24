//
//  Projection.cpp
//  Proj1
//
//  Created by Luis Santos on 23/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Projection.hpp"

Projection::Projection(double min, double max) {
    _min = min;
    _max = max;
}

bool Projection::overlap(Projection p) {
    if(_max > p._min) {
        return true;
    }
    
    if(_min > p._max) {
        return true;
    }
    
    return false;
}