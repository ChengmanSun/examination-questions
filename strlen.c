/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : strlen.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/05 19:22:39
*  @Last Modified  : 2017/08/17 19:31:05
********************************************************************************
*/

#include <stdio.h>
#include <string.h>

size_t mystrlen(const char *str)
{
    if(str == NULL)
        return 0;
    const char *ptr = str;
    while(*ptr != '\0')
        ++ptr;
    return ptr - str;
}

int main(int argc, char *argv[])
{
    int mlength = mystrlen("this is a test of my strlen.");
    int length = strlen("this is a test of my strlen.");
    printf("%d %d\n", mlength, length);
    return 0;
}
