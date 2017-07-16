/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : test_funptr.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/09 15:26:08
*  @Last Modified  : 2017/05/09 15:31:00
********************************************************************************
*/

#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char *argv[])
{
    int m;
    int (*f)(int, int);
    f = max;
    printf("the max number is:%d\n", f(1, 2));
    printf("the max number is:%d\n", (*f)(6, 8));
    return 0;
}
