//
//  main.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include <iostream>
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "Vector3.hpp"
#include "LightSource.hpp"
#include "GameManager.hpp"
#include "Orange.hpp"
#define MILLIS 15

GameManager *manager = new GameManager();
int xwindow = 1280, ywindow = 720;
bool keys[260];
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
    manager->onTimer();
    glutTimerFunc(MILLIS, timer, 5); // next timer call milliseconds later
}

void display() {
    manager->display();
}
void idle(){
    manager->idle(keys);
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    manager->reshape(width, height);
}

void myKeyboard(unsigned char key, int x, int y) {
    keys[key] = true;
    manager->keyPressed(keys);
}

void myKeyboard_S(int key, int x, int y) {
    keys[(key%100 + 256)] = true;
    manager->keyPressed(keys);
}

void myKeyboardUp_S(int key, int x, int y) {
    keys[(key%100 + 256)] = false;
    manager->keyPressed(keys);
}

void myKeyboardUp(unsigned char key, int x, int y) {
    keys[key] = false;
    manager->keyPressed(keys);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffered mode
    glutInitWindowSize(xwindow, ywindow);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    
    glutCreateWindow("Micro-Machines");          // Create window with the given title
    
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutKeyboardFunc(myKeyboard);
    glutKeyboardUpFunc(myKeyboardUp);
    glutSpecialFunc(myKeyboard_S);
    glutSpecialUpFunc(myKeyboardUp_S);
    manager->init();
    initGL();                       // Our own OpenGL initialization
    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutIdleFunc(idle);
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
