/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : StringPermutation.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 13:07:50
*  @Last Modified  : 2017/08/17 19:24:28
********************************************************************************
*/

#include <stdio.h>

//输入一个字符串假设字符中没有重复的字符，打印出该字符串中字符的所有排序。

//这道题类似于：打印出1到n的所有数字。参考PrintOneToN.cpp

void swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Permutation(char *str, char *begin)
{
    if(begin[0] == '\0')
        printf("%s\n", str);
    else
    {
        for(char *ch = begin; *ch != '\0'; ++ch)
        {
            swap(begin, ch);//交换
            Permutation(str, begin+1);
            swap(begin, ch);//还原
        }
    }
}

void StringPermutation(char *str)
{
    if(str == NULL)
        return;
    Permutation(str, str);
}

int main(int argc, char *argv[])
{
    char str[] = "abcd";
    StringPermutation(str);
    return 0;
}
