//
//  main.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "Vector3.hpp"
#include "LightSource.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#define MILLIS 20


/* Initialize OpenGL Graphics */

void initGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void timer(int value) {
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(MILLIS, timer, 0); // next timer call milliseconds later
}

GameManager *manager = new GameManager();
int xwindow = 1280, ywindow = 720;

void display() {
    manager->display();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    manager->reshape(width, height);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffered mode
    glutInitWindowSize(xwindow, ywindow);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    
    glutCreateWindow("Micro-Machines");          // Create window with the given title
    
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    manager->init();
    initGL();                       // Our own OpenGL initialization
    //glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
