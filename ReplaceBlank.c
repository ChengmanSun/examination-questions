/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : string_replay.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/15 09:49:17
*  @Last Modified  : 2017/06/06 16:08:54
********************************************************************************
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
********************************************************************************
* Note : 将字符串中的空格替换成"%20"，假设字符串有足够的空间使替换后不会越界，
*        请在原字符串上进行替换。 
*        如果有连续的空格，则在原字符上替换将会出错。
********************************************************************************
*/

//替换的字符串没有连续的多个空格
char *ReplaceBlank(char s[], int n)
{
    int len = 0, space_count = 0;
    char *p1, *p2;

    if(s == NULL || n <= 0)
        return NULL;

    p1 = s;
    while(*p1 != '\0')
    {
        if(isspace(*p1++))
            space_count++;
    }

    p2 = p1 + space_count  * 2;
    if(p2 > s+n-1)
        return NULL;

    while(p1 >= s)
    {
        if(!isspace(*p1))
            *p2-- = *p1--;
        else
        {
            p1--;
            *p2-- = '0', *p2-- = '2', *p2-- = '%';
        }
    }
    return s;
}

//替换的字符串如果有多个连续空格
char *ReplaceMultiBlank(char s[], int n)
{
    int newstring_len = 0, space_count = 0;
    char *p1, *p2;

    if(s == NULL || n < 1)
        return NULL;

    p1 = s;
    while(*p1 != '\0')
    {
        if(isspace(*p1++))
            ++space_count;
        else
            ++newstring_len;
        //跳过连续空格
        while(isspace(*p1))
            ++p1;
    }

    newstring_len += space_count*3;
    if(newstring_len+1 > n)
        return NULL;

    //由于可能有多个连续空格，所以替换后的字符串可以比原字符长也可以短。
    //所以必须把新字符串替换到数组的末尾。
    p2 = s + n - 1;
    while(p1 >= s)
    {
        if(isspace(*p1))
        {
            --p1;
            *p2-- = '0', *p2-- = '2', *p2-- = '%';
            while(isspace(*p1)) //去掉连续的空格
                --p1;
        }
        else
        {
            *p2-- = *p1--;
        }
    }

    memmove(s, p2+1, newstring_len+1);
    return s;
}

int main(int argc, const char *argv[])
{
    char str[100] = "We are happy.";
    char str1[100] = "We    are not  happy.";
    printf("%s\n", ReplaceBlank(str, sizeof(str)));
    printf("%s\n", ReplaceMultiBlank(str1, sizeof(str1)));
    return 0;
}
