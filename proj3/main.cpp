//
//  main.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include <iostream>
#include "commandLine.h"

int main(int argc, char ** argv) {

    ios_base::sync_with_stdio(false);
    flagOptions op;
    string mapType = getopt(argc, argv, op);
    
    
    
    
    cout<<mapType;
    
    
    return 0;
}
