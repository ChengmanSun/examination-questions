/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : container_of.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/08/25 14:03:59
*  @Last Modified  : 2017/08/25 14:34:06
********************************************************************************
*/

#include <stdio.h>

//如果知道知道结构体类型，以及结构体某个成员的指针，求成员指针所在结构体实例的内存首地址。

#define container_of(ptr, type, member) ((void *)ptr - (size_t)&(((type *)0)->member))

typedef struct ContainerTest
{
    int a;
    int b;
    int c;
} ContainerTest;

int main(int argc, char *argv[])
{
    ContainerTest con = {1, 2, 3};
    int *pb = &con.b;
    ContainerTest *pCon = (ContainerTest *)container_of(pb, ContainerTest, b);
    printf("%p\n", pb);
    printf("%p\n", &(((ContainerTest *)0)->b));
    printf("%p\n", pCon);
    return 0;
}
