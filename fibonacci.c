/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : fibonacci.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/01 22:07:23
*  @Last Modified  : 2017/07/09 15:48:58
********************************************************************************
*/

#include <stdio.h>

/*
 * int fibonacci(int n)
 * {
 *     if(n <= 0)
 *         return 0;
 *     if(n == 1)
 *         return 1;
 *     return fibonacci(n-2) + fibonacci(n-1);
 * }
 */

int fibonacci(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    int a = 0, b = 1 , next;
    for(int i = 2; i <= n; ++i)
    {
        next = a + b;
        a = b;
        b = next;
    }
    return next;
}

//求斐波纳契数的前n项的和
long long fibonacci_sum(int n)
{
    if(n < 2)
        return n;
    int a = 0, b = 1, next, sum = a+b;
    for(int i = 2; i <= n; ++i)
    {
        next = a + b;
        a = b;
        b = next;
        sum += next;
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    printf("%d\n", fibonacci(0));
    printf("%d\n", fibonacci(1));
    printf("%d\n", fibonacci(2));
    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(4));
    printf("%d\n", fibonacci(5));

    printf("sum: %lld\n", fibonacci_sum(5));

    return 0;
}
