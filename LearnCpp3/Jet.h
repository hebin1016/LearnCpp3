#pragma once
//
//  Jet.h
//  LearnCpp3
//
//  Created by hebin on 2017/2/11.
//  Copyright © 2017年 hebin. All rights reserved.
//

#ifndef Jet_h
#define Jet_h


#endif /* Jet_h */

#include "Plane.h"


//普通飞机
class Jet:public Plane{
public:
    virtual void fly();
    virtual void land();
};

