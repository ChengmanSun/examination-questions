/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : main.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/09/04 16:46:14
*  @Last Modified  : 2017/09/04 17:04:40
********************************************************************************
*/

#include <stdio.h>

extern void printf_a_global(void);
extern void printf_b_global(void);
extern int var;

int main(int argc, char *argv[])
{
    printf_a_global();
    printf_b_global();
    printf("从main.c中访问var:%d\n", var);
    return 0;
}
