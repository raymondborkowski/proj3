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
#include <deque>
#include <unordered_map>
#include <unordered_set>
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
    
    int tttbuyt = -1;
    int tttbuyp = 0;
    int tttsellt = -1;
    int tttsellp = 0;
    int tttp  = INT_MIN;
    
    void timeSellBuy(int,int,bool);
    void printT(string);
    bool check();
    
    int median1=0;
    int span=0;
    int transferBuy = 0;
    int transferSell = 0;
    int transferTotal = 0;
    
    void bought(int, int);
    void sell(int, int);
    void getMedians(priority_queue<int> maxQueue, priority_queue<int, vector<int>, greater<int>> minQueue);
    void insertMedian(int i);
    
    int medd(){return median1;}
    
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
    int time;
    unordered_map<string, med> transferM;
    unordered_map<string, med> tttM;
    unordered_map<string, med> medianMap;
    unordered_map< string, equityT* > eqMap;
    void inside(pair<string, equityT*> equity, bool);
    int commision = 0;
    int getcomis(){return commision;}
    int transfer = 0;
    int gettrans(){return transfer;}
    int completed = 0;
    int getCompleted(){return completed;}
    int shares = 0;
    int getShares(){return shares;}
    void completeSummary(int, int, bool);
    void completeTransfer(int, int, bool, bool, string, string);
    void completeTravel(int x1, bool buySell, bool travel, pair<string, equityT*> op);
    void completeVerb(bool, bool verb, int count, string ice,string, int ecirp, pair<string, equityT*> op);
    int completeTrade(pair<string, equityT*> op, bool);
    string last;
    pair<string, string> pp;
    pair<int, int> xx;
    deque<string> tttS;
    set<string> transferS;
    set<string> medianSet;
    unordered_set<string> insider;
    //  priority_queue<int> maxQueue;
    //  priority_queue<int, vector<int>, greater<int>> minQueue;
    
    
    void addSummary();
    void addTransfer();
    void addTTT(char*);
    void printVerbose(orderLine* buyer, orderLine*, pair<int, int>);
    void runThru(bool);
    void transferFunc(orderLine* newOrder);
    void timeTravFunc(orderLine* newOrder);
    void insert(orderLine);
    void insertDistribution(orderLine* newOrder);
    
    
};
flagOptions getopt(int argc, char ** argv);
bool isEmpty(pair<string, equityT*> op);

#endif /* defined(__proj3__commandLine__) */