/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintToMaxOfDigits.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 19:19:06
*  @Last Modified  : 2017/08/07 00:59:27
********************************************************************************
*/

#include <stdio.h>
#include <malloc.h>

//打印1到n的所有数字。n可能很大，超过long long的最大值。

void recursive(int array[], int n, int index)
{
    if(index == n)
    {
        int i = 0;
        while(i < n && array[i] == 0)
            ++i;
        for(; i < n; ++i)
            printf("%d", array[i]);
        printf("\n");
    }
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            array[index] = i;
            recursive(array, n, index + 1);
        }
    }
}

void printOneToN(int n)
{
    int *array = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < 10; ++i)
    {
        array[0] = i;
        recursive(array, n, 1);
    }
    free(array);
}

int main(int argc, const char *argv[])
{
    printOneToN(5);
    return 0;
}
