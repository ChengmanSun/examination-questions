/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintToMaxOfDigits.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 19:19:06
*  @Last Modified  : 2017/08/15 16:05:21
********************************************************************************
*/

#include <stdio.h>
#include <malloc.h>

//打印1到n的所有数字。n可能很大，超过long long的最大值。

void recursive(int num[], int n, int index)
{
    if(index == n)
    {
        int i = 0;
        while(i < n && num[i] == 0) ++i;
        while(i < n) printf("%d", num[i]);
        printf("\n");
    }
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            num[index] = i;
            recursive(num, n, index + 1);
        }
    }
}

void printOneToN(int n)
{
    int *num = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < 10; ++i)
    {
        num[0] = i;
        recursive(num, n, 1);
    }
    free(num);
}

int main(int argc, const char *argv[])
{
    printOneToN(5);
    return 0;
}
