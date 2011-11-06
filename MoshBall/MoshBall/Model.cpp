//
//  Model.cpp
//  MoshBall
//
//  Created by Philip Dougherty on 11/6/11.
//  Copyright 2011 UW Madison. All rights reserved.
//

#include "Model.h"
time_t Model::currTime;

void Model::updateTime()
{
    time(&currTime);
}