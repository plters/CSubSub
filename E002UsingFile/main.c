//
//  main.c
//  E002UsingFile
//
//  Created by apple on 2016/12/4.
//  Copyright © 2016年 plters. All rights reserved.
//

#include <stdio.h>
#include "css.h"
int main(int argc, const char * argv[]) {
    logOn();
    
    cssString * str = cssStringCreateWithCString("/Users/apple/Desktop/CSubSub/E002UsingFile/Data.txt");
    cssFile * f = cssFileCreate(str);
    f->open(f,"r");
    
    printf("File Content : %s\n",f->getStringContent(f)->_cstr);
    
    str->release(str);
    f->release(f);
    return 0;
}
