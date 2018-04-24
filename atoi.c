/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : atoi.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/17 00:14:09
*  @Last Modified  : 2017/10/11 23:59:47
********************************************************************************
*/

#include <stdio.h>
#include <ctype.h>

int atoi(const char *str)
{
    char c;
    int value = 0;
    int sign = 1; //if '-' then negative, otherwise positive.

    if(str == NULL)
        return 0;

    while(isspace(*str))
        ++str;
    if((c = *str) == '-')
        sign = -1;
    if(c == '-' || c == '+')
        ++str;
    while(isdigit(c = *str++))
    {
        value = value*10 + (c - '0');
    }
    return sign * value;
}

int main(int argc, char *argv[])
{
    printf("%d\n", atoi("-1234a5678"));
    return 0;
}
