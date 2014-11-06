//
//  errorChecking.h
//  proj3
//
//  Created by Raymond Borkowski on 10/29/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __proj3__errorChecking__
#define __proj3__errorChecking__

#include <stdio.h>
#include <iostream>

bool errorCheckTimestamp(unsigned int time);
bool errorCheckPrice(char dollarSign, unsigned int price);
bool errorCheckQuantity(char hashTag, unsigned int quantity);
bool errorCheckBuyOrSell(std::string buyOrSell);
bool errorCheckClient(std::string client);
bool errorCheckEquitySymbol(std::string equitySymbol);
bool isAlpha(char x);

#endif /* defined(__proj3__errorChecking__) */
