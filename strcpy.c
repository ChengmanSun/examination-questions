/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : strcpy.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/05 20:01:26
*  @Last Modified  : 2017/08/17 16:31:29
********************************************************************************
*/

#include <stdio.h>

char *mystrcpy(char *dst, const char *src)
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

char *mystrncpy(char *dst, int n, const char *src)
{
    if(dst == NULL || src == NULL || n < 2)
        return NULL;
    if(dst == src)
        return dst;
    int cpyIndex = 0;
    while(cpyIndex < n && (dst[cpyIndex] = src[cpyIndex]) != '\0')
        ++cpyIndex;
    if(cpyIndex == n)
        dst[n - 1] = '\0';
    return dst;
}

int main(int argc, char *argv[])
{
    char dst[10];
    char src[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", mystrncpy(dst, sizeof(dst)/sizeof(dst[0]), src));
    return 0;
}
