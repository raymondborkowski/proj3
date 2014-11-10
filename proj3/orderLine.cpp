//
//  readInLines.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "orderLine.h"
#include <string>

orderLine orderLineRead(int x){
    orderLine orderOp;
    std::string temp, temp1, temp2, temp3;
    char tempChar1, tempChar2;
    int intTemp1,intTemp3, intTemp4;
    intTemp1 = x;
    std::cin>>temp1;
    std::cin>>temp2;
    std::cin>>temp3;
    std::cin>>tempChar1;
    if(tempChar1 != '$')
        exit(1);
    std::cin>>temp;
    intTemp3 = stoi(temp);
    std::cin>>tempChar2;
    if(tempChar2 !='#')
        exit(1);
    std::cin>>temp;
    intTemp4 = stoi(temp);
    errorCheck(intTemp1, tempChar1, intTemp3, tempChar2, intTemp4, temp2, temp1, temp3);
    
    orderOp.timestamp = intTemp1;
    orderOp.client_name = temp1;
    orderOp.buyOrSell = temp2;
    orderOp.equitySymbol = temp3;
    orderOp.price = intTemp3;
    orderOp.quantity = intTemp4;
    
    orderLine * pp = new orderLine;
    *pp = orderOp;
    
    return *pp;
}
orderLinePR orderLineReadPR(){
    pr orderOp;
    std::string inputPr;
    double j;
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    orderOp.random_seed = stoi(inputPr);
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    orderOp.numOfOrders = stoi(inputPr);
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    if(inputPr.length() > 1)
        exit(1);
    isAlpha(inputPr[0]);
    orderOp.lastClient = inputPr[0];
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    if(inputPr.length() > 1)
        exit(1);
    isAlpha1(inputPr[0]);
    orderOp.lastEquity = inputPr[0];
    
    std::cin>>inputPr;
    std::cin>>inputPr;
    j = std::stod(inputPr);
    orderOp.arrivalRate = j;
    
    orderLinePR pp(orderOp);
    
    return pp;
}