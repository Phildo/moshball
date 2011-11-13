//
//  Player.h
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	PLAYER_H
#define	PLAYER_H
#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "Model.h"
#include "VectorLib/Vectors.h"
#include "Movable.h"
#include "DrawableGeometry.h"

class Player: public Movable, public DrawableGeometry
{
public:    
	Player();
    ~Player();
    
    void compileDL(); 
    void draw();
    void drawAtPosition();
    
protected:
    static bool compiled;
    static GLuint displayList;
};

#endif
