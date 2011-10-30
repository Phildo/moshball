//
//  Arena.h
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	ARENA_H
#define	ARENA_H

#define ARENA_WIDTH  5280
#define ARENA_LENGTH 5280
#define ARENA_HEIGHT 100

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "VectorLib/Vectors.h"

class Arena
{
public:    
	Arena();
    ~Arena();

    void compile();
	void draw();
    
protected:
    static GLuint arenaList;
    static bool compiled;
};

#endif
