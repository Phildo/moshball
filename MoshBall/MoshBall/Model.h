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

#define COMPASS_DISTANCE 3750
#define HUD_WIDTH COMPASS_DISTANCE*2+100
#define HUD_HEIGHT COMPASS_DISTANCE*2+100

#define NUM_MODES 2
#define NUM_BALLS 5
#define SEED 0

#define MOVEMENT_TOLERANCE .025
#define SPEED 100
#define ROT_SPEED 10

#define BALL_RADIUS 50
#define FULL_TIME (30+(NUM_BALLS*2))
#include <time.h>
#include "VectorLib/Vectors.h"
#include "Player.h"
#include "Ball.h"
#include "Arena.h"
#include "Arrow.h"
#include "highprecisiontime.h"

class Player;
class Ball;
class Arena;
class Arrow;

class Model{
public:
    
    static HighPrecisionTime *hTime;
    
    static Player *player;
    static Ball **balls;
    static Arena *arena;
    static Arrow *compass;
    
    static time_t currTime;
    static Vector3 UpVect;
    static Vector3 DownVect;
    static Vector3 NorthVect;
    static Vector3 SouthVect;
    static Vector3 WestVect;
    static Vector3 EastVect;
    
    static void setUpModel();
    static void updateTime();
};

#endif
