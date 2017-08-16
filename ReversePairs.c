/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReversePairs.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/22 16:45:26
*  @Last Modified  : 2017/08/16 16:16:17
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MergeSort(int data[], int copy[], int left, int right)
{
    if(left >= right)
        return 0;
    int middle = left + (right - left) / 2;
    int leftCount = MergeSort(copy, data, left, middle);
    int rightCount = MergeSort(copy, data, middle + 1, right);
    int i = middle, j = right;
    int copyIndex = right, count = 0;
    while(i >= left && j > middle)
    {
        if(data[i] > data[j])
        {
            count += j - middle;
            copy[copyIndex--] = data[i--];
        }
        else
            copy[copyIndex--] = data[j--];
    }
    while(i >= left)
        copy[copyIndex--] = data[i--];
    while(j > middle)
        copy[copyIndex--] = data[j--];
    return leftCount + rightCount + count;
}

int ReversePairs(int data[], int n)
{
    if(data == NULL || n <= 0)
        return 0;
    int *copy = (int *)malloc(sizeof(int) * n);
    memcpy(copy, data, sizeof(int) * n);
    int count = MergeSort(copy, data, 0, n - 1);
    free(copy);
    return count;
}

int main(int argc, char *argv[])
{
    int a[] = {7, 5, 6, 4};
    printf("ReversePairs : %d\n", ReversePairs(a, sizeof(a)/sizeof(a[0])));
    return 0;
}
