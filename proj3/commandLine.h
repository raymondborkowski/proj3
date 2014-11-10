//
//  commandLine.h
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__commandLine__
#define __proj3__commandLine__

#include <stdio.h>
#include <iostream>
#include <random>
#include "map.h"
#include <map>
#include "orderLine.h"
#include <queue>
#include<set>
#include "errorChecking.h"
#include "getopt.h"
using namespace std;
struct medianT{
    //I will need to write a function to get median
    int median=0;
    int span=0;
    int getMedian(){return median;}
};
struct compare{
    bool reverse;
    compare(const bool& rev=false) {
        reverse = rev;
    }
    bool comp(orderLine* a, orderLine* b) const;
    bool operator()(orderLine* a, orderLine* b) const;
};
typedef vector<orderLine* > Orders;
typedef priority_queue<orderLine*, Orders, compare> orderQueue;
struct equityT{
    orderQueue buy;
    orderQueue sell;
    int blimit;
    int slimit;
    void insertEq(orderLine);
    equityT() :
    sell(compare(true)), blimit(-1), slimit(INT_MAX) {}
    bool empty() {return (buy.empty() || sell.empty());}
};
struct prioQueue{
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
};
typedef vector<orderLine* > Orders;
struct flagOptions{
    bool summary = false;
    bool verbose = false;
    bool median = false;
    bool transfers = false;
    bool insiders = false;
    bool ttt = false;
    void insert(orderLine);
    string last;
    bool mapType = false;
    void insertDistribution(orderLine newOrder);
    
    map<string, medianT> medianMap;
    set< string > medianSet;
    map< string, equityT > eqMap;
    set<string> insider;
    void printMedian(int);
    
};
flagOptions getopt(int argc, char ** argv);


#endif /* defined(__proj3__commandLine__) */