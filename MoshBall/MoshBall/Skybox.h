//
//  Skybox.h
//  MoshBall
//
//  Created by Philip Dougherty on 11/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#ifndef SKYBOX_H
#define SKYBOX_H

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "Model.h"
#include "DrawableGeometry.h"

class Skybox: public DrawableGeometry
{
public:
    Skybox();
    ~Skybox();
    
    void compileDL();
    void draw();
    
protected:
    static bool compiled;
    static GLuint displayList;

};

#endif