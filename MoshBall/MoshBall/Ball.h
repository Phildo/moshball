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
#include "Player.h"
#include "VectorLib/Vectors.h"
#include "Movable.h"
#include "DrawableGeometry.h"
#include "Timer.h"

class Player;

class Ball: public Movable, public DrawableGeometry
{
public:    
	Ball();
    ~Ball();
   
    void compileDL();
    void draw();
    void drawAtPosition();
    
    void hit();
    void unhit();
    
    void updateTime();
    void displayTimer();
    
    bool checkCollisionWithPlayer(Player * p);
    
protected:
    bool active;
    double timeLeft;
    time_t timeHit;
    Timer timerDisp;
    
    static bool compiled;
    static GLuint displayList;
};

#endif
