//
//  River.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef River_hpp
#define River_hpp

#include <stdio.h>
#include "StaticObject.hpp"

class River :public StaticObject
{
public:
    River();
    ~River();
    void draw();
};


#endif /* River_hpp */
