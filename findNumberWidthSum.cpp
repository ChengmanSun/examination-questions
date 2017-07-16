/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : findNumberWidthSum.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/16 22:12:27
*  @Last Modified  : 2017/07/10 14:51:44
********************************************************************************
*/

#include <stdio.h>

//输入一个弟增的数组和一个数字s，在数组中查找两个数，使得它们的和等于s。如果有多
//对数字的和等于s，输出任意一对即可。
bool findNumbersWidthSum(int a[], int n, int sum, int *number1, int *number2)
{
    if(a == NULL || n <= 0 || number1 == NULL || number2 == NULL)
        return false;
    int low = 0, high = n - 1;
    while(low < high)
    {
        int temp = a[low] + a[high];
        if(temp == sum)
        {
            *number1 = a[low];
            *number2 = a[high];
            return true;
        }
        else if(temp > sum)
            --high;
        else
            ++low;
    }
    return false;
}

//输入一个正数s，打印出所有和为s的连续正数序列(至少含有两个数)，例如输入15，由于
//1+2+3+4+5=4+5+6+7=7+8=15，所以结果打印出3个连续的正数序列：1~5、4~6、7~8。
void PrintContinusSequence(int s, int b)
{
    for(int i = s; i <= b; ++i)
        printf("%d", i);
    printf("\n");
}

void FindContinusSequence(int value)
{
    if(value < 3)
        return;
    int small = 1, big = 2, half = (value+1)/2;
    int sum = small + big;
    while(small < half)
    {
        if(sum == value)
            PrintContinusSequence(small, big);
        while(sum > value && small < half)
        {
            sum -= small;
            ++small;
            if(sum == value)
                PrintContinusSequence(small, big);
        }
        ++big;
        sum += big;
    }
}

int main(int argc, const char *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int x, y;
    findNumbersWidthSum(array, sizeof(array)/sizeof(array[0]), 18, &x, &y);
    printf("x:%d y:%d\n", x, y);
    printf("---------------------------------------\n");
    FindContinusSequence(18);
    return 0;
}
