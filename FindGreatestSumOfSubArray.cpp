/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : FindGreatestSumOfSubArray.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 20:55:48
*  @Last Modified  : 2017/08/13 11:06:53
********************************************************************************
*/

//输入一个整形数组，数组里有正数也有负数。数组中一个或者连续的多个整数组成一个子
//数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <stdio.h>
#include <algorithm>

bool g_InvalidInput = false;

// 方法一：
int findGreatestSumOfSubArray(int a[], int n)
{
    if(a == NULL || n <= 0)    
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int finalMax = a[0], currMax = a[0];
    for(int i = 1; i < n; ++i)
    {
        if(currMax < 0)      //重点是必须先判断currMax大于0才能currMax + = a[i]，不判断就加， 是错的。
            currMax = a[i];
        else
            currMax += a[i]; 
        if(currMax > finalMax)
            finalMax = currMax;
    }
    return finalMax;
}

// 方法二，动态规划法：
int maxContinueSubArray(int a[], int n)
{
    if(a == NULL || n < 1)
    {
        return 0;
        g_InvalidInput = true;
    }
    g_InvalidInput = false;
    int currMax = a[0], finalMax = a[0];
    for(int i = 1; i < n; ++i)
    {
        //如果currMax为负，则currMax的值被赋值为a[i]
        currMax = std::max(a[i], currMax + a[i]);
        finalMax = std::max(currMax, finalMax);
    }
    return finalMax;
}

int main(int argc, char *argv[])
{
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int sum = findGreatestSumOfSubArray(a, sizeof(a)/sizeof(a[0]));
    if(!g_InvalidInput)
        printf("%d\n", sum);
    return 0;
}
