/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : memcpy.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/09/06 17:52:08
*  @Last Modified  : 2017/09/09 17:13:38
********************************************************************************
*/

#include <stdio.h>
#include <string.h>

//必须考虑内存重叠的情况和超出内存范围的情况。

//假设单片机的RAM地址从0x20000000开始，总共64K
#define MEM_SIZE 64 //64K
#define MEM_START 0x20000000UL
#define MEM_END (MEM_START + MEM_SIZE * 1024)

#define is_overload(dst_, src_, len_) \
        (dst_ < (void *)MEM_START || src_ < (void *)MEM_START || \
        (dst_ + len_) >= (void *)MEM_END || (src_ + len_) >= (void *)MEM_END)

void *my_memcpy(void *dst, void *src, size_t len)
{
    if(dst == NULL || src == NULL || dst == src || len <= 0)
        return NULL;
    //检测地址是否合法，测试时应该将它注销
    /*
     * if(is_overload(dst, src, len))
     *     return NULL;
     */
    char *d = (char *)dst, *s = (char *)src;
    if(s < d && s + len > d) //内存重叠，且源地址比目标地址小。
    {
        d += len - 1;
        s += len - 1;
        while(len--)
            *d-- = *s--;
    }
    else                    //内存不重叠，或者重叠但源地址比目标地址大。
    {
        while(len--)
            *d++ = *s++;
    }
    return dst;
}

int main(int argc, char *argv[])
{
    char s1[100] = "abcdefghigk";
    char *s2 = s1+5;
    void *ret = my_memcpy(s2, s1, strlen(s1) + 1);
    if(ret)
        printf("%s\n", ret);
    else
        printf("内存复制失败\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    return 0;
}
