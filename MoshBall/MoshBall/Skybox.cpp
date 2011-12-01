//
//  Skybox.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Skybox.h"

bool Skybox::compiled;
GLuint Skybox::displayList;

Skybox::Skybox()
{
	if(!Skybox::compiled) {
        Skybox::compileDL();
    }
}

Skybox::~Skybox()
{
    
}

void Skybox::compileDL()
{
    if(Skybox::compiled) return;
    Skybox::displayList = glGenLists(1);
    glNewList(Skybox::displayList, GL_COMPILE);
    
    
    glBegin(GL_QUADS);
    
    //Ceiling
    glNormal3d(0.0, 1.0, 0.0);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    
    //West Wall
    glNormal3d(1.0, 0.0, 0.0);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.6*ARENA_LENGTH);
    
    //East Wall
    glNormal3d(-1.0, 0.0, 0.0);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.6*ARENA_LENGTH);
    
    //North Wall
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.6*ARENA_LENGTH);
    
    //South Wall
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3d(-.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, .6*ARENA_LENGTH);
    glVertex3d(-.6*ARENA_WIDTH, -.5*ARENA_HEIGHT, .6*ARENA_LENGTH);
    
    glEnd();
    glEndList();
    Skybox::compiled = true;
}

void Skybox::draw()
{
    if(!Skybox::compiled) return;
    glCallList(Skybox::displayList);
}