//
//  commandLine.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "commandLine.h"

string getopt(int argc, char ** argv){
    
    bool s = false, q = false;
    
    struct option longOpts[]={
        {"summary", no_argument, NULL, 's'},
        {"verbose", no_argument, NULL, 'v'},
        {"median", no_argument, NULL, 'm'},
        {"transfers", no_argument, NULL, 't'},
        {"insiders", required_argument, NULL, 'i'},
        {"ttt", required_argument, NULL, 'g'},
        {"help", no_argument, NULL, 'h'}
    };
    int opt = 0, index = 0;
    while((opt = getopt_long (argc, argv, "svmti:g:h", longOpts, &index)) != -1){
        switch(opt) {
            case 's':
                break;
            case 'v':
                break;
            case 'm':
                break;
            case 't':
                break;
            case 'i':
                break;
            case 'g':
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
    if(s && q){
        cerr << "You have to many routing Schemes oh no!\n";
        exit(1);
    }
    if(!(s || q)){
        cerr<<"You forgot to pick a routing scheme dummy!\n";
        exit(1);
    }
    string mapType;
    cin>>mapType;
    
    return mapType;
}