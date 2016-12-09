//
//  main.c
//  L001HelloCSS
//
//  Created by apple on 2016/12/4.
//  Copyright © 2016年 plters. All rights reserved.
//

#include <stdio.h>
#include "css.h"

#define HelloFields(TYPE) \
    cssObjectFields(TYPE) \
    char * _name; \
    void (*sayHello)(TYPE); \
    void (*_superOnDelloc)(TYPE); \




cssClass(Hello)

static void HelloSayHello(Hello * _this){
    printf("Hello %s\n",_this->_name);
}


static void HelloOnDelloc(Hello * h){
    logOut("delete Hello");
    
    h->_superOnDelloc(h);
}

Hello* HelloInit(Hello * _this,char *name){
    cssObjectInit(cssAs(cssObject*, _this));
    
    logOut("Hello init");
    
    _this->_name = name;
    _this->_superOnDelloc = _this->onDelloc;
    _this->onDelloc = &HelloOnDelloc;
    _this->sayHello = &HelloSayHello;
    
    return _this;
}

Hello* HelloCreate(char *name){
    return HelloInit(cssAlloc(Hello), name);
}



int main(int argc, const char * argv[]) {

    logOn();
//    Hello * h = HelloInit(cssAlloc(Hello), "ZhangSan");
    Hello *h = HelloCreate("ZhangSan");
    h->sayHello(h);

    
    h->release(h);
   
    
    
    return 0;
}
