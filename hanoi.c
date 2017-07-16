/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : hanoi.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 22:48:23
*  @Last Modified  : 2017/07/10 17:48:25
********************************************************************************
*/

#include <stdio.h>

//汉诺塔问题

//                      A           B           C
void hanoi(int n, char from, char depend, char to)
{
    if(n == 1)
        printf("from %c to %c\n", from, to);    //当剩下最后一个盘子时，直接移动要目的地。
    else
    {
        hanoi(n - 1, from, to, depend);         //n-1个盘子借助C移动到B(不管怎么移动，反正是可行的)
        printf("from %c to %c\n", from, to);    //剩下的1个盘子直接移动到C
        hanoi(n - 1, depend, from, to);         //再把B中剩下的盘子借助A移动到C(不管怎么移动反正可行)
    }
}

int main(int argc, const char *argv[])
{
    char from = 'A', depend = 'B', to = 'C';
    hanoi(64, from, depend, to);
    return 0;
}
