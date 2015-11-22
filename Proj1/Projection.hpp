//
//  Projection.hpp
//  Proj1
//
//  Created by Luis Santos on 23/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Projection_hpp
#define Projection_hpp

//#include <stdio.h>

class Projection {
    double _min;
    double _max;
public:
    Projection(double, double);
    bool overlap(Projection p);
};


#endif /* Projection_hpp */
