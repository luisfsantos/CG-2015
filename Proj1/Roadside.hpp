//
//  Roadside.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Roadside_hpp
#define Roadside_hpp

#include <stdio.h>
#include "StaticObject.hpp"

class Roadside : public StaticObject
{
public:
    Roadside ();
    ~Roadside();
    void draw ();
    
};


#endif /* Roadside_hpp */
