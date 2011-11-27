//
//  Collision.h
//  MoshBall
//
//  Created by Philip Dougherty on 11/20/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef H_COLLISION
#define H_COLLISION
#include "Movable.h"

class Collision
{
public:
    Collision();
    ~Collision();
    
    Movable *a;
    Movable *b;
    double timePassed;
};
#endif