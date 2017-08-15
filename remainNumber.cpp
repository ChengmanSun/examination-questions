/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : remainNumber.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/21 14:26:10
*  @Last Modified  : 2017/08/15 21:02:06
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
    std::list<int> lst;
    for(int i = 1; i <= n; ++i)
        lst.push_back(i);
    std::list<int>::iterator iter = lst.begin();
    while(lst.size() > 1)
    {
        for(int i = 1; i < m; ++i)
            if(++iter == lst.end()) //必须是++iter，如果是iter++将会段错误
                iter = lst.begin();
        std::list<int>::iterator temp = iter;
        if(++iter == lst.end()) iter = lst.begin();
        // printf("%d\n", *temp);
        lst.erase(temp);
    }
    return lst.front();
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
