//
//  readInLines.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "orderLine.h"
#include "pseduRando.h"
#include <string>

orderLine orderLineRead(){
    orderLine * orderOp;
    std::string temp;
    char tempChar;
    unsigned int intTemp;
    
    std::cin>>temp;
    intTemp = stoi(temp);
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
    intTemp = 1;
    errorCheckPrice(tempChar, intTemp);
    std::cin>>temp;
    intTemp = stoi(temp);
    errorCheckPrice(tempChar, intTemp);
    orderOp->price = intTemp;
    
    std::cin>>tempChar;
    std::cin>>temp;
    intTemp = stoi(temp);
    errorCheckQuantity(tempChar, intTemp);
    orderOp->quantity = intTemp;
    
    
    return *orderOp;
}
orderLinePR orderLineReadPR(){
    orderLinePR * orderOp;
    std::string inputPr;
    double j;
    char i;
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    orderOp->random_seed = stoi(inputPr);

    std::cin>>inputPr;
    std::cin>>inputPr;
    orderOp->numOfOrders = stoi(inputPr);
    
    std::cin>>inputPr;
    std::cin>>i;
    isAlpha(i);
    orderOp->lastClient = i;
    
    std::cin>>inputPr;
    std::cin>>i;
    isAlpha(i);
    orderOp->lastEquity = i;
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    j = std::stod(inputPr);
    orderOp->arrivalRate = j;
    
    orderLinePR op(*orderOp);

    
    return *orderOp;
}