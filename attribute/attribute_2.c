/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : attribute_2.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/08/29 12:44:06
*  @Last Modified  : 2017/08/29 13:20:36
********************************************************************************
*/

#include <stdio.h>

//__attribute__ ((aligned (1)))只能设置比原对齐方式大的数值，小于原对齐方式的值不被处理
struct S
{
    __attribute__ ((aligned (1))) char a;
    __attribute__ ((aligned (1))) int b;
    __attribute__ ((aligned (1))) short c;
};

//虽然将a声明成了8字节对齐，但只是意味着a要放在8字节对齐的位置上，a仍然占用1个字节的空间。
//a占一个字节的空间，但是b要放在4字节对齐的位置，所以相当于a占用了4个字节的空间。
//b占用4个字节。
//c紧挨着b占用两个字节。
//由以上分析得struct S_1占用4+4+2=10个字节。
//但是由于struct S_1的成员中最大的对齐数为8，所以struct S_1也默认成8字节对齐。所以
//struct S_1的实际占用内存为8的整数位，最终可得struct S_1占用空间为2*8=16。
struct S_1
{
    __attribute__ ((aligned (8))) char a;
    int b;
    short c;
};

//a占一个字节的空间，但是b要放在8字节对齐的位置，所以相当于a占用了8个字节的空间。
//b占用4个字节。
//c紧挨着b占用两个字节。
//由以上分析得struct S_2占用8+4+2=14个字节。
//但是由于struct S_2的成员中最大的对齐数为8，所以struct S_2也默认成8字节对齐。所以
//struct S_2的实际占用内存为8的整数位，最终可得struct S_2占用空间为2*8=16。
struct S_2
{
    char a;
    __attribute__ ((aligned (8))) int b;
    short c;
};

//由于没有声明struct S_3的对齐数，所以struct S_3的对齐数等于其成员中最大的对齐数。
//a+b+c=8+8+2=18，但是struct S_3成员的最大对齐数为8所以应该占用3*8=24。
struct S_3
{
    char a;
    __attribute__ ((aligned (8))) int b;
    __attribute__ ((aligned (8))) short c;
};

//struct S_4的对齐数为32，所以struct S_4的实际大小为32的整数倍。
//所以占用32个字节，而不是24个字节。
struct S_4
{
    __attribute__ ((aligned (8))) char a;
    __attribute__ ((aligned (8))) int b;
    __attribute__ ((aligned (8))) short c;
} __attribute__ ((aligned (32)));

int main(int argc, char *argv[])
{
    printf("S:%llu\n", sizeof(struct S));
    printf("S_1:%llu\n", sizeof(struct S_1));
    printf("S_2:%llu\n", sizeof(struct S_2));
    printf("S_3:%llu\n", sizeof(struct S_3));
    printf("S_4:%llu\n", sizeof(struct S_4));

    struct S_1 s_1;
    printf("成员a和成员b相隔4个字节：\nS_1.a:%p S_1.b:%p\n", &s_1.a, &s_1.b);
    struct S_2 s_2;
    printf("成员a和成员b相隔8个字节：\nS_2.a:%p S_2.b:%p\n", &s_2.a, &s_2.b);

    return 0;
}
