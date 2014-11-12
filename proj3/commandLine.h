//
//  commandLine.h
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__commandLine__
#define __proj3__commandLine__
#include <climits>
#include <stdio.h>
#include <iostream>
#include <random>
#include "map.h"
#include <map>
#include <unordered_map>
#include "orderLine.h"
#include <queue>
#include<set>
#include "errorChecking.h"
#include "getopt.h"
using namespace std;
struct whileStuff{
    bool trueOrFalse;
    int returnValue;
};

struct med {
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    int median1=0;
    int span=0;
    int transferBuy;
    int transferSell;
    int transferTotal;
    
    void bought(int, int);
    void sell(int, int);
    void getMedians(priority_queue<int> maxQueue, priority_queue<int, vector<int>, greater<int>> minQueue);
    void insertMedian(int i);
    
    int getMedian(){return median1;}
    
    med() : median1(0), span(0) {}
    
};

struct compare{
    bool reverse;
    compare(const bool& rev=false) {
        reverse = rev;
    }
    bool comp(orderLine*, orderLine*) const;
    bool operator()(orderLine*, orderLine*) const;
};
typedef vector<orderLine* > Orders;
typedef priority_queue<orderLine*, Orders, compare> orderQueue;
struct equityT{
    orderQueue buy;
    orderQueue sell;
    int blimit;
    whileStuff whileStufff(orderLine* buyer, orderLine* seller);
    int slimit;
    equityT() :
    sell(compare(true)), blimit(-1), slimit(INT_MAX) {}
    bool empty() {return (buy.empty() || sell.empty());}
    void insertEq(orderLine*);
    
};

typedef vector<orderLine* > Orders;
typedef priority_queue<orderLine*, Orders, compare> orderQueue;
struct flagOptions{
    bool summary = false;
    bool verbose = false;
    bool median = false;
    bool transfers = false;
    bool insiders = false;
    bool ttt = false;
    bool mapType = false;
    unordered_map<string, med> transferM;
    unordered_map<string, med> medianMap;
    unordered_map< string, equityT* > eqMap;
    
    int commision;
    int getcomis(){return commision;}
    int transfer;
    int gettrans(){return transfer;}
    int completed;
    int getCompleted(){return completed;}
    int shares;
    int getShares(){return shares;}
    
    int completeTrade(pair<string, equityT*> op, bool);
    string last;
    pair<string, string> pp;
    pair<int, int> xx;
    
    set<string> transferS;
    set< string > medianSet;
    set<string> insider;
    //  priority_queue<int> maxQueue;
    //  priority_queue<int, vector<int>, greater<int>> minQueue;
    
    
    void addSummary();
    void addTransfer();
    
    void printVerbose(orderLine* buyer, orderLine*, pair<int, int>);
    void runThru(bool);
    void printMedian(int x);
    void transferFunc(orderLine* newOrder);
    void insert(orderLine);
    void insertDistribution(orderLine* newOrder);
    
    
};
flagOptions getopt(int argc, char ** argv);
bool isEmpty(pair<string, equityT*> op);

#endif /* defined(__proj3__commandLine__) */