/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : alpha.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/15 09:15:11
*  @Last Modified  : 2017/06/05 22:38:41
********************************************************************************
*/

#include <stdio.h>
#include <ctype.h>

/*
 * 小写字母-大写字母=32=2的5次方。所以小写字母和大写字母大二进制上的区别只是第5位，只
 * 要改变第5位就能改就字母的大小写
 */

//将字符串中的小写字母转换成大写
char *string_toupper(char *s)
{
    char *ptr = s;
    if(s == NULL)
        return NULL;
    while(*ptr != '\0')
    {
        if(isalpha(*ptr))
            *ptr &= ~32;
        ptr++;
    }
    return s;
}

//将字符串中的大写字母转换成小写
char *string_tolower(char *s)
{
    char *ptr = s;
    if(s == NULL)
        return NULL;
    while(*ptr != '\0')
    {
        if(isalpha(*ptr))
            *ptr |= 32;
        ++ptr;
    }
    return s;
}

//将字符串中的大写字母转换成小写，将小写字母转成大写字母
char *string_alpha_reverse(char *s)
{
    char *ptr = s;
    if(s == NULL)
        return NULL;
    while(*ptr != '\0')
    {
        if(isalpha(*ptr))
            *ptr ^= 32;
        ++ptr;
    }
    return s;
}

int main(int argc, char *argv[])
{
    char str[] = "This Is A Test!";
    printf("%s\n", string_alpha_reverse(str));
    printf("%s\n", string_toupper(str));
    printf("%s\n", string_tolower(str));
    return 0;
}
