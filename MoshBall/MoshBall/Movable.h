//
//  Movable.h
//  MoshBall
//
//  Created by Philip Dougherty on 11/12/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	MOVABLE_H
#define	MOVABLE_H

#include <math.h>
#include "VectorLib/Vectors.h"

class Movable
{
public:
    Movable();
    virtual ~Movable();
    
    Vector3 pos;    //x,y,z
    Vector3 dir;    //x,y,z- SHOULD BE KEPT NORMALIZED
    double vel;     //rate at which position changes in direction 'dir'
    
    //Adds dir*vel*timePassed to pos (updates 'pos' in 'dir' direction by amount 'vel')
    virtual void updatePos(double timePassed);
    
    virtual void hit();
};

#endif