/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReorderArray.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 21:29:27
*  @Last Modified  : 2017/08/16 13:38:21
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//将一个数组中的所有奇数排在偶数后面。

void Reorder(int a[], int n)
{
    if(a == NULL || n < 1)
        return;
    int left = 0, right = n - 1;
    while(left < right)
    {
        while(left < right && (a[left] & 0x01) == 0) //left向右移动直到找到奇数
            ++left;
        while(left < right && (a[right] & 0x01) == 1)//right向左移动直到找到偶数
            --right;
        if(left < right)
        {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int a[50];
    srand(time(NULL));
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
        a[i] = rand();
    fflush(stdout);
    Reorder(a, sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
        printf("%d ", a[i]);
    return 0;
}
