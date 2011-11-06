//
//  Arena.h
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	ARENA_H
#define	ARENA_H

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "Model.h"
#include "VectorLib/Vectors.h"

class Arena
{
public:    
	Arena();
    ~Arena();

    double getWidth();
    double getLength();
    
    void compile();
	void draw();
    
protected:
    static GLuint arenaList;
    static bool compiled;
};

#endif
