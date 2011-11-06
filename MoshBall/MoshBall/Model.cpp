//
//  Model.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/6/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Model.h"
time_t Model::currTime;
Vector2 Model::NorthVect;
Vector2 Model::SouthVect;
Vector2 Model::WestVect;
Vector2 Model::EastVect;

void Model::setUpModel()
{
    NorthVect.set(0, -1);
    SouthVect.set(0, 1);
    WestVect.set(-1, 0);
    EastVect.set(1, 0);
}

void Model::updateTime()
{
    time(&currTime);
}