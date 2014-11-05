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
#include "errorChecking.h"
#include "getopt.h"
using namespace std;

struct flagOptions{
    bool summary = false;
    bool verbose = false;
    bool median = false;
    bool transfers = false;
    bool insiders = false;
    bool ttt = false;
    string mapType;
};

flagOptions getopt(int argc, char ** argv);


#endif /* defined(__proj3__commandLine__) */