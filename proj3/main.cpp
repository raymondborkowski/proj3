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
    flagOptions* op = new flagOptions;
    *op = getopt(argc, argv);
    orderLine* newOrder = nullptr;
    orderLinePR pp;
    int countOrders = 1;
    int count = 0;
    bool test1 = op->mapType;
    //PR Read in
    if(test1 == true){
        pp = orderLineReadPR(countOrders);
        while(countOrders > 0){
            countOrders-=1;
            newOrder = pp.order();
            if(count != newOrder->timestamp){
                if(op->median == true){
                    op->printMedian(count);
                    count = newOrder->timestamp;
                }
                
            }
            op->insertDistribution(newOrder);
            //5. Process all possible trades with the information in your data structures (match buyers to sellers). If any
            //      orders cannot be filled, you should leave them in your data structures to match with future orders.
            op->runThru();
        }
    }

    //TL Read in
    int x;
    while(cin>>x){
        if(test1 == false){
            newOrder = orderLineRead(x);
        }
        if(count != newOrder->timestamp){
            if(op->median == true){
                op->printMedian(count);
                count = newOrder->timestamp;
            }
            
        }
        //4. Add the order from step 2 to your data structures.
        op->insertDistribution(newOrder);
        //5. Process all possible trades with the information in your data structures (match buyers to sellers). If any
        //      orders cannot be filled, you should leave them in your data structures to match with future orders.
        op->runThru();
        
    }
    if(op->median == true)
        op->printMedian(count);
    
    cout<<"--End of Day--\n";
    
    return 0;
}