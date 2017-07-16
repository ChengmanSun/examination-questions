/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : findTheNumberApearOnce.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/16 20:33:59
*  @Last Modified  : 2017/07/10 13:52:03
********************************************************************************
*/

#include <stdio.h>

//一个整型数组中除了两个数字只出现了一次之外，其它数字都出现了两次。
//请找出这两个数字。

bool findNumberAppearOnce(int a[], int n, int *number1, int *number2)
{
    if(a == NULL || n <= 0 || number1 == NULL || number2 == NULL)
        return false;

    int sum = a[0];
    for(int i = 1; i < n; ++i)
        sum ^= a[i];
    int flag = 1;
    while( !(sum & flag) )
        flag <<= 1;

    *number1 = *number2 = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] & flag)
            *number1 ^= a[i];
        else
            *number2 ^= a[i];
    }
}

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;
    int a[] = {1, 1, 2, 3, 3, 4, 4, 5, 6, 6};
    int x, y;
    findNumberAppearOnce(a, sizeof(a)/sizeof(a[0]), &x, &y);
    printf("x:%d y:%d", x, y);
    return 0;
}
