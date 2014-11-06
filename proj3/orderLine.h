//
//  readInLines.h
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__readInLines__
#define __proj3__readInLines__

#include <stdio.h>
#include "errorChecking.h"
#include <random>

struct orderLine{
    std::string client_name;
    std::string buyOrSell;
    std::string equitySymbol;
    unsigned int timestamp = 0;
    unsigned int price = 0;
    unsigned int quantity = 0;
    unsigned int position = 0;
    
};
struct orderLinePR{
    unsigned int random_seed;
    unsigned int numOfOrders;
    char lastClient;
    char lastEquity;
    double arrivalRate;
    static unsigned int ID;
    static double timestamp;
    
    std::mt19937 gen;
    std::uniform_int_distribution<char> clients;
    std::uniform_int_distribution<char> equities;
    std::exponential_distribution<> arrivals;
    std::bernoulli_distribution buy_or_sell;
    std::uniform_int_distribution<> price;
    std::uniform_int_distribution<> quantity;
    orderLinePR(orderLinePR & op);
    orderLine order();
    orderLinePR();
    
};

orderLine orderLineRead();
orderLinePR orderLineReadPR();

#endif /* defined(__proj3__readInLines__) */
