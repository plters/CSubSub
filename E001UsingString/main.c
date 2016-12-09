//
//  main.c
//  E001UsingString
//
//  Created by apple on 2016/12/4.
//  Copyright © 2016年 plters. All rights reserved.
//

#include <stdio.h>
#include "css.h"
int main(int argc, const char * argv[]) {
   
    // logOn();
    
    cssString *str = cssStringCreateWithCString("Hello World");
    
    //insert coder here
    printf("%s\n",str->getCString(str));
    
    str->release(str);
    return 0;
}
