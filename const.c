/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : const.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/22 10:29:05
*  @Last Modified  : 2017/05/22 14:43:55
********************************************************************************
*/

#include <ctype.h>
#include <stdio.h>

char *strToUpper(char *str)
{
    char *ptr = str;
    while(*str)
    {
        if(isalpha(*str))
            *str &= ~32;
        ++str;
    }
    return ptr;
}

void show1(const char *str)
{
    printf("%s\n", str++);
}

void show2(char const *str)
{
    printf("%s\n", str++);
}

void show3(char * const str)
{
    /* ++str;                  //错误, str不可变 */
    printf("%s\n", str);
}

int main(int argc, char *argv[])
{
    char str1[] = "string1";
    const char *str2 = "string2";   //str2和str3是变量指针指向常量字符串
    char const *str3 = "string3";   //“char const *”和“const char *”是等效的
    char * const str4 = "string4";  //str4是一个常量指针，常指针不可变

    strToUpper(str1);

    /*
     * str4 = str1;        //错误, str4不可变
     * str4 = str2;        //错误, str4不可变
     * str4 = str3;        //错误, str4不可变
     */

    show1(str1);
    show2(str2);
    show2(str3);
    show3(str4);

    return 0;
}
