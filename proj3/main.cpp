//
//  main.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/28/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include <iostream>
#include "commandLine.h"
#include "errorChecking.h"
#include <fstream>

int main(int argc, char ** argv) {
    
  //  ios_base::sync_with_stdio(false);
    ifstream arq(getenv("MYARQ"));
    cin.rdbuf(arq.rdbuf());
    flagOptions op;
    op = getopt(argc, argv);
    cout<<op.mapType<<endl;
    
    if(op.mapType == "PR"){
        pseudo
    }
    else if(op.mapType == "TL"){
        
    }
    else
        exit(1);
    
    
    return 0;
}