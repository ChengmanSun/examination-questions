/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : remainNumber.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/21 14:26:10
*  @Last Modified  : 2017/07/13 15:41:49
********************************************************************************
*/

//约瑟夫环

//0, 1, 2, 3...n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除每m个数字。
//求这个圆圈中剩下的最后一个数。

#include <stdio.h>
#include <stdlib.h>
#include <list>

/*
 * int remainNumber(int n, int m)
 * {
 *     int *array = (int *)malloc(sizeof(int) * n);
 *     for(int i = 0; i < n; ++i)
 *         array[i] = i;
 *     int count = 0;
 *     int lastNumber = array[0];
 *     while(1)
 *     {
 *         for(int i = 0; i < n; ++i)
 *         {
 *             if(array[i] > -1)
 *             {
 *                 if(count++ == m)
 *                 {
 *                     count = 0;
 *                     if(lastNumber == array[i])
 *                         return lastNumber;
 *                     else
 *                         array[i] = -1;
 *                 }
 *                 else
 *                     lastNumber = array[i];
 *             }
 *         }
 *     }
 *     free(array);
 * }
 */

int remainNumber(int n, int m)
{
    std::list<int> josephus;
    for(int i = 1; i <= n; ++i)
        josephus.push_back(i);
    int count = 1;
    while(josephus.size() > 1)
    {
        for(std::list<int>::iterator iter = josephus.begin(); iter != josephus.end();)
        {
            if(count++ == m)
            {
                count = 1;
                std::list<int>::iterator temp = iter++;
                // printf("%d ", *temp);
                josephus.erase(temp);
            }
            else
                ++iter;
        }
    }
    return *josephus.begin();
}

//用数学方法解题：
/*
 * int remainNumber(int n, int m)
 * {
 *     if(n < 1 || m < 1)
 *         return -1;
 *     int last = 0;
 *     for(int i = 2; i <= n; ++i)
 *         last = (last + m)%i;
 *     return last;
 * }
 */

int main(int argc, const char *argv[])
{
    int n = 10, m = 3;
    /* scanf("%d %d", &n, &m); */
    printf("total:%d steps:%d remain:%d\n", n, m, remainNumber(n, m));
    return 0;
}
