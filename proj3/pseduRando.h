//
//  pseduRando.h
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__pseduRando__
#define __proj3__pseduRando__

#include <stdio.h>
#include "orderLine.h"
#include <random>

class pseduRando{
public:
    std::mt19937 gen;
    std::uniform_int_distribution<char> clients;
    std::uniform_int_distribution<char> equities;
    std::exponential_distribution<> arrivals;
    std::bernoulli_distribution buy_or_sell;
    std::uniform_int_distribution<> price;
    std::uniform_int_distribution<> quantity;
    static unsigned int ID;
    static double timeStamp;
    pseduRando(orderLinePR & op);
    orderLine order();
};

#endif /* defined(__proj3__pseduRando__) */
