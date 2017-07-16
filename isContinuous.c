/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : isContinuous.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/07/13 11:13:50
*  @Last Modified  : 2017/07/13 13:00:15
********************************************************************************
*/

/*
 * 题. 从扑克牌中随机抽取5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2~10为数
 * 字本身，A为1，J为11，Q为12，K为13，而大小王可以看作是任意数字。
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}

int isContinuous(int array[], int length)
{
    if(array == NULL || length != 5)
        return 0;
    qsort(array, sizeof(int), length, compare);
    int KingCount = 0;
    int i = 0;
    for(; i < length && array[i] == 0; ++i)
        ++KingCount;
    
    int totalGap = 0;
    for(; i < length - 1; ++i)
    {
        int currGap = array[i+1] - array[i];
        if(currGap == 0) //两张牌相等，有对子就不可能是顺子。
            return 0;
        else if(currGap > 1)
            totalGap += currGap;
    }

    return KingCount > totalGap;
}
