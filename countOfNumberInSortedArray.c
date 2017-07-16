/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : findFirstK.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/16 15:45:16
*  @Last Modified  : 2017/07/09 14:33:28
********************************************************************************
*/

#include <stdio.h>

//统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3, 3, 3, 4, 5}和
//数字3，由于数字3在数组中出现了4次，所以输出3。

int findFirst(int a[], int n, int value)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] == value)
        {
            if(middle == 0 || a[middle - 1] < value)
                return middle;
            else
                high = middle - 1;
        }
        else if(a[middle] < value)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

int findLast(int a[], int n, int value)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] == value)
        {
            if(middle == n - 1 || a[middle+1] > value)
                return middle;
            else
                low = middle + 1;
        }
        else if(a[middle] < value)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return - 1;
}

int countOfNumberInSortedArray(int a[], int n, int value)
{
    if(a == NULL || n <= 0)
        return 0;
    int first = findFirst(a, n, value);
    if(first < 0)
        return 0;
    int last = findLast(a + first, n - first, value);
    return last + 1;
}

int main(int argc, const char *argv[])
{
    int value = 0;
    printf("请输入要查找的数：\n");
    fflush(stdout);
    scanf("%d", &value);
    int a[] = {0, 0, 0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10};
    printf("count of %d is: %d\n", value, countOfNumberInSortedArray(a, sizeof(a)/sizeof(a[0]), value));
    return 0;
}
