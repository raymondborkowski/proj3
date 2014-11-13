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
    unsigned int pos = 0;
    double timestamp = 0;
    mt19937 gen;
    uniform_int_distribution<char> clients;
    uniform_int_distribution<char> equities;
    exponential_distribution<> arrivals;
    bernoulli_distribution buy_or_sell;
    uniform_int_distribution<> price;
    uniform_int_distribution<> quantity;
    orderLinePR(pr &x) : gen(x.random_seed),
    clients('a', x.lastClient), equities('A', x.lastEquity),
    arrivals(x.arrivalRate), price(2,11), quantity(1,30) {
        mt19937 gen;
        uniform_int_distribution<char> clients;
        uniform_int_distribution<char> equities;
        exponential_distribution<> arrivals;
        bernoulli_distribution buy_or_sell;
        uniform_int_distribution<> price;
        uniform_int_distribution<> quantity;
    }
    orderLine* order();
    orderLinePR(){};
    
};

orderLine * orderLineRead(int);
orderLinePR orderLineReadPR(int& );

#endif /* defined(__proj3__readInLines__) */