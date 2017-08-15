/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : MoreThanHalf.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 14:36:59
*  @Last Modified  : 2017/08/15 11:54:21
********************************************************************************
*/

//查找数组中出现次数超过一半的数字

//解析：如果一个数字在数组中超过一半，则排序后这个数字应该在数组的中间。
//使用快速排序的思想不需要真正完成排序，只需要在让patition的返回值不
//断逼近中间点，直到pivot为中间。

#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
            --high;
        if(low < high)
            a[low++] = a[high];
        while(low < high && a[low] <= pivot)
            ++low;
        if(low < high)
            a[high--] = a[low];
    }
    a[low] = pivot;
    return low;
}

bool g_InvalidInput = false;

bool checkInvalid(int a[], int n, int value)
{
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == value)
            ++cnt;
    return cnt*2 < n;
}

int MoreThanHalt(int a[], int n)
{
    if(a == NULL || n <= 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int middle = n / 2;
    int povitIndex = partition(a, 0, n - 1);
    while(povitIndex != middle)
    {
        if(povitIndex < middle)
            povitIndex = partition(a, povitIndex+1, n-1);
        else
            povitIndex = partition(a, 0, povitIndex-1);
    }
    g_InvalidInput = checkInvalid(a, n, a[povitIndex]);
    return a[povitIndex];
}

int main(int argc, const char *argv[])
{
    int a[] = {3, 3, 2, 3, 5, 6, 8, 3, 3, 2, 6, 3};
    int half = MoreThanHalt(a, sizeof(a)/sizeof(a[0]));
    if(g_InvalidInput)
        printf("invalid input.");
    else
        printf("half number: %d\n", half);
    return 0;
}
