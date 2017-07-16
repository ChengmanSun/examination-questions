/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : FindGreatestSumOfSubArray.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 20:55:48
*  @Last Modified  : 2017/07/10 11:22:39
********************************************************************************
*/

//输入一个整形数组，数组里有正数也有负数。数组中一个或者连续的多个整数组成一个子
//数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <stdio.h>

bool g_InvalidInput = false;

int findGreatestSumOfSubArray(int a[], int n)
{
    if(a == NULL || n <= 0)    
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int greatestSum = a[0], currentSum = a[0];
    for(int i = 1; i < n; ++i)
    {
        if(currentSum < 0)      //重点是必须先判断currentSum大于0才能currentSum + = a[i]，不判断就加， 是错的。
            currentSum = a[i];
        else
            currentSum += a[i]; 
        if(currentSum > greatestSum)
            greatestSum = currentSum;
    }
    return greatestSum;
}

int main(int argc, const char *argv[])
{
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int sum = findGreatestSumOfSubArray(a, sizeof(a)/sizeof(a[0]));
    if(!g_InvalidInput)
        printf("%d\n", sum);
    return 0;
}
