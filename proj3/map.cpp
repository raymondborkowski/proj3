//
//  map.cpp
//  proj3
//
//  Created by Raymond Borkowski on 11/9/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "map.h"
bool med::check(){
    int i = -1;
    int j = 0;
    if(tttsellt < j){
        tttbuyt = i;
        return true;
    }
    return false;
}
void flagOptions::printVerbose(orderLine* buyer, orderLine* seller, pair<int, int> xx){
    if(verbose==true){
        if(xx.first == 0)
            return;
        cout<<buyer->client_name<<" purchased "<<xx.first<<" shares of "<<buyer->equitySymbol<<" from "<<seller->client_name<<" for $"<<xx.second<<"/"<<"share\n";
    }
}

void med::timeSellBuy(int i, int j, bool buyOrSell){
    if(buyOrSell == true){
        tttbuyt = i;
        tttbuyp = j;
        int total = tttsellp - tttbuyp;
        tttp = total;
        
        return;
    }
    else if(buyOrSell == false && !(tttbuyt < 0)){
        tttsellp = j;
        tttsellt = i;
        int total = tttsellp - tttbuyp;
        tttp = total;
    }
}

//I need to set max and min prio queues
void med::getMedians(priority_queue<int> maxQueue, priority_queue<int, vector<int>, greater<int>> minQueue){
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
void med::insertMedian(int i){
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
int addOne(int x){
    x +=1;
    return x;
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
    time = newOrder->timestamp;
    transferFunc(newOrder);
    timeTravFunc(newOrder);
}
void flagOptions::timeTravFunc(orderLine* newOrder){
    
    bool timeTrave = ttt;
    int price = newOrder->price;
    int tSell = tttM[newOrder->equitySymbol].tttsellp;
    int tBuy = tttM[newOrder->equitySymbol].tttbuyp;
    int tBTime = tttM[newOrder->equitySymbol].tttbuyt;
    int tSTime = tttM[newOrder->equitySymbol].tttsellt;
    int total = tttM[newOrder->equitySymbol].tttp;
    while(timeTrave){
        string temp = newOrder->buyOrSell;
        bool buy = false;
        if(temp =="BUY")
            buy = true;
        if(tttM.count(newOrder->equitySymbol)){
            if(!buy){
                int x = tSell - price;
                if(x > tttM[newOrder->equitySymbol].tttp)
                    tttM[newOrder->equitySymbol].timeSellBuy(newOrder->timestamp,price, true);
            }
        }
        if(tttM.count(newOrder->equitySymbol)){
            if(buy){
                int x = price - tBuy;
                if(tBTime > tSTime)
                    tttM[newOrder->equitySymbol].timeSellBuy(newOrder->timestamp,price, false);
                if(x > total)
                    tttM[newOrder->equitySymbol].timeSellBuy(newOrder->timestamp,price, false);
            }
        }
        timeTrave = false;
    }
}

void flagOptions::transferFunc(orderLine* newOrder){
    med* order = new med;
    bool test = transfers;
    while(test == true){
        if(transferM.count(newOrder->client_name))
            goto here;
        else{
            transferM.insert(make_pair(newOrder->client_name, *order));
            transferS.insert(newOrder->client_name);
            goto here;
        }
    }
here:
    delete order;
}

void med::bought(int i, int j) {
    //j = i + j;
    
    int temp = i*j;
    transferBuy = i + transferBuy;
    transferTotal = transferTotal - temp;
}
void  med::sell(int i, int j) {
    transferSell = i + transferSell;
    int temp = i * j;
    transferTotal = temp + transferTotal;
}

int easyCalc(int x, int y, bool test){
    int val;
    if(test)
        val = x-y;
    else
        val = y - x;
    return val;
}

int addTwo(int x1, int x2){
    int p = x1+x2;
    return p;
}
int divide(int x){
    return (x/100);
}


bool comparee(int x, int y){
    if(x > (y/10)){
        return true;
    }
    return false;
}

void flagOptions::inside(pair<string, equityT*> op, bool type){
    
    //if true buy if false sell
    
    if(type){
        if(op.second->buy.empty() == true)
            return;
    }
    else{
        if(op.second->sell.empty() == true)
            return;
    }
    int ecirp;
    int total;
    string print = "INSIDER_";
    print = print + op.first;
    orderLine* t = nullptr;
    string ice;
    int count;
    int medd = medianMap[op.first].medd();
    if(medd){
        if(type){
            ecirp = op.second->blimit;
        }
        else{
            ecirp = op.second->slimit;
        }
        total = easyCalc(ecirp, medd, type);
        
        if(comparee(total, medd) == true){
            if(type){
                t = op.second->buy.top();
                count = t->quantity;
                ice = t->client_name;
                op.second->buy.pop();
                if(op.second->buy.empty() == true) {
                    op.second->blimit = 0;
                }
                else
                    op.second->blimit = op.second->buy.top()->price;
            }
            else{
                t=op.second->sell.top();
                count = t->quantity;
                ice = t->client_name;
                op.second->sell.pop();
                if(op.second->sell.empty() == true) {
                    op.second->slimit = 1316134912;
                }
                else
                    op.second->slimit = op.second->sell.top()->price;
            }
            medianMap[op.first].insertMedian(ecirp);
            
            completeSummary(count, ecirp, summary);
            completeTransfer(count, ecirp, transfers, type, print, ice);
            completeTravel(ecirp, type, ttt, op);
            completeVerb(type, verbose, count, ice, print, ecirp, op);
            
        }
    }
    delete t;
}
void flagOptions::completeVerb(bool buySell, bool verb, int count, string ice, string print, int ecirp, pair<string, equityT*> op){
    while(verb){
        if(count > 0){
            while(buySell){
                cout<<ice<<" purchased "<<count<<" shares of "<<op.first<<" from "<<print<<" for $"<<ecirp<<"/share\n";
                return;
            }
            cout<<print<<" purchased "<<count<<" shares of "<<op.first<<" from "<<ice<<" for $"<<ecirp<<"/share\n";
            break;
        }
        break;
    }
}

void flagOptions::completeTravel(int x1, bool buySell, bool travel, pair<string, equityT*> op){
    //price x1
    while(travel){
        string temp;
        while(tttM.count(op.first)){
            if(buySell){
                int x = tttM[op.first].tttbuyp - x1;
                if(x > (tttM[op.first].tttp)){
                    tttM[op.first].timeSellBuy(time, x1, true);
                }
            }
            else if(!buySell){
                int x = x1 - tttM[op.first].tttsellp;
                if(x > tttM[op.first].tttp)
                    tttM[op.first].timeSellBuy(time, x1, false);
                
            }
            return;
        }
        return;
    }
    return;
    
    
}
void flagOptions::completeSummary(int count, int other, bool summ){
    int mult = count * other;
    while(summ){
        shares += count;
        completed = addOne(completed);
        transfer = addTwo(transfer, mult);
        for(int i = 0; i < 2; i++)
            commision = ((count*other) / 100 )+ commision;
        return;
    }
}
void flagOptions::completeTransfer(int i, int j, bool transfer, bool buySell, string go, string ice){
    med* tran = new med;
    transferS.insert(go);
    bool test = buySell;
    
    while(transfer){
        while(test){
            transferM[go].sell(i, j);
            transferM[ice].bought(i, j);
            goto here;
        }
    here:
        if(!test){
            transferM[go].bought(i, j);
            transferM[ice].sell(i,j);
        }
        if(transferM.count(go) == false){
            transferM.insert(make_pair(go, *tran));
        }
        transferS.insert(ice);
        break;
    }
    delete tran;
}

void flagOptions::runThru(bool x){
    int zero = 0;
    int bop = true;
    for(auto it = eqMap.begin(); it != eqMap.end(); it++){
        while(bop){
            if(completeTrade(*it, x) != zero) {
                last = it->first;
                if(median)
                    medianSet.insert(it->first);
            }
            bop = false;
        }
        while(!bop){
            if(insider.count(it->first)) {
                bool temp = false;
                for(int i = 0; i < 2; ++i){
                    if(i == 0)
                        temp = true;
                    else
                        temp = false;
                    inside(*it, temp);
                }
                
            }
            bop = true;
        }
    }
}

void flagOptions::addSummary(){
    bool test = summary;
    bool testT = transfers;
    int one = xx.first;
    int two = xx.second;
    while(testT == true){
        
        transferM[pp.first].bought(one, two);
        transferM[pp.second].sell(one, two);
        
        testT = false;
    }
    
    while(test){
        shares = one + shares;
        completed+=1;
        transfer = (one*two) + transfer;
        for(int i = 0; i < 2; i++)
            commision = ((one*two) / 100 )+ commision;
        test = false;
    }
}


int flagOptions::completeTrade(pair<string, equityT*> op, bool x){
    
    int returnValue = 0;
    bool trueOrFalse = true;
    orderLine* buyer;
    unsigned  int zero = 0;
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
            if(x == true){
                buyer->timestamp = buyer->position;
                seller->timestamp = seller->position;
            }
            if(buyer->position < seller->position)
                xx.second = buyer->price;
            else if(buyer->position >= seller->position)
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
                op.second->sell.pop();
                if(op.second->sell.empty())
                    op.second->slimit = INT_MAX;
                else{
                    int cost = op.second->sell.top()->price;
                    op.second->slimit = cost;
                }
            }
            int zeroo = 0;
            trueOrFalse = true;
            if(xx.first > zeroo){
                returnValue = 1;
                //Add Transfers
                //Add Summary
                addSummary();
                medianMap[op.first].insertMedian(xx.second);
            }
        }
        
        else
            trueOrFalse = false;
    }
    return returnValue;
}


