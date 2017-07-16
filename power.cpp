/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : power.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 17:24:46
*  @Last Modified  : 2017/07/12 10:06:22
********************************************************************************
*/

#include <stdio.h>
#include <math.h>

//写一个求平方的函数

bool g_InvalidInput = false;

inline bool fequal(double num1, double num2)
{
    return fabs(num1 - num2) < 0.000001;
}

double PowerWidthUnsignedExponent(int base, unsigned int exponent)
{
    double result = 1.0;
    for(unsigned int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

double pow(double base, int exponent)
{
    if(fequal(base, 0.0) && exponent < 0) //0的0次方无意义
    {
        g_InvalidInput = true;
        return 0.0;
    }
    g_InvalidInput = false;
    double result = PowerWidthUnsignedExponent(base, abs(exponent));
    if(exponent < 0)
        result = 1 / result;
    return result;
}
