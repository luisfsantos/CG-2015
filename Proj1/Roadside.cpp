//
//  Roadside.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Roadside.hpp"
#include "Orange.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#define TABLE "/Users/luissantos/Documents/IST/3ano/CG/Proj1/Proj1/Lwood.jpg"
#else
#define TABLE "..\\Proj1\\Lwood.jpg"
#endif
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int colors[6][3] = {
    {255, 255, 194},
    {204, 102, 255},
    {178, 204, 255},
    {255, 132, 132},
    {194, 255, 173},
    {255, 194, 133}
};

Roadside::Roadside() {
    
}

Roadside::Roadside(double positions[][3], int size, double x, double y, double z) {
    _position.set(x, y, z);
    initTableTexture(TABLE);
    for (int i=0; i<size; i++) {
        _cherrios.push_back(new Cherrio(positions[i][0]+x, positions[i][1]+y, positions[i][2]+z, 2.4, 4));
    }
}

Roadside::~Roadside() {
    
}

void Roadside::reset(double positions[][3], int size, double x, double y, double z) {
    _cherrios.clear();
    for (int i=0; i<size; i++) {
        _cherrios.push_back(new Cherrio(positions[i][0]+x, positions[i][1]+y, positions[i][2]+z, 2.4, 4));
    }
}

void Roadside::draw() {
    std::vector<Cherrio*>::iterator iter;
    drawTable3();
    glPushMatrix();
    //glTranslatef(_position.getX(), _position.getY(), _position.getZ());
    for ( iter = _cherrios.begin() ; iter != _cherrios.end(); ++iter){
        (*iter)->draw();
    }
    glPopMatrix();
    
}

void Roadside::drawTable() {
    /* comment the material*/
    GLfloat amb[]={0.1f,0.1f,0.1f,1.0f};
    GLfloat diff[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat shine=10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /* comment the material*/
    bool color = true;
    int w=1280, h=720, n=10, m=5;
    int sw = w/n, sh = h/m; //square width and height respectively
    //for each width and eight draw a rectangle with a specific color
    glPushMatrix();
    glColor3ub(234,234,234);
    glTranslated(w/2,h/2, -10);
    glScaled(w, h, 20);
    glRotated(0, 0, 0, 0);
    glutSolidCube(1);
    glPopMatrix();   
}

void Roadside::initTableTexture(const char *filename) {
    int imagex = 0, imagey = 0, imagen = 0;
    unsigned char *data = stbi_load(filename, &imagex, &imagey, &imagen, 0);
    
    glGenTextures( 1, &_TableTexture );
    glBindTexture( GL_TEXTURE_2D, _TableTexture );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, imagex, imagey, GL_RGB, GL_UNSIGNED_BYTE, data );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    
    free( data );

}


void Roadside::drawTable2() {
    /* comment the material*/
    GLfloat amb[]={0.1f,0.1f,0.1f,1.0f};
    GLfloat diff[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat shine=10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /* comment the material*/
    bool color = true;
    float x=0, y=0, z = 0;
    int w=1280, h=720, xxx=50;
    double hw = h/xxx;
    double ww = w/xxx;
    glPushMatrix();
    glColor3ub(234,234,234);
    //glTranslated(w/2,h/2, 0);
    //glScaled(w, h, 20);
    
    for (y=0; y <= h; y += hw) {
        glBegin(GL_QUADS);
        
        for (x=0; x<=w+ww; x += ww) {
            glNormal3f(0, 0, 1);
            glVertex3f(x, y, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x, y+hw, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y+hw, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y, z);
            
        }
        glEnd();
    }
    glPopMatrix();
}

void Roadside::drawTable3() {
    /* comment the material */
    GLfloat amb[]={0.4f,0.4f,0.4f,1.0f};
    GLfloat diff[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat shine=10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /*comment the material*/
    bool color = true;
    float x=0, y=0, z = 0;
    int w=1280, h=720, xxx=50;
    double hw = 5;// h/xxx;
    double ww = 5;//w/xxx;
    double texX = 0;
    double texY = 0;
    double tex = 1/(256/hw);
    glColor3ub(245, 245, 245);
    glPushMatrix();
    glBindTexture( GL_TEXTURE_2D, _TableTexture );
    for (y=0; y <= h; y += hw) {
        glBegin(GL_QUADS);
        
        for (x=0; x<=w - ww; x += ww) {
            glTexCoord2f(texX, texY);
            glNormal3f(0, 0, 1);
            glVertex3f(x, y, z);
            glTexCoord2f(texX, texY+tex);
            glNormal3f(0, 0, 1);
            glVertex3f(x, y+hw, z);
            glTexCoord2f(texX+tex, texY+tex);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y+hw, z);
            glTexCoord2f(texX+tex , texY);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y, z);
            
            (texX<1.0) ? texX += tex : texX = 0;
        }
        (texY<1.0) ? texY += tex : texY = 0;
        glEnd();
    }
    glPopMatrix();
}

bool Roadside::isIntersecting(GameObject orange) {
    bool test1 = false, test2 = false;
    test1 = (orange.getPosition()->getX() + orange.getHalfWidth() < 0
            ||
			orange.getPosition()->getX() - orange.getHalfHeight() > 1280);
    test2 = (orange.getPosition()->getY() + orange.getHalfWidth() < 0
            ||
			orange.getPosition()->getY() - orange.getHalfHeight() > 720);
    return test1 || test2;
}

std::vector<Cherrio*> Roadside::getCherrios() {
    return _cherrios;
}

