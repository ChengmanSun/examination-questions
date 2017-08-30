/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : attribute_3.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/08/29 20:14:33
*  @Last Modified  : 2017/08/29 20:36:04
********************************************************************************
*/

#include <stdio.h>

//所有的C编译器都支持#pragma关键字
//只有gun编译器才支持__attribute__关键字

#pragma pack(push)
#pragma pack(1)
struct S_Pragma
{
    char a;
    int b[2];
    double c;
};

struct S_Attribute
{
    char a;
    int b[2];
    double c;
} __attribute__ ((packed));

int main(int argc, char *argv[])
{
    printf("sizeof struct S_Pragma:%llu\n", sizeof(struct S_Pragma));
    printf("sizeof struct S_Attribute:%llu\n", sizeof(struct S_Attribute));
    return 0;
}
#pragma pack(pop)
