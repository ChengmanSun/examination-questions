/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : b.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/09/04 16:44:54
*  @Last Modified  : 2017/09/04 17:06:17
********************************************************************************
*/

#include <stdio.h>

int var;
void printf_b_global(void)
{
    var = 1;
    printf("将b文件中未初始化全局变量var赋值为1:%d\n", var);
}
