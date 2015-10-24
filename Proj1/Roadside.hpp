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
#include <vector>
#include "StaticObject.hpp"
#include "Vector3.hpp"
#include "Cherrio.hpp"

class Roadside : public StaticObject
{
public:
    std::vector<Cherrio*> _cherrios;
public:
    Roadside ();
    Roadside (double [][3], int, double, double, double);
    ~Roadside();
    void draw ();
    void drawTable();
    std::vector<Cherrio*> getCherrios();
};


#endif /* Roadside_hpp */
