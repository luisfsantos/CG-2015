//
//  Car.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Car.hpp"

Car::Car() {
    setDirection(90);
    setAbsSpeed(0);
    setBoundingBox(16, 9);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
}

Car::~Car() {
    
}

void Car::draw() {
    
    /***************************************
     DECLARING VARIABLES
     Object variables
     **************************************/
    
    //special colors
    int tecnico_Blue [3] =  {0, 157, 224};
    int tecnico_Gray [3] =  {70, 85, 95};
    
    //main undercarriage
    int *undercarriage_C = tecnico_Blue;
    Vector3 undercarriage_T (0, 0, 0.3+1);
    Vector3 undercarriage_S (3, 7, 1);
    
    //back engine compartment
    int *backEngine_C = tecnico_Gray;
    Vector3 backEngine_T(0, -2, 1.5+1);
    Vector3 backEngine_S(3, 3, 1.4);
    
    //strips on either side of driver
    Vector3 leftStrip_T(-1.1, 1.45, 0.95+1);
    Vector3 rightStrip_T(1.1, 1.45, 0.95+1);
    Vector3 bothStrip_S(0.3, 3.9, 0.3);
    
    
    //wheels
    int allWheel_C [3] = {0, 0, 0};
    Vector3 lbWheel_T(-2, -2.5, (1.25*sin(60*M_PI/180))+0.01);
    Vector3 lfWheel_T(-1.8, 2.15, (1.25*sin(60*M_PI/180))+0.01);
    Vector3 rbWheel_T(2, -2.5, (1.25*sin(60*M_PI/180))+0.01);
    Vector3 rfWheel_T(1.8, 2.15, (1.25*sin(60*M_PI/180))+0.01);
    Vector3 back_S(1, 1.25, 1.25);
    Vector3 front_S(0.6, 1.25, 1.25);
    
    //final scaling of the object
    int scale = 4;
    
    /****************************************
     METHOD CALLS
     Creating the objects
     ***************************************/
    
    
    glPushMatrix();
    
    glTranslated(_position.getX(), _position.getY(), _position.getZ()); //move car around
    glScaled(scale, scale, scale);
    glRotated(_direction-90, 0, 0, 1);
    
    // main undercarriage
    drawUnder();
    
    //head of driver
    glPushMatrix();
    glColor3ub(236, 238, 239);
    glTranslated(0, 0.2, 1.7);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    
    //back engine compartment
    drawCage();
    // strips on either side of the driver
    drawStrips();
    
    /**********
     WHEELS
     *********/
    // left back
    drawWheel(allWheel_C, lbWheel_T, back_S, false);
    // left front
    drawWheel(allWheel_C, lfWheel_T, front_S, false);
    // right back
    drawWheel(allWheel_C, rbWheel_T, back_S, true);
    // right front
    drawWheel(allWheel_C, rfWheel_T, front_S, true);
    
    glPopMatrix();
}

void Car::drawWheel (int color[], Vector3 translate, Vector3 scale, bool r) {
    /*
     glPushMatrix();
     glColor3f(color[0], color[1], color[2]);
     glTranslated(translate.getX(), translate.getY(), translate.getZ());
     glScaled(scale.getX(), scale.getY(), scale.getZ());
     glRotated(90, 0, 1, 0);
     glutSolidTorus(0.5, 1, 20, 20);
     glPopMatrix();*/
    glPushMatrix();
    glColor3ub(0, 0, 0);
    GLfloat amb[]={0.07f,0.07f,0.08f,1.0f};
    GLfloat diff[]={0.18f,0.19f,0.18f,1.0f};
    GLfloat spec[]={0.0f,0.0f,0.0f,1.0f};
    GLfloat shine=128;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(scale.getX(), scale.getY(), scale.getZ());
    if(r) glRotated(180, 0, 0, 1);
    glRotated(90, 0, 0, 1);
    //wheel side panels
    glPushMatrix();
    glTranslated(0, 0.25, 0);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f(1, 1, 0);
    glVertex3f( 1, 0, 0);
    glNormal3f(cos(60*M_PI/180),1, sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), 0, sin(60*M_PI/180));
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f(cos(60*M_PI/180), 1, sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), 0, sin(60*M_PI/180));
    glNormal3f(-cos(60*M_PI/180), 1, sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0, sin(60*M_PI/180));
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f(-cos(60*M_PI/180), 1, sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0, sin(60*M_PI/180));
    glNormal3f(-1, 1, 0);
    glVertex3f( -1, 0, 0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f(-1, 1, 0);
    glVertex3f( -1, 0, 0);
    glNormal3f(-cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0, -sin(60*M_PI/180));
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f( -cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0, -sin(60*M_PI/180));
    glNormal3f(cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), 0, -sin(60*M_PI/180));
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0);
    glVertex3f( 0, 0, 0);
    glNormal3f(cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), 0, -sin(60*M_PI/180));
    glNormal3f(1, 1, 0);
    glVertex3f( 1, 0, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    //wheel top panels
    glPushMatrix();
    glBegin(GL_TRIANGLE_STRIP);
    
    glVertex3f(1, -0.25, 0);
    glNormal3f(1, 1, 0);
    glVertex3f(1, 0.25, 0);
    glVertex3f(cos(60*M_PI/180), -0.25, sin(60*M_PI/180));
    glNormal3f(cos(60*M_PI/180),1, sin(60*M_PI/180));
    glVertex3f(cos(60*M_PI/180), 0.25, sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), -0.25, sin(60*M_PI/180));
    glNormal3f(-cos(60*M_PI/180), 1, sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0.25, sin(60*M_PI/180));
    glVertex3f( -1, -0.25, 0);
    glNormal3f(-1, 1, 0);
    glVertex3f( -1, 0.25, 0);
    glVertex3f( -cos(60*M_PI/180), -0.25, -sin(60*M_PI/180));
    glNormal3f( -cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( -cos(60*M_PI/180), 0.25, -sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), -0.25, -sin(60*M_PI/180));
    glNormal3f(cos(60*M_PI/180), 1, -sin(60*M_PI/180));
    glVertex3f( cos(60*M_PI/180), 0.25, -sin(60*M_PI/180));
    glVertex3f( 1, -0.25, 0);
    glNormal3f(1, 1, 0);
    glVertex3f( 1, 0.25, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
}

void Car::drawCubeObj (int color[], Vector3 translate, Vector3 scale) {
    glPushMatrix();
    glColor3ub(color[0], color[1], color[2]);
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(scale.getX(), scale.getY(), scale.getZ());
    glutSolidCube(1);
    glPopMatrix();
}

void Car::update(double delta_t) {
    double _angle = (((getDirection()-90) * M_PI ) / 180.0);
    int i = 0;
    std::vector<Vector3*>::iterator iter;
    if (_movement[UP]) accelarate(1);
    if (_movement[DOWN]) brake(1);
    if (_movement[LEFT]) turn(LL);
    if (_movement[RIGHT]) turn(RR);
    
    _halfWidth = _Height*std::abs(sin(_angle)) + _Width*std::abs(cos(_angle));
    _halfHeight = _Height*std::abs(cos(_angle)) + _Width*std::abs(sin(_angle));
    
    if (_absSpeed!=0 && !_movement[UP] && !_movement[DOWN]) {
        if (_absSpeed< -_accelaration) accelarate(0.4);
        else if (_absSpeed>_accelaration) brake(0.4);
        else _absSpeed = 0;
    }
    
    setSpeed(cos((getDirection() * M_PI ) / 180.0 ) * getAbsSpeed(), sin((getDirection() * M_PI ) / 180.0 )* getAbsSpeed(), 0);
    _position = _position + _speed * delta_t;
    for (iter = _vertices.begin(); iter != _vertices.end(); ++iter, i++) {
        double temp [4][2] = {{-_Width, _Height},{-_Width, -_Height},{_Width, -_Height},{_Width, _Height}};
        double tempX = temp[i][0];
        double tempY = temp[i][1];
        
        // now apply rotation
        float rotatedX = tempX*cos(_angle) - tempY*sin(_angle);
        float rotatedY = tempX*sin(_angle) + tempY*cos(_angle);
        
        // translate back
        (*iter)->set(rotatedX + _position.getX(), rotatedY + _position.getY(), 0);
    }
}

void Car::drawUnder() {
    glPushMatrix();
    glColor3ub(0, 157, 224);	//Tecnico Blue
    //GLfloat amb[] = { 0.0f,0.64f,0.87f,1.0f };
    //GLfloat diff[] = { 0.0f,0.17f,0.26f,1.0f };
    //GLfloat spec[] = { 0.3f,0.28f,0.39f,1.0f };
    GLfloat amb[]={0.0f,0.12f,0.23f,1.0f};
    GLfloat diff[]={0.0f,0.61f,0.87f,1.0f};
    GLfloat spec[]={0.07f,0.07f,0.07f,1.0f};
    GLfloat shine = 90;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
    glTranslated(0, 0, (1.25*sin(60*M_PI/180))+0.01);
    //top front bottom back panels
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(1,-1,1);
    glVertex3f(1.5, -3.5, 0.5);
    glNormal3f(-1,-1,1);
    glVertex3f(-1.5, -3.5, 0.5);
    glNormal3f(1,-0.6,1);
    glVertex3f(1.5, -2.5, 0.5);
    glNormal3f(-1,-0.6,1);
    glVertex3f(-1.5, -2.5, 0.5);
    glNormal3f(1,-0.3,1);
    glVertex3f(1.5, -1.5, 0.5);
    glNormal3f(-1,-0.6,1);
    glVertex3f(-1.5, -1.5, 0.5);
    glNormal3f(1, 0, 1);
    glVertex3f(1.5, -0.5, 0.5);
    glNormal3f(-1, 0, 1);
    glVertex3f(-1.5, -0.5, 0.5);
    glNormal3f(1, 0, 1);
    glVertex3f(1.5, 0.5, 0.5);
    glNormal3f(-1, 0, 1);
    glVertex3f(-1.5, 0.5, 0.5);
    glNormal3f(1, 0.3, 1);
    glVertex3f(1.5, 1.5, 0.5);
    glNormal3f(-1, 0.3, 1);
    glVertex3f(-1.5, 1.5, 0.5);
    glNormal3f(1, 0.6, 1);
    glVertex3f(1.5, 2.5, 0.5);
    glNormal3f(-1, 0.6, 1);
    glVertex3f(-1.5, 2.5, 0.5);
    glNormal3f(1,1,1);
    glVertex3f(1.5, 3.5, 0.5);
    glNormal3f(-1,1,1);
    glVertex3f(-1.5, 3.5, 0.5);
    
    glNormal3f(1,1,-1);
    glVertex3f(1.5, 3.5, -0.5);
    glNormal3f(-1,1,-1);
    glVertex3f(-1.5, 3.5, -0.5);
    glVertex3f(1.5, 2.5, -0.5);
    glVertex3f(-1.5, 2.5, -0.5);
    glVertex3f(1.5, 1.5, -0.5);
    glVertex3f(-1.5, 1.5, -0.5);
    glNormal3f(1, 0, -1);
    glVertex3f(1.5, 0.5, -0.5);
    glNormal3f(-1, 0, -1);
    glVertex3f(-1.5, 0.5, -0.5);
    glNormal3f(1, 0, -1);
    glVertex3f(1.5, -0.5, -0.5);
    glNormal3f(-1, 0, -1);
    glVertex3f(-1.5, -0.5, -0.5);
    glVertex3f(1.5, -1.5, -0.5);
    glVertex3f(-1.5, -1.5, -0.5);
    glVertex3f(1.5, -2.5, -0.5);
    glVertex3f(-1.5, -2.5, -0.5);
    glNormal3f(-1,-1,-0.5);
    glVertex3f(1.5, -3.5, -0.5);
    glNormal3f(-1,-1,-0.5);
    glVertex3f(-1.5, -3.5, -0.5);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(1,-1,1);
    glVertex3f(1.5, -3.5, 0.5);
    glNormal3f(1,-1,-1);
    glVertex3f(1.5, -3.5, -0.5);
    glNormal3f(0.25,-1,1);
    glVertex3f(0.75, -3.5, 0.5);
    glNormal3f(0.25,-1,-1);
    glVertex3f(0.75, -3.5, -0.5);
    glNormal3f(-0.25,-1,1);
    glVertex3f(-0.75, -3.5, 0.5);
    glNormal3f(-0.25,-1,-1);
    glVertex3f(-0.75, -3.5, -0.5);
    glNormal3f(-1,-1,1);
    glVertex3f(-1.5, -3.5, 0.5);
    glNormal3f(-1,-1,-1);
    glVertex3f(-1.5, -3.5, -0.5);
    
    glEnd();
    //right side panel
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(1.5, -3.5, -0.5);
    glVertex3f(1.5, -3.5, 0.5);
    glVertex3f(1.5, -2.5, -0.5);
    glVertex3f(1.5, -2.5, 0.5);
    glVertex3f(1.5, -1.5, -0.5);
    glVertex3f(1.5, -1.5, 0.5);
    glVertex3f(1.5, -0.5, -0.5);
    glVertex3f(1.5, -0.5, 0.5);
    glVertex3f(1.5, 0.5, -0.5);
    glVertex3f(1.5, 0.5, 0.5);
    glVertex3f(1.5, 1.5, -0.5);
    glVertex3f(1.5, 1.5, 0.5);
    glVertex3f(1.5, 2.5, -0.5);
    glVertex3f(1.5, 2.5, 0.5);
    glVertex3f(1.5, 3.5, -0.5);
    glVertex3f(1.5, 3.5, 0.5);
    glEnd();
    //left side panel
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(-1.5, -3.5, 0.5);
    glVertex3f(-1.5, -3.5, -0.5);
    glVertex3f(-1.5, -2.5, 0.5);
    glVertex3f(-1.5, -2.5, -0.5);
    glVertex3f(-1.5, -1.5, 0.5);
    glVertex3f(-1.5, -1.5, -0.5);
    glVertex3f(-1.5, -0.5, 0.5);
    glVertex3f(-1.5, -0.5, -0.5);
    glVertex3f(-1.5, 0.5, 0.5);
    glVertex3f(-1.5, 0.5, -0.5);
    glVertex3f(-1.5, 1.5, 0.5);
    glVertex3f(-1.5, 1.5, -0.5);
    glVertex3f(-1.5, 2.5, 0.5);
    glVertex3f(-1.5, 2.5, -0.5);
    glVertex3f(-1.5, 3.5, 0.5);
    glVertex3f(-1.5, 3.5, -0.5);
    glEnd();
    glPopMatrix();
}

void Car::drawStrips() {
    glPushMatrix();
    glColor3ub(70, 85, 95);	//Tecnico Grey
    GLfloat amb[]={0.44f,0.49f,0.48f,1.0f};
    GLfloat diff[]={0.4f,0.44f,0.5f,1.0f};
    GLfloat spec[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat shine=128;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    
    glTranslated(0, 0, (1.25*sin(60*M_PI/180))+0.02 + 0.5);
    //left
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.75, 3.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.1, 3.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.75, 2.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.1, 2.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.75, 1.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.1, 1.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.75, 0.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.1, 0.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.75, -0.5, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.1, -0.5, 0);
    glEnd();
    //right
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.75, 3.5, 0);
    glVertex3f(1.1, 3.5, 0);
    glVertex3f(0.75, 2.5, 0);
    glVertex3f(1.1, 2.5, 0);
    glVertex3f(0.75, 1.5, 0);
    glVertex3f(1.1, 1.5, 0);
    glVertex3f(0.75, 0.5, 0);
    glVertex3f(1.1, 0.5, 0);
    glVertex3f(0.75, -0.5, 0);
    glVertex3f(1.1, -0.5, 0);
    glEnd();
    glPopMatrix();
}

void Car::drawCage() {
    glPushMatrix();
    glColor3ub(70, 85, 95);	//Tecnico Grey
    GLfloat amb1[]={1,0.2f,0.2f,1.0f};
    GLfloat diff1[]={1.0f,0.1f,0.1f,1.0f};
    GLfloat spec1[]={1.0f,0.1f,0.1f,1.0f};
    GLfloat shine=24;
    glTranslated(0, 0, (1.25*sin(60*M_PI/180))+0.02 + 0.5);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb1);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff1);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec1);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    glBegin(GL_LINES);
    glVertex3f(0, -3.5, 0);
    glVertex3f(0, -4.2, 0.3);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(1.5, -0.5, 0);
    glVertex3f(2.2, -0.8, 0.3);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.6, -0.5, 1);
    glVertex3f(0.7, -0.6, 1.7);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.6, -0.5, 1);
    glVertex3f(-0.7, -0.6, 1.7);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.5, -0.5, 0);
    glVertex3f(-2.2, -0.8, 0.3);
    glEnd();
    GLfloat amb[]={0.21f,0.21f,0.21f,1.0f};
    GLfloat diff[]={0.18f,0.18f,0.18f,1.0f};
    GLfloat spec[]={0.14f,0.14f,0.14f,1.0f};
    /*GLfloat amb[]={0.29f,0.29f,0.29f,1.0f};
     GLfloat diff[]={0.51f,0.51f,0.51f,1.0f};
     GLfloat spec[]={0.19f,0.18f,0.17f,1.0f};
     GLfloat shine=76.8f;*/
    
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, -0.7, 0.3);
    glVertex3f(0, -3.5, 0);
    
    glNormal3f(0.7, -0.3, 0.3);
    glVertex3f(1.5, -0.5, 0);
    
    glNormal3f(0.1, -0.1, 0.7);
    glVertex3f(0.6, -0.5, 1);
    
    glNormal3f(-0.1, -0.1, 0.7);
    glVertex3f(-0.6, -0.5, 1);
    
    glNormal3f(-0.7, -0.3, 0.3);
    glVertex3f(-1.5, -0.5, 0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, -0.5, 0);
    glVertex3f(0, -0.5, 1);
    glVertex3f(0.6, -0.5, 1);
    glVertex3f(1.5, -0.5, 0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, -0.5, 0);
    glVertex3f(-1.5, -0.5, 0);
    glVertex3f(0.6, -0.5, 1);
    glVertex3f(0, -0.5, 1);
    glEnd();
    glPopMatrix();
}

void Car::setLives(double lives) {
    _lives = lives;
}

double Car::getLives() {
    return _lives;
}

void Car::die(){
    _lives -= 1;
}



