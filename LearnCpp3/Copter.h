//
//  Copter.h
//  LearnCpp3
//
//  Created by hebin on 2017/2/11.
//  Copyright © 2017年 hebin. All rights reserved.
//

#ifndef Copter_h
#define Copter_h


#endif /* Copter_h */

#include "Plane.h"

//普通飞机
class Copter:public Plane{
public:
    virtual void fly();
    virtual void land();
};
