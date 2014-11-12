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
    int transferBuy;
    int transferSell;
    int transferTotal;
    void bought(int, int);
    void sell(int, int);
    
    
    int median1=0;
    int span=0;
    int getMedian(){return median1;}
    int completeTrade(pair<string, equityT*> op, bool);
    flagOptions() : median1(0), span(0) {}
    void getMedians(priority_queue<int> maxQueue, priority_queue<int, vector<int>, greater<int>> minQueue);
    void insertMedian(int i);
    void printVerbose(orderLine* buyer, orderLine*, pair<int, int>);
    string last;
    pair<string, string> pp;
    pair<int, int> xx;
    
    
    int commision;
    int getcomis(){return commision;}
    int transfer;
    int gettrans(){return transfer;}
    int completed;
    int getCompleted(){return completed;}
    int shares;
    int getShares(){return shares;}
    void addSummary();
    void addTransfer();
    unordered_map<string, flagOptions> transferM;
    set<string> transferS;
    
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    bool summary = false;
    bool verbose = false;
    bool median = false;
    void runThru(bool);
    unordered_map<string, flagOptions> medianMap;
    set< string > medianSet;
    bool transfers = false;
    void printMedian(int x);
    void transferFunc(orderLine* newOrder);
    bool insiders = false;
    bool ttt = false;
    void insert(orderLine);
    bool mapType = false;
    void insertDistribution(orderLine* newOrder);
    unordered_map< string, equityT* > eqMap;
    set<string> insider;

    
};
flagOptions getopt(int argc, char ** argv);
bool isEmpty(pair<string, equityT*> op);

#endif /* defined(__proj3__commandLine__) */