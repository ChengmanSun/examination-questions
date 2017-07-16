/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : mutiplied_division.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/17 22:06:06
*  @Last Modified  : 2017/05/18 00:11:42
********************************************************************************
*/

#include <stdio.h>
#include <math.h>

/*
 * <<1 == *2
 * <<2 == *4
 * <<3 == *8
 * 
 * >>1 == /2
 * >>2 == /4
 * >>3 == /8
 */

int main(int argc, const char *argv[])
{
    int i = 5, j = 20;
    printf("%d %d\n", i<<1, i*2);
    printf("%d %d\n", i<<2, i*4);
    printf("%d %d\n", j>>1, j/2);
    printf("%d %d\n", j>>2, j/4);
    printf("%d\n", 2>1);
    return 0;
}
