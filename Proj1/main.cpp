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
#include "Orange.hpp"

#define MILLIS 20

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    Orange::Orange rog;
    Orange::Orange rog2;
    rog.setPosition(50, 40, 5);
    rog2.setPosition(50, 70, -5);
    rog.draw();
    rog2.draw();
    
    glutSwapBuffers();
    glFlush();
}

void timer(int value) {
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(MILLIS, timer, 0); // next timer call milliseconds later
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(600, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Micro-Machines");          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    //glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
