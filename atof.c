/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : atof.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/16 23:41:37
*  @Last Modified  : 2017/08/16 21:00:54
********************************************************************************
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(const char *str)
{
    char c;
    int sign = 1;       //符号处理
    int integer = 1;   //用来表明当前处理的是整数部分还是小数部分
    float d = 10.0f;    //小数点的位数
    long long i = 0;

    if(str == NULL)
        return 0.0f;

    while(isspace(*str))
        ++str;
    if((c = *str) == '-')
        sign = -1;
    if(c == '-' || c == '+')
        ++str;

    while((c = *str++) != '\0')
    {
        if(isdigit(c))
        {
            if(integer)
                i = i*10 + (c - '0');
            else
            {
                i += (c - '0') / d;
                d *= 10.0f;
            }
        }
        else if(c == '.')
            integer = 0; //开始处理小数部分
    }

    if(c == 'e' || c == 'E')
    {
        //科学计数法。
    }

    return sign < 0 ? -d : d;
}

int main(int argc, char *argv[])
{
    printf("%lf\n", atof("-0.1256"));
    return 0;
}
