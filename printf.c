/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : printf.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/27 10:37:23
*  @Last Modified  : 2017/06/05 22:49:28
********************************************************************************
*/

#include <stdio.h>
#include <stdarg.h>

//由于函数说明：printf(const char *, ...)知，函数只有第一个参数的类型是确定的。
//所以printf("%d\n", 5.0f)和printf("%f\n", 5)无法正确显示字符，编译器传参时只
//是在printf的栈分配足够大的空间，然后将值原原本本地入栈，并没有进行隐式转换。
//而printf("%d\n", (int)5.0f)和printf("%f\n\n", (double)5)能够正确显示是因为
//入栈时分配的空间是强制转换后的类型需要的空间，然后把强制转换后的值入栈。

typedef struct {
    int a;
    float b;
} st_t;

void show(int n, ...)
{
    st_t t;
    va_list ap; 
    va_start(ap, n);
    while(n--)
    {
        t = va_arg(ap, st_t);
        printf("a:%d b:%f\n", t.a, t.b);
    }
    va_end(ap);
}

int main(int argc, char *argv[])
{
    printf("%d\n", 5.0f);
    printf("%f\n", 5);
    printf("%d\n", (int)5.0f);
    printf("%f\n\n", (double)5);

    st_t t1 = {1, 1.5f};
    st_t t2 = {10, 5.5f};
    show(2, t1, t2);

    return 0;
}
