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

orderLine* orderLinePR::order() {
    
    orderLine* op = new orderLine;
    //TIMESTAMP := GENERATOR_TIMESTAMP
    op->timestamp = timestamp;
    //GENERATOR_TIMESTAMP := GENERATOR_TIMESTAMP + floor(arrivals(gen) + .5)
    timestamp += floor(arrivals(gen) + .5);
    //CLIENT_NAME := string("C_") + clients(gen)
    //Range of possible client names is thus 'C_a' to 'C_z'.
    op->client_name = std::string("C_") + clients(gen);
    //Range of possible client names is thus 'C_a' to 'C_z'.
    //Range of possible equity names is thus "E_A" to "E_Z".
    //BUY_OR_SELL := (buy_or_sell(gen) ? BUY : SELL)
    op->buyOrSell = (buy_or_sell(gen) ? "BUY" : "SELL");
    //EQUITY_SYMBOL := string("E_") + equities(gen)
    op->equitySymbol = std::string("E_") + equities(gen);
    //PRICE := 5 * price(gen) // $10 ­ $55
    op->price = 5 * price(gen); //10-55
    //QUANTITY := quantity(gen) // 1 ­ 30
    op->quantity = quantity(gen); //1-30
    op->position = pos++;
    return op;
}