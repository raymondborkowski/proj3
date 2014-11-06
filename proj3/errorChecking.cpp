//
//  errorChecking.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/29/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "errorChecking.h"

bool errorCheckTimestamp(unsigned int time){
    unsigned int zero = 0;
    if(time >= zero )
        return true;
    exit(1);
}
bool errorCheckPrice(char dollarSign, unsigned int price){
    if(dollarSign != '$')
        exit(1);
    if(price > 0)
        return true;
    exit(1);
}
bool errorCheckQuantity(char hashTag, unsigned int quantity){
    if(hashTag != '#')
        exit(1);
    if(quantity > 0)
        return true;
    exit(1);
}
bool errorCheckBuyOrSell(std::string buyOrSell){
    if(buyOrSell == "BUY" || buyOrSell == "SELL")
        return true;
    else
        exit(1);
}
bool errorCheckClient(std::string client){
    for(int i = 0; i < client.length(); i++){
        if(!isalnum(client[i]) && client[i] != '_')
            exit(1);
    }
    return true;
}
bool errorCheckEquitySymbol(std::string equitySymbol){
    size_t length = equitySymbol.length();
    if(length < 1 || length > 5)
        exit(1);
    for(size_t i = 0; i < length; i++){
        if(!isalnum(equitySymbol[i]) && equitySymbol[i] != '_' && equitySymbol[i] != '.')
            exit(1);
    }
    return true;
}
bool isAlpha(char x){
    if(isalpha(x))
        return true;
    else
        exit(1);
}