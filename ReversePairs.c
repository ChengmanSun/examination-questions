/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReversePairs.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/22 16:45:26
*  @Last Modified  : 2017/07/10 22:33:56
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countInversePairs(int data[], int copy[], int start, int end)
{
    if(start >= end)
        return 0;
    int middle = (start + end) / 2;
    int leftCount = countInversePairs(copy, data, start, middle);
    int rightCount = countInversePairs(copy, data, middle + 1, end);
    int i = middle, j = end;
    int copyIndex = end;
    int count = 0;
    while(i >= start && j >= middle + 1)
    {
        if(data[i] > data[j])
        {
            count += j - middle;
            copy[copyIndex--] = data[i--];
        }
        else
            copy[copyIndex--] = data[j--];
    }
    while(i >= start)
        copy[copyIndex--] = data[i--];
    while(j >= middle + 1)
        copy[copyIndex--] = data[j--];
    return leftCount + rightCount + count;
}

int reversePairs(int data[], int n)
{
    if(data == NULL || n <= 0)
        return 0;
    int *copy = (int *)malloc(sizeof(int) * n);
    memcpy(copy, data, sizeof(int) * n);
    int count = countInversePairs(data, copy, 0, n - 1);
    /* memcpy(copy, data, sizeof(int) * n); */
    free(copy);
    return count;
}

int main(int argc, const char *argv[])
{
    int a[] = {7, 5, 6, 4};
    printf("ReversePairs : %d\n", reversePairs(a, sizeof(a)/sizeof(a[0])));
    return 0;
}
