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

class Player
{
public:    
	Player();
    ~Player();
    
    void setPos(const Vector2 & newPos);
    Vector2 getPos();
    
    void setDir(const Vector2 & newDir);
    Vector2 getDir();
    
    void setVel(double newVel);
    double getVel();
    
    void updatePos(double elapsedTime);
    
    void setColor(const Vector3 & color);
    
    void compile();
	void draw();
    
protected:
    static GLuint playerList;
    static bool compiled;
    Vector2 pos;
    Vector2 dir;
    double vel;
    
    Vector3 color;
    GLfloat specular[4];
    GLfloat ambient[4];
    GLfloat diffuse[4];
};

#endif
