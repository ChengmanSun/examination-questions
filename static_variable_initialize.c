#include <stdio.h>

int g_i;

int main(int argc, char *argv[])
{
    int stack_i;
    static int s_i;

    printf("g_i:%d\n", g_i);
    printf("s_i:%d\n", s_i);
    printf("stack_i:%d\n", stack_i);

    return 0;
}


//使用visual studio 编译就可以看出未初始化的静态int变量（静态全局或者静态局部都一样）
//会被编译器自动初始化成0，而未初始化的局部变量的值是不确定的。
