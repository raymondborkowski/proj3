//
//  pseduRando.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "orderLine.h"
/////////////////////////////////////////////////////////////
//PSEDU FROM SPEC
/////////////////////////////////////////////////////////////


orderLinePR::orderLinePR(pr &op) : gen(op.random_seed),
clients('a', op.lastClient), equities('A', op.lastEquity),
arrivals(op.arrivalRate), price(2,11), quantity(1,30) {}

unsigned int orderLinePR::ID = 0;
double orderLinePR::timestamp = 0;

orderLine orderLinePR::order() {
    orderLine op = *new orderLine;
    op.timestamp = orderLinePR::timestamp;
    orderLinePR::timestamp += floor(arrivals(gen) + .5);
    op.client_name = std::string("C_") + clients(gen);
    //Range of possible client names is thus 'C_a' to 'C_z'.
    op.buyOrSell = (buy_or_sell(gen) ? "BUY" : "SELL");
    op.equitySymbol = std::string("E_") + equities(gen);
    op.price = 5 * price(gen); //10-55
    op.quantity = quantity(gen); //1-30

    return op;
}
orderLinePR::orderLinePR() {}