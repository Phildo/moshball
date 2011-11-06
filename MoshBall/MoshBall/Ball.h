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
#include <time.h>
#include "Model.h"
#include "VectorLib/Vectors.h"
#include "Timer.h"

class Ball
{
public:    
	Ball();
    ~Ball();
    
    void setPos(const Vector2 & newPos);
    Vector2 getPos();
    
    void hit();
    void unhit();
    void updateTime();
    void setColor(const Vector3 & color);
    
    void compile();
	void draw();
    void displayTimer();
    
protected:
    static GLuint ballList;
    static bool compiled;
    
    Vector2 pos;
    bool active;
    double timeLeft;
    time_t timeHit;
    Timer timerDisp;
    
    Vector3 color;
    GLfloat specular[4];
    GLfloat ambient[4];
    GLfloat diffuse[4];
};

#endif
