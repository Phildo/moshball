//
//  Arrow.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/13/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Arrow.h"

bool Arrow::compiled;
GLuint Arrow::displayList;

Arrow::Arrow()
{
	if(!Arrow::compiled) {
        setColor(0.0, 0.0, 1.0, 1.0, 0.5, 1.0, 1.0);
        Arrow::compileDL();
    }
}

Arrow::~Arrow()
{
}

void Arrow::compileDL()
{
    if(Arrow::compiled) return;
    Arrow::displayList = glGenLists(1);
    glNewList(Arrow::displayList, GL_COMPILE);
    glPushMatrix();
        setGLColor();
        glPushMatrix();
            glRotated(90, 1.0, 0.0, 0.0);
            glutSolidTorus(20, 310, 100, 100);
        glPopMatrix();
        glRotated(90.0, 0.0, 0.0, 1.0);
        gluCylinder(gluNewQuadric(), 20, 20, 300, 4, 1);
            glPushMatrix();
            glPopMatrix(); 
    glPopMatrix();
    glEndList();
    Arrow::compiled = true;
}

void Arrow::draw()
{
    if(!Arrow::compiled) return;
    glPushMatrix();
        double angleOfDir = acos(Model::player->dir.dot(Model::SouthVect))*(180/3.14159);
        if(Model::player->dir[0] < 0) angleOfDir= 360-angleOfDir; 
        glTranslated(ARENA_WIDTH/2+400, 0.0, 0.0);
        glRotated(angleOfDir, 0.0, 1.0, 0.0);
        glCallList(Arrow::displayList);
    glPopMatrix();
}