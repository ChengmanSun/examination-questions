/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : strcpy.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/05 20:01:26
*  @Last Modified  : 2017/07/13 19:50:23
********************************************************************************
*/

#include <stdio.h>

char *strcpy(char *dst, const char *src)
{
    char *temp = dst;
    if(dst == NULL || src == NULL)
        return NULL;
    if(dst == src)
        return dst;
    while((*dst++ = *src++) != '\0')
        ;
    return temp;
}

char *strncpy(char *dst, int n, const char *src)
{
    char *temp = dst;
    if(dst == NULL || src == NULL || n <= 1)
        return NULL;
    if(dst == src)
        return dst;
    while((*dst++ = *src++) != '\0' && n--)
        ;
    return temp;
}

int main(int argc, const char *argv[])
{

    return 0;
}
