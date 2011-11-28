//
//  Jumbotron.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Jumbotron.h"

bool Jumbotron::compiled;
GLuint Jumbotron::displayList;

Jumbotron::Jumbotron()
{
	if(!Jumbotron::compiled) {
        setColor(1.0, 0.5, 0.5, 1.0, 0.25, 0.25, 0.5);
        Jumbotron::compileDL();
    }
}

Jumbotron::~Jumbotron()
{
}

#define J_WIDTH 300
#define J_HEIGHT 200
#define J_THICK 40
void Jumbotron::compileDL()
{
    if(Jumbotron::compiled) return;
    Jumbotron::displayList = glGenLists(1);
    glNewList(Jumbotron::displayList, GL_COMPILE);
    glPushMatrix();
    setGLColor();
    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(0.0, 0.0, -300.0);
    gluCylinder(gluNewQuadric(), 20, 20, 300, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 300, 0);
    glBegin(GL_TRIANGLES);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);

    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    glVertex3d(-.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, -.5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(-.5*J_WIDTH, .5*J_HEIGHT, -.5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(-.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    glVertex3d(-.5*J_WIDTH, .5*J_HEIGHT, -.5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(-.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, -.5*J_THICK);
    
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, .5*J_HEIGHT, .5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, -.5*J_THICK);
    glVertex3d(-.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);
    glVertex3d(.5*J_WIDTH, -.5*J_HEIGHT, .5*J_THICK);

    glEnd();
    glPopMatrix();
    
    glEndList();
    Jumbotron::compiled = true;
}

void Jumbotron::draw()
{
    if(!Jumbotron::compiled) return;
    glCallList(Jumbotron::displayList);
}