//
//  readInLines.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "orderLine.h"

orderLine orderLineRead(){
    orderLine * orderOp = new orderLine;
    std::string temp;
    char tempChar;
    unsigned int intTemp;
    
    std::cin>>intTemp;
    errorCheckTimestamp(intTemp);
    orderOp->timestamp = intTemp;
    
    std::cin>>temp;
    errorCheckClient(temp);
    orderOp->client_name = temp;

    std::cin>>temp;
    errorCheckBuyOrSell(temp);
    orderOp->buyOrSell = temp;
    
    std::cin>>temp;
    errorCheckEquitySymbol(temp);
    orderOp->equitySymbol = temp;
    
    std::cin>>tempChar;
    std::cin>>intTemp;
    errorCheckPrice(tempChar, intTemp);
    orderOp->price = intTemp;
    
    std::cin>>tempChar;
    std::cin>>intTemp;
    errorCheckQuantity(tempChar, intTemp);
    orderOp->quantity = intTemp;
    
    
    return *orderOp;
}