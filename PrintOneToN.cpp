/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintToMaxOfDigits.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 19:19:06
*  @Last Modified  : 2017/07/12 16:26:06
********************************************************************************
*/

#include <stdio.h>
#include <malloc.h>

//打印1到n的所有数字。n可能很大，超过long long的最大值。

void printNumber(int *array, int n)
{
    int *p = array;
    while(*p == 0 && n > 0)
    {
        ++p;
        --n;
    }
    while(n-- > 0)
        printf("%d", *p++);
    printf("\n");
}

void recursivly(int array[], int n, int index)
{
    if(index == n)
        printNumber(array, n);
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            array[index] = i;
            recursivly(array, n, index + 1);
        }
    }
}

void printOneToN(int n)
{
    int *array = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < 10; ++i)
    {
        array[0] = i;
        recursivly(array, n, 1);
    }
    free(array);
}

int main(int argc, const char *argv[])
{
    printOneToN(5);
    return 0;
}
