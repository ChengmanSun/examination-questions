/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : attribute_1.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/08/29 11:53:27
*  @Last Modified  : 2017/09/06 10:40:42
********************************************************************************
*/

#include <stdio.h>

//在windows下要使用msys-gcc编译器，mingw-gcc不支持__attribute__ ((packed))。

//设置对齐时，对齐的值必须是2的n次方。
//使用__attribute__ ((aligned (2^n)))修饰结构体时，表示结构体的实例所在地址必须在
//给定对齐数值的整数倍上。也表示结构体占据的空间必须是对齐数值的整数倍。

//__attribute__ ((aligned (2^n)))设置的对齐大小要比原对齐方式大，小于原对齐方式的值不被处理
struct S1
{
   char a;
   int b;
   short c;
} __attribute__ ((aligned (1)));

//结构体里的成员按其本身大小进行对齐
//结构体按4字节对齐，且结构体的大小为4的整数倍
struct S4
{
   char a;
   int b;
   short c;
} __attribute__ ((aligned (4)));

//结构体里的成员按其本身大小进行对齐
//结构体按8字节对齐，且结构体的大小为8的整数倍
struct S8
{
   char a;
   int b;
   short c;
} __attribute__ ((aligned (8)));

//结构体里的成员按其本身大小进行对齐
//结构体按64字节对齐，且结构体的大小为64的整数倍
struct S64
{
   char a;
   int b;
   short c;
} __attribute__ ((aligned (64)));

struct SPacked
{
   char a;
   int b;
   short c;
} __attribute__ ((packed));

struct S4 s4;
struct S8 s8;
struct S64 s64;
int __attribute__ ((aligned (32))) i; //变量i被定义在32对齐的地址上

int main(int argc, char *argv[])
{
    printf("s4 address:%p\n", &s4);     //s4在4字节对齐的地址上
    printf("s8 address:%p\n", &s8);     //s8在8字节对齐的地址上
    printf("s64 address:%p\n", &s64);   //s64在64字节对齐的地址上
    printf("S1:%llu\n", sizeof(struct S1));
    printf("S4:%llu\n", sizeof(struct S4));
    printf("S8:%llu\n", sizeof(struct S8));
    printf("S64:%llu\n", sizeof(struct S64));
    printf("SPacked:%llu\n", sizeof(struct SPacked));
    printf("address of i:%p\n", &i);
    return 0;
}
