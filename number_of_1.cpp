/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : number_of_1.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/01 23:24:31
*  @Last Modified  : 2017/08/15 12:07:37
********************************************************************************
*/

#include <stdio.h>

/* 题目：计算一个整数中有多少个位为1 */

/*
********************************************************************************
* Note : 这一题应该注意不能使用以下方法：
*        while(n)
*        {
*           if(n & 1)
*               ++count;
*           n >>= 1;
*        } 
*        原因是如果n是负数，则n右移不能去掉最高位的1（也就是符号位），所以会死
*        循环。
********************************************************************************
*/

//法一：
/*
 * int number_of_1(int n)
 * {
 *     int mask = 1;
 *     int count = 0;
 *     while(mask)
 *     {
 *         if(mask & n)
 *             ++count;
 *         mask <<= 1;
 *     }
 *     return count;
 * }
 */

//法二：
int number_of_1(int n)
{
    int count = 0;
    while(n)
    {
        // n = n&(n-1);
        n &= n - 1;
        ++count;
    }
    return count;
}

//由方法二可以引申出一个类似的题目：
//题：请判断一个数是否是2的n次方。
//解析：由1<<0==2^0, 1<<1==2^1, 1<<2==2^2 ... 可知，如果一个数是2的n次方，则该数
//中只有一个位是1，则n&(n-1)==0。
bool is2n(int n)
{
    if(n <= 0)
        return false;
    return !(n&(n-1));
}

int main(int argc, const char *argv[])
{
    printf("%d\n", number_of_1(0xffff));
    printf("%d\n", is2n(0));
    printf("%d\n", is2n(1));
    printf("%d\n", is2n(2));
    printf("%d\n", is2n(3));
    printf("%d\n", is2n(4));
    return 0;
}
