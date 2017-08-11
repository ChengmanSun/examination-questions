/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : strcpy.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/05 20:01:26
*  @Last Modified  : 2017/08/11 10:59:28
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
    if(dst == NULL || src == NULL || n <= 1)
        return NULL;
    if(dst == src)
        return dst;
    char *temp = dst;
    int cpylen = 0;
    while(cpylen < n && (*dst++ = *src++) != '\0')
        ++cpylen;
    if(cpylen == n)
        dst[n - 1] = '\0';
    return temp;
}

int main(int argc, const char *argv[])
{

    return 0;
}
