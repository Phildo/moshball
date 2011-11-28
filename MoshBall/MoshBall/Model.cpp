//
//  Model.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/6/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Model.h"

Player * Model::player;
Arena * Model::arena;
Ball ** Model::balls;
Arrow * Model::compass;
Jumbotron * Model::jOne;
Jumbotron * Model::jTwo;

time_t Model::currTime;
Vector3 Model::UpVect;
Vector3 Model::DownVect;
Vector3 Model::NorthVect;
Vector3 Model::SouthVect;
Vector3 Model::WestVect;
Vector3 Model::EastVect;

void Model::setUpModel()
{
    arena = new Arena();
    player = new Player();
    balls = new Ball*[NUM_BALLS];
    compass = new Arrow();
    jOne = new Jumbotron();
    jTwo = new Jumbotron();
    
    UpVect.set   ( 0, 1, 0);
    DownVect.set ( 0,-1, 0);
    NorthVect.set( 0, 0,-1);
    SouthVect.set( 0, 0, 1);
    WestVect.set (-1, 0, 0);
    EastVect.set ( 1, 0, 0);
}

void Model::updateTime()
{
    time(&currTime);
}