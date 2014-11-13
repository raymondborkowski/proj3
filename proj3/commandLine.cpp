//
//  commandLine.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "commandLine.h"
#include <deque>

flagOptions getopt(int argc, char ** argv){
    
    struct option longOpts[]={
        {"summary", no_argument, NULL, 's'},
        {"verbose", no_argument, NULL, 'v'},
        {"median", no_argument, NULL, 'm'},
        {"transfers", no_argument, NULL, 't'},
        {"insiders", required_argument, NULL, 'i'},
        {"ttt", required_argument, NULL, 'g'},
        {"help", no_argument, NULL, 'h'}
    };
    flagOptions op;
    string mapTypeTemp;
    int opt = 0, index = 0;
    while((opt = getopt_long (argc, argv, "svmti:g:h", longOpts, &index)) != -1){
        switch(opt) {
            case 's':
                op.summary = true;
                break;
            case 'v':
                op.verbose = true;
                break;
            case 'm':
                op.median = true;
                break;
            case 't':
                op.transfers=true;
                break;
            case 'i':{
                op.insiders = true;
                op.insider.insert(optarg);
                if(op.transfers == true) {
                    if(!op.transferM.count(optarg)) {
                        string temp = optarg;
                        med temp1 = *new med;
                        temp = "INSIDER_" + temp;
                        op.transferM.insert(make_pair(temp, temp1));
                        op.transferS.insert(temp);
                    }
                }
            }
                break;
            case 'g':{
                op.ttt = true;
                bool timeTrav = op.ttt;
                while(timeTrav == true){
                    string temp(optarg);
                    med* one = new med;
                    op.tttM.insert(make_pair(temp, *one));
                    op.tttS.push_back(temp);
                    timeTrav = false;
                    continue;
                }
                break;
            }
            case 'h':
                cout<<"This is a Stock Market Simulation\n"
                "--s -summary prints that\n"
                "--v -verbose prints verbose\n"
                "--m -median prints median\n"
                "--t -transfers prints transfers\n"
                "--i -insiders prints insiders\n"
                "--g -ttt prints ttt\n"
                "--h -help prints this!\n";
                exit(0);
        }
    }
    cin>>mapTypeTemp;
    if(mapTypeTemp == "PR")
        op.mapType = true;
    
    return op;
}

bool compare::comp(orderLine* i, orderLine* j) const {
    
    unsigned int a = i->price;
    unsigned int b = j->price;
    unsigned int c = i->position;
    unsigned int d = j->position;
    
    while(true){
        if(b == a){
            if(reverse){
                if(d > c)
                    return true;
                return false;
            }
            else{
                if(c > d)
                    return true;
                return false;
            }
        }
        else if(a < b)
            return true;
        return false;
    }
}

bool compare::operator()(orderLine* i, orderLine* j) const {
    if(!reverse){
        unsigned int a = i->price;
        unsigned int b = j->price;
        unsigned int c = i->position;
        unsigned int d = j->position;
        
        while(true){
            if(b == a){
                if(reverse){
                    if(d > c)
                        return true;
                    return false;
                }
                else{
                    if(c > d)
                        return true;
                    return false;
                }
            }
            else if(a < b)
                return true;
            return false;
        }
    }
    else{
        unsigned int a = j->price;
        unsigned int b = i->price;
        unsigned int c = j->position;
        unsigned int d = i->position;
        
        while(true){
            if(b == a){
                if(reverse){
                    if(d > c)
                        return true;
                    return false;
                }
                else{
                    if(c > d)
                        return true;
                    return false;
                }
            }
            else if(a < b)
                return true;
            return false;
        }
    }
}