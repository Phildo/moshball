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
        setColor(1.0, 0.0, 1.0, 1.0, 0.5, 1.0, 1.0);
        Jumbotron::compileDL();
    }
}

Jumbotron::~Jumbotron()
{
}

void Jumbotron::compileDL()
{
    if(Jumbotron::compiled) return;
    Jumbotron::displayList = glGenLists(1);
    glNewList(Jumbotron::displayList, GL_COMPILE);
    glPushMatrix();
    setGLColor();
    glPushMatrix();
    glRotated(90, 1.0, 0.0, 0.0);
    glutSolidTorus(20, 310, 100, 100);
    glPopMatrix();
    glRotated(90.0, 0.0, 0.0, 1.0);
    gluCylinder(gluNewQuadric(), 20, 20, 300, 4, 1);
    glPopMatrix();
    glEndList();
    Jumbotron::compiled = true;
}

void Jumbotron::draw()
{
    if(!Jumbotron::compiled) return;
    glPushMatrix();
    double angleOfDir = acos(Model::player->dir.dot(Model::SouthVect))*(180/3.14159);
    if(Model::player->dir[0] < 0) angleOfDir= 360-angleOfDir; 
    glTranslated(ARENA_WIDTH/2+400, 0.0, 0.0);
    glRotated(angleOfDir, 0.0, 1.0, 0.0);
    glCallList(Jumbotron::displayList);
    glPopMatrix();
}