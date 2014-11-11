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
using namespace std;

struct orderLine{
    std::string client_name;
    std::string buyOrSell;
    std::string equitySymbol;
    unsigned int timestamp;
    unsigned int price;
    unsigned int quantity;
    unsigned int position;
    
};
struct pr{
    unsigned int random_seed;
    unsigned int numOfOrders;
    char lastClient;
    char lastEquity;
    double arrivalRate;
    unsigned int ID;
    double timestamp;
};
struct orderLinePR{
    static unsigned int pos;
    static double timestamp;
    mt19937 gen;
    uniform_int_distribution<char> clients;
    uniform_int_distribution<char> equities;
    exponential_distribution<double> arrivals;
    bernoulli_distribution buy_or_sell;
    uniform_int_distribution<int> price;
    uniform_int_distribution<int> quantity;
    orderLinePR(pr &op);
    orderLine* order();
    orderLinePR();
    
};

orderLine * orderLineRead(int);
orderLinePR orderLineReadPR(int& );

#endif /* defined(__proj3__readInLines__) */