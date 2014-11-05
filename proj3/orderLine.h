//
//  readInLines.h
//  proj3
//
//  Created by Raymond Borkowski on 11/5/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__readInLines__
#define __proj3__readInLines__

#include <stdio.h>
#include "errorChecking.h"

struct orderLine{
    std::string client_name = NULL;
    std::string buyOrSell = NULL;
    std::string equitySymbol = NULL;
    unsigned int timestamp = 0;
    unsigned int price = 0;
    unsigned int quantity = 0;
    unsigned int position = 0;
    
};

orderLine orderLineRead();

#endif /* defined(__proj3__readInLines__) */
