/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReorderArray.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 21:29:27
*  @Last Modified  : 2017/07/13 16:00:26
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
    int low = 0, high = n - 1;
    while(low < high)
    {
        while(low < high && (a[low] & 0x01) == 1) //low向后移动直到找到偶数
            ++low;
        while(low < high && (a[high] & 0x01) == 0)//high向前移动直到找到奇数
            --high;
        if(low < high)
        {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
}

int main(int argc, const char *argv[])
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
