/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : strlen.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/05 19:22:39
*  @Last Modified  : 2017/06/05 20:08:04
********************************************************************************
*/

#include <stdio.h>
#include <string.h>

size_t mystrlen(const char *str)
{
    const char *ptr = str;
    if(ptr == NULL)
        return 0;
    while(*ptr++ != '\0')
        ;
    return ptr - str - 1;
}

int main(int argc, const char *argv[])
{
    int mlength = mystrlen("this is a test of my strlen.");
    int length = strlen("this is a test of my strlen.");
    printf("%d %d\n", mlength, length);
    return 0;
}
