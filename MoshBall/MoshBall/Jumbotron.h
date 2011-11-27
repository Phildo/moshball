//
//  Jumbotron.h
//  MoshBall
//
//  Created by Philip Dougherty on 10/30/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#ifndef JUMBOTRON_H
#define JUMBOTRON_H

#include "Model.h"
#include "DrawableGeometry.h"

class Jumbotron: public DrawableGeometry
{
public:
    Jumbotron();
    ~Jumbotron();
    
    void compileDL();
    void draw();
    
protected:
    static bool compiled;
    static GLuint displayList;
};

#endif