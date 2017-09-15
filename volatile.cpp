/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : volatile.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/20 17:42:52
*  @Last Modified  : 2017/09/09 15:33:51
********************************************************************************
*/

#include <stdio.h>
#include <thread>
// #include <windows.h>
#include <unistd.h>

/*
 * volatile关键字的功能：
 * (1). volatile作为指令关键字，具有确保条指令不会因编译器的优化而省略的功能。如下：
 * unsigned char XByte[3] = 0;
 * XByte[0] = 0x34;
 * XByte[0] = 0x36;
 * XByte[0] = 0x3f;
 * 对外部硬件而言，上述4条语句表示4个不同的操作，会产生4个不同的动作。而编译器会对其
 * 进行优化，只认为 最后一句XByte[0] = 0x3f 是有用的赋值语句，而忽略其它赋值语句。如果使用
 * volatile来声明XByte，则所有的赋值语句都会被执行。
 * (2). 使用volatile关键字修饰的变量可以被未知因素修改。当要使用volatile变量时，系统
 * 会重新从它的地址处访问该变量，而不是从寄存器中访问该变量的缓存。所以跨线程和ISR的
 * 变量必须定义成volatile变量。
 */

// volatile bool flag = false;
bool flag = false;

void thread1_process(void)
{
    while(1)
    {
        usleep(1);
        flag = !flag;
    }
}

void thread2_process(void)
{
    while(1)
    {
        usleep(2);
        printf("flag:%d\n", flag);
        fflush(stdout);
    }
}

int main(int argc, char *argv[])
{
    volatile unsigned char XByte[3] = {0};
    XByte[0] = 0x34;
    XByte[1] = 0x36;
    XByte[2] = 0x3f;

    std::thread thread1(thread1_process);
    std::thread thread2(thread2_process);
    thread1.detach();
    thread2.detach();
    while(1)
        ;
    return 0;
}
