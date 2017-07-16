#include <stdio.h>
//这个小程序如果在windows下用GCC编译，运行时会出错死循环的BUG。
//但是在windows下用其它编译器编译，或者在linux下用GCC编译都不会
//出现BUG。原因可能是windws下GCC把%h和%hh都当成了两个字节，导致
//往&temp中写数据时越界，修改了i的内容，导致死循环。
int main(int argc, char *argv[])
{
    char  temp;
    char str[] = "112233445566";

    for(int i = 0; i < 6; i++)
    {
        sscanf(str+i*2, "%2hhx", &temp);
        printf("%X\n", temp);
    }
    return 0;
}
