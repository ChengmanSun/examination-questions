/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintProbability.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/17 14:58:34
*  @Last Modified  : 2017/08/15 17:39:51
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

/*
 * 题. 把n个骰子扔在地下，所有骰子朝上一面的点数之和为s。输入骰子数n，打印出骰子
 * 所有可能的值的出现概率。
 */

/*
 * 解析：n个骰子的所有点的数的排列数为6的n次方。所以求出每一个值对应的排序数，除以总
 * 排列数就可得出该值的概率。当骰子的所有点数为1时则值为n，当所有骰子的点数为6时值为
 * 6n。所以n个骰子的所有可能的值为n到6n，即有6n-n+1个可能的值。
 */

void ProbabilityRecursivly(int n, int index, int *pTable, int sum)
{
    if(index == n)
        pTable[sum - n]++;
    else
    {
        for(int i = 1; i <= 6; ++i)
        {
            sum += i;
            ProbabilityRecursivly(n, index + 1, pTable, sum);
            sum -= i;
        }
    }
}

void printProbability(int n)
{
    if(n < 1)
        return;

    double totalPermutation = pow(6, n); //n个骰子的所有排列为6^n
    int tableSize = 6*n - n + 1;
    int *SumTable = (int *)malloc(sizeof(int)*(tableSize));
    memset(SumTable, 0, sizeof(int) * tableSize);
    int sum = 0;
    for(int i = 1; i <= 6; ++i)
    {
        sum += i;
        ProbabilityRecursivly(n, 1, SumTable, sum);
        sum -= i;
    }
    for(int i = 0; i < tableSize; ++i)
        printf("sum:%d probability:%lf\n", n+i, SumTable[i]/totalPermutation);
    free(SumTable);
}

int main(int argc, const char *argv[])
{
    printProbability(2);
    return 0;
}
