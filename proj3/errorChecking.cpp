//
//  errorChecking.cpp
//  proj3
//
//  Created by Raymond Borkowski on 10/29/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "errorChecking.h"

bool errorCheck(int time, char dollarSign,  int price, char hashTag,  int quantity, std::string buyOrSell, std::string client, std::string equitySymbol){
    int zero = 0;
    if(time < zero )
        exit(1);
    if(dollarSign != '$')
        exit(1);
    if(price <= 0)
        exit(1);
    if(hashTag != '#')
        exit(1);
    if(quantity <= 0)
        exit(1);
    if(buyOrSell != "BUY" && buyOrSell != "SELL")
        exit(1);
    for(unsigned int i = 0; i < client.length(); i++){
        if(!isalnum(client[i]) && client[i] != '_')
            exit(1);
    }
    size_t length = equitySymbol.length();
    if(length < 1 || length > 5)
        exit(1);
    for(size_t j = 0; j < length; j++){
        if(!isalnum(equitySymbol[j]) && equitySymbol[j] != '_' && equitySymbol[j] != '.')
            exit(1);
    }
    
    return true;
}
bool isAlpha(char x){
    if(islower(x))
        return true;
    else
        exit(1);
}
bool isAlpha1(char x){
    if(isupper(x))
        return true;
    else
        exit(1);
}