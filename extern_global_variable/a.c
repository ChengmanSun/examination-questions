/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : a.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/09/04 16:42:36
*  @Last Modified  : 2017/09/04 16:47:02
********************************************************************************
*/

#include <stdio.h>

int var;
void printf_a_global(void)
{
    var = 100;
    printf("将a文件中未初始化全局变量var赋值为100:%d\n", var);
}
