/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : FindFirstNotRepeatingChar.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/15 21:29:44
*  @Last Modified  : 2017/08/12 17:14:34
********************************************************************************
*/

#include <stdio.h>

//在字符串中找出第一个只出现一次的字符。如输入“abaccdeff”则输出'b'。

char findFirstNotRepeatingChar(const char *str)
{
    if(str == NULL)
        return '\0';
    int HashTable[0xff] = {0};
    for(const char *c = str; *c != '\0'; ++c)
        HashTable[*c]++;
    for(int i = 0; i < sizeof(HashTable)/sizeof(HashTable[0]); ++i)
        if(HashTable[i] == 1)
            return i;
    return '\0';
}
