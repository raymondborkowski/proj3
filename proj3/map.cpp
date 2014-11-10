//
//  map.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/9/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "map.h"

void flagOptions::printMedian(int x){
    for(auto med : medianSet) {
        std::cout<<"Median match price of " << med << " at time "<< x << " is $" << medianMap[med].getMedian()<< '\n';
    }
}

//I need to set max and min prio queues
void getMedian(){
    medianT op;
    prioQueue pp;
    int x = pp.maxQueue.top() + pp.minQueue.top();
    switch(op.span){
            // Return median Type
        case 1:
            op.median = pp.maxQueue.top();
        case -1:
            op.median = pp.minQueue.top();
        default:
            op.median = x/2;
    }
}
//Recheck this before submit
void insertMedian(int i){
    prioQueue pp;
    medianT op;
    if(i < op.median || op.span == -1) {
        op.span++;
        pp.maxQueue.push(i);
    }
    else {
        op.span--;
        pp.minQueue.push(i);
    }
    if(op.span < -1 || op.span > 1) {
        if(op.span < -1) {
            pp.maxQueue.push(pp.minQueue.top());
            pp.minQueue.pop();
            op.span = 0;
        }
        else{
            pp.minQueue.push(pp.maxQueue.top());
            pp.maxQueue.pop();
            op.span = 0;
        }
    }
    getMedian();
}
void equityT::insertEq(orderLine newOrder){
    if(newOrder.buyOrSell == "BUY") {
        buy.push(&newOrder);
        
        if(blimit < newOrder.price)
            blimit = newOrder.price;
    }
    else {
        sell.push(&newOrder);
        if(slimit > newOrder.price)
            slimit = newOrder.price;
    }
}
void flagOptions::insertDistribution(orderLine newOrder){
    string company = newOrder.equitySymbol;
    string name = newOrder.client_name;
    if(eqMap.count(company))
        eqMap[company].insertEq(newOrder);
    else{
        equityT* temp = new equityT();
        temp->insertEq(newOrder);
        eqMap.insert(pair<string, equityT>(company, *temp));
        medianMap[company];
    }
}