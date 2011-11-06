//
//  Model.h
//  MoshBall
//
//  Created by Philip Dougherty on 11/6/11.
//  Copyright 2011 UW Madison. All rights reserved.
//
#ifndef	MODEL_H
#define	MODEL_H

#define ARENA_WIDTH  5280
#define ARENA_LENGTH 5280
#define ARENA_HEIGHT 100

#define NUM_MODES 2
#define NUM_BALLS 100
#define SEED 0

#define BALL_RADIUS 50
#define FULL_TIME (30+(NUM_BALLS*2))
#include <time.h>
#include "VectorLib/Vectors.h"

class Model{
    public:
    static time_t currTime;
    static Vector2 NorthVect;
    static Vector2 SouthVect;
    static Vector2 WestVect;
    static Vector2 EastVect;
    
    static void setUpModel();
    static void updateTime();
};

#endif
