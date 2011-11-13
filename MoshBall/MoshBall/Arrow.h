//
//  Arrow.h
//  MoshBall
//
//  Created by Philip Dougherty on 11/13/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef ARROW_H
#define ARROW_H

#include "Model.h"
#include "DrawableGeometry.h"

class Arrow: public DrawableGeometry
{
public:
    Arrow();
    ~Arrow();
    
    void compileDL();
    void draw();
    
protected:
    static bool compiled;
    static GLuint displayList;
};

#endif