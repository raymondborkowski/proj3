//
//  map.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/9/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "map.h"

void flagOptions::printMedian(int x){
    for(auto it = medianSet.begin(); it != medianSet.end(); ++it) {
        cout<<"Median match price of " << *it << " at time "<< x << " is $" << medianMap[*it].getMedian()<< '\n';
    }
}
void flagOptions::printVerbose(orderLine* buyer, orderLine* seller, pair<int, int> xx){
    if(verbose==true)
        cout<<buyer->client_name<<" purchased "<<xx.first<<" shares of "<<buyer->equitySymbol<<" from "<<seller->client_name<<" for $"<<xx.second<<"share\n";
}
void insertTransfer(){
    
    
}
//I need to set max and min prio queues
void flagOptions::getMedians(priority_queue<int> maxQueue, priority_queue<int, vector<int>, greater<int>> minQueue){
    switch(span){
            // Return median Type
        case 1:
            median1 = maxQueue.top();
            break;
        case -1:
            median1 = minQueue.top();
            break;
        default:
            int x = maxQueue.top() + minQueue.top();
            median1 = x/2;
            break;
    }
    
}
//Recheck this before submit
void flagOptions::insertMedian(int i){
    int zero = 0;
    int one = 1;
    int negativeOne = -1;
    
    
    if(i < median1) {
        span++;
        maxQueue.push(i);
    }
    else if( i > median1) {
        span--;
        minQueue.push(i);
    }
    else if(span == negativeOne){
        span++;
        maxQueue.push(i);
    }
    else {
        span--;
        minQueue.push(i);
    }
    if(span < negativeOne) {
        if(span < negativeOne) {
            maxQueue.push(minQueue.top());
            minQueue.pop();
            span = zero;
        }
        else{
            minQueue.push(maxQueue.top());
            maxQueue.pop();
            span = zero;
        }
    }
    if(span > one){
        if(span < negativeOne) {
            maxQueue.push(minQueue.top());
            minQueue.pop();
            span = zero;
        }
        else{
            minQueue.push(maxQueue.top());
            maxQueue.pop();
            span = zero;
        }
    }
    getMedians(maxQueue, minQueue);
}
void equityT::insertEq(orderLine* newOrder){
    int price = newOrder->price;
    if(newOrder->buyOrSell == "BUY") {
        buy.push(newOrder);
        if(blimit < price)
            blimit = newOrder->price;
    }
    else {
        sell.push(newOrder);
        if(slimit > price)
            slimit = newOrder->price;
    }
}
bool isEmpty(pair<string, equityT*> op){
    if(op.second->empty() == true || op.first.empty() == true)
        return true;
    return false;
}
void flagOptions::insertDistribution(orderLine* newOrder){
    if(eqMap.count(newOrder->equitySymbol))
        eqMap[newOrder->equitySymbol]->insertEq(newOrder);
    else{
        equityT* temp = new equityT();
        temp->insertEq(newOrder);
        eqMap.insert(make_pair(newOrder->equitySymbol, temp));
        medianMap[newOrder->equitySymbol];
    }
}
void flagOptions::runThru(){
    int zero = 0;
    for(auto it : eqMap) {
        if(completeTrade(it) != zero) {
            last = it.first;
            if(median)
                medianSet.insert(it.first);
        }
      //  if(INSIDERS.count(it.first)) {
      //      insider_trading('S', it);
       //     insider_trading('B', it);
      //  }
    }
}

int flagOptions::completeTrade(pair<string, equityT*> op){

    int returnValue = 0;
    bool trueOrFalse = true;
    orderLine* buyer;
    int zero = 0;
    orderLine* seller;
    if(op.second->empty() == true || op.first.empty() == true){
        return returnValue;
    }
    while(trueOrFalse){
        trueOrFalse = false;
        if(op.second->blimit >= op.second->slimit){
            buyer = op.second->buy.top();
            seller = op.second->sell.top();
            pp.first = buyer->client_name;
            pp.second = seller->client_name;
            if(buyer->timestamp < seller->timestamp)
                xx.second = buyer->price;
            else if(buyer->timestamp >= seller->timestamp)
                xx.second = seller->price;
            if(buyer->quantity <= seller->quantity){
                xx.first = buyer->quantity;
            }
            else if(buyer->quantity > seller->quantity)
                xx.first = seller->quantity;
            seller->quantity = (seller->quantity - xx.first);
            buyer->quantity = (buyer->quantity - xx.first);
            printVerbose(buyer, seller,xx);
            if(buyer->quantity == zero) {
                orderLine* temp = op.second->buy.top();
                delete temp;
                op.second->buy.pop();
                if(op.second->buy.empty()) {
                    op.second->blimit = zero;
                }
                else{
                    int cost = op.second->buy.top()->price;
                    op.second->blimit = cost;
                }
            }
            else if(seller->quantity == zero) {
                orderLine* temp = op.second->sell.top();
                delete temp;
                op.second->sell.pop();
                if(op.second->sell.empty())
                    op.second->slimit = INT_MAX;
                else{
                    int cost = op.second->sell.top()->price;
                    op.second->slimit = cost;
                }
            }
            trueOrFalse = true;
            if(xx.first > zero){
                returnValue = 1;
                //Add Transfers
                //Add Summary
                medianMap[op.first].insertMedian(xx.second);
            }
        }

        else
            trueOrFalse = false;
    }
    return returnValue;
}




