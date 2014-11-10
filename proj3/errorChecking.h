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
bool errorCheck( int time, char dollarSign,  int price, char hashTag,  int quantity, std::string buyOrSell, std::string client, std::string equitySymbol);
bool isAlpha(char x);
bool isAlpha1(char x);

#endif /* defined(__proj3__errorChecking__) */
