//
//  commandLine.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "commandLine.h"

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
            case 'i':
                op.insiders = true;
                break;
            case 'g':
                op.ttt = true;
                break;
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

bool compare::comp(orderLine* a, orderLine* b) const {
    
    if(a->price < b->price)
        return true;
    else if(b->price < a->price)
        return false;
    else{
        if(reverse)
            return b->position > a->position;
        else
            return a->position > b->position;
    }
}

bool compare::operator()(orderLine* a, orderLine* b) const {
    
    if(reverse)
        return comp(b, a);
    
    return comp(a, b);
}