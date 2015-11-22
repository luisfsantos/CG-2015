//
//  Table.cpp
//  Proj1
//
//  Created by Luis Santos on 12/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Table.hpp"


Table::Table(){

}

Table::~Table(){
    
}

void Table::draw(){
    bool color = true;
    int w=1280, h=720, n=10, m=5;
    int sw = w/n, sh = h/m; //square width and height respectively
    //for each width and height draw a rectangle with a specific color
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 5; ++j) {
            //oscillate the color per square of the board
            if(color)
                glColor3ub(255, 255, 255);
            else
                glColor3ub(0, 0, 255);
            color = !color;
            
            //draw a rectangle in the ith row and jth column
            //glRecti(i*sw, j*sh, (i+1)*sw, (j+1)*sh);
            glPushMatrix();
            glBegin(GL_POLYGON);
            glVertex3i(i*sw, j*sh, -39);
            glVertex3i(j*sh, (i+1)*sw, -39);
            glVertex3i((i+1)*sw, (j+1)*sh, -39);
            glVertex3i((j+1)*sh, i*sw, -39);
            glEnd();
        }
        if(m % 2 == 0) color = !color; //switch color order at end of row if necessary
    }
}