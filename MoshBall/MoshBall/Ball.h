//
//  Ball.h
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	BALL_H
#define	BALL_H
#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "VectorLib/Vectors.h"

class Ball
{
public:    
	Ball();
    ~Ball();
    
    void setPos(const Vector2 & newPos);
    Vector2 getPos();
    
    void hit();
    void setColor(const Vector3 & color);
    
    void compile();
	void draw();
    
protected:
    static GLuint ballList;
    static bool compiled;
    Vector2 pos;
    bool active;
    
    Vector3 color;
    GLfloat specular[4];
    GLfloat ambient[4];
    GLfloat diffuse[4];
};

#endif
