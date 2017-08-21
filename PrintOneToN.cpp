/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintToMaxOfDigits.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 19:19:06
*  @Last Modified  : 2017/08/17 17:25:37
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
        while(i < n) printf("%d", num[i++]);
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
    if(n < 1) return;
    int *num = (int *)malloc(sizeof(int) * n);
    recursive(num, n, 0);
    free(num);
}

int main(int argc, char *argv[])
{
    printOneToN(5);
    return 0;
}
