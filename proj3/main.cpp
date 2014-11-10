//
//  main.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include <iostream>
#include "commandLine.h"
#include "map.h"
#include "orderLine.h"
#include "errorChecking.h"
#include <fstream>

int main(int argc, char ** argv) {
    
    ios_base::sync_with_stdio(false);
    ifstream arq(getenv("MYARQ"));
    cin.rdbuf(arq.rdbuf());
    flagOptions op;
    op = getopt(argc, argv);
    orderLine newOrder;
    orderLinePR pp;
    int count = 0;
    
    //PR Read in
    if(op.mapType == true){
        pp = orderLineReadPR();
        newOrder = pp.order();
    }
    //TL Read in
    int x;
    while(cin>>x){
        if(op.mapType == false){
            newOrder = orderLineRead(x);
        }
        cout<<newOrder.client_name<<endl;
        if(count != newOrder.timestamp){
            if(op.median == true){
                op.printMedian(count);
                count = newOrder.timestamp;
            }
            newOrder.position = count;
        }
        op.insertDistribution(newOrder);
    }
    
    return 0;
}