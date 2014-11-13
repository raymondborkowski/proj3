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
  //  ifstream arq(getenv("MYARQ"));
  //  cin.rdbuf(arq.rdbuf());
    flagOptions* op = new flagOptions;
    *op = getopt(argc, argv);
    orderLine* newOrder = nullptr;
    orderLinePR pp;
    int y = 0;
    int countOrders = 1;
    unsigned  int count = 0;
    bool test1 = op->mapType;
    //PR Read in
    if(test1 == true){
        pp = orderLineReadPR(countOrders);
        while(countOrders > 0){
            countOrders-=1;
            newOrder = pp.order();
            if(count != newOrder->timestamp){
                if(op->median == true){
                    for(auto it = op->medianSet.begin(); it != op->medianSet.end(); ++it) {
                        cout<<"Median match price of " << *it << " at time "<< count << " is $" << op->medianMap[*it].medd()<<'\n';
                    }
                    count = newOrder->timestamp;
                }
                
            }
            op->insertDistribution(newOrder);
            //5. Process all possible trades with the information in your data structures (match buyers to sellers). If any
            //      orders cannot be filled, you should leave them in your data structures to match with future orders.
            op->runThru(test1);
        }
    }
    
    //TL Read in
    int x;
    while(cin>>x){
        if(test1 == false){
            newOrder = orderLineRead(x, y);
            y= newOrder->timestamp;
        }
        if(count != newOrder->timestamp){
            if(op->median == true){
                for(auto it = op->medianSet.begin(); it != op->medianSet.end(); ++it) {
                    cout<<"Median match price of " << *it << " at time "<< count << " is $" << op->medianMap[*it].medd()<<'\n';
                }
                count = newOrder->timestamp;
            }
            
        }
        //4. Add the order from step 2 to your data structures.
        op->insertDistribution(newOrder);
        //5. Process all possible trades with the information in your data structures (match buyers to sellers). If any
        //      orders cannot be filled, you should leave them in your data structures to match with future orders.
        op->runThru(test1);
        
    }
    if(op->median == true){
        for(auto it = op->medianSet.begin(); it != op->medianSet.end(); ++it) {
            cout<<"Median match price of " << *it << " at time "<< count << " is $" << op->medianMap[*it].medd()<<'\n';
        }
    }
    
    cout<<"---End of Day---\n";
    
    if(op->summary == true){
        cout<<"Commission Earnings: $"<<op->getcomis()<<"\n"<<"Total Amount of Money Transferred: $"<<op->gettrans()<<"\n";
        cout<<"Number of Completed Trades: "<<op->getCompleted()<<"\n"<<"Number of Shares Traded: "<<op->getShares()<<"\n";
    }
    if(op->transfers){
        for(auto it = op->transferS.begin(); it != op->transferS.end(); ++it){
            med clientt = op->transferM[*it];
            cout << *it << " bought " << clientt.transferBuy<< " and sold " << clientt.transferSell  << " for a net transfer of $" << clientt.transferTotal << "\n";
        }
    }
    if(op->ttt){
        for(auto it = op->tttS.begin(); it !=op->tttS.end(); ++it){
            med client = op->tttM[*it];
            client.check();
            cout<<"Time travelers would buy ";
            cout<<*it;
            cout<<" at time: "<<client.tttbuyt<<" and sell it at time: "<<client.tttsellt<<"\n";
        }
    }
    
    return 0;
}