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
#include "Orange.hpp"
#include "GameObject.hpp"


class Roadside : public StaticObject
{
public:
    std::vector<Cherrio*> _cherrios;
    GLuint _TableTexture;
public:
    Roadside ();
    Roadside (double [][3], int, double, double, double);
    ~Roadside();
    void draw ();
    void initTableTexture(char const *);
    void drawTable();
    void drawTable2();
    void drawTable3();
    bool isIntersecting(GameObject);
    std::vector<Cherrio*> getCherrios();
};


#endif /* Roadside_hpp */
