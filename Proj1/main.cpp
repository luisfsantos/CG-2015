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

Orange rog3 = Orange::Orange();


/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rog3.Orange::draw();
    
    glutSwapBuffers();
    glFlush();
}

void timer(int value) {
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(MILLIS, timer, 0); // next timer call milliseconds later
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    double aspectratio = width/height;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* simple keyboard speed */
void processSpecialKeys(int key, int x, int y) {
    
    switch(key) {
        case GLUT_KEY_UP :
            rog3.Orange::setSpeed(0, 2, 0);
            rog3.Orange::update(1);
            glutPostRedisplay();
             break;
        case GLUT_KEY_RIGHT :
            rog3.Orange::setSpeed(2, 0, 0);
            rog3.Orange::update(1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT :
            rog3.Orange::setSpeed(-2, 0, 0);
            rog3.Orange::update(1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN :
            rog3.Orange::setSpeed(0, -2, 0);
            rog3.Orange::update(1);
            glutPostRedisplay();
             break;
    }
}

int main(int argc, char** argv) {
    rog3.Orange::setPosition(50, 50, 10);
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffered mode
    glutInitWindowSize(600, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Micro-Machines");          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutSpecialFunc(processSpecialKeys);
    //glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
