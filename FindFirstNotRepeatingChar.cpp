/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : FindFirstNotRepeatingChar.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/15 21:29:44
*  @Last Modified  : 2017/10/12 14:39:34
********************************************************************************
*/

#include <stdio.h>

//在字符串中找出第一个只出现一次的字符。如输入“abaccdeff”则输出'b'。

char findFirstNotRepeatingChar(const char *str)
{
    if(str == NULL)
        return -1;
    int HashTable[256] = {0};
    for(const char *c = str; *c != '\0'; ++c)
        HashTable[*c]++;
    for(int i = 0; i < 256; ++i)
        if(HashTable[i] == 1)
            return i;
    return -1;
}
