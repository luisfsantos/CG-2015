//
//  Table.hpp
//  Proj1
//
//  Created by Luis Santos on 12/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Vector3.hpp"

class Table :public StaticObject
{
public:
    Table();
    ~Table();
    void draw();
};

#endif /* Table_hpp */
