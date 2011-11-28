//
//  Movable.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/12/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Movable.h"

Movable::Movable()
{
    pos.set(0.0,0.0,0.0);
    dir.set(0.0,0.0,-1.0);
}

Movable::~Movable()
{
    
}

void Movable::updatePos(double timePassed)
{
    pos+=(dir*(vel*timePassed));
}

void Movable::hit()
{
    //Do nothing
}