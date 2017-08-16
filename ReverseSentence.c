/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReverseSentence.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/17 11:57:43
*  @Last Modified  : 2017/08/16 20:29:30
********************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//输入一个英文句子，翻转单词的顺序，但单词内的字符的顺序不变。为简单起见，标点
//符号的普通字母一样处理。例如输入字符串"I am a student."，则输出字符串
//"student. a am I"。

void Reverse(char *left, char *right)
{
    while(left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}

char *ReverseSentence(char *str)
{
    if(str == NULL) return NULL;
    Reverse(str, str + strlen(str) - 1);
    char *p = str;
    while(*p != '\0')
    {
        while(isspace(*p) && *p != '\0')
            ++p;
        char *temp = p;
        while(*p != ' ' && *p != '\0')
            ++p;
        Reverse(temp, p - 1);
    }
    return str;
}

//字符串的左旋操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋操作。比如输入字符串"abcdefg"和数
//字2，该函数将返回左旋转2位得到的结果"cdefgab"。
char *leftRotationString(char *str, int n)
{
    if(str == NULL || n <= 0)
    {
        return NULL;
    }

    int len = strlen(str);
    if(len > 0 && n > 0 && n < len)
    {
        Reverse(str, str + n - 1);              //翻转字符串的0-n个字符
        Reverse(str + n, str + len - 1);        //翻转剩下的字符
        Reverse(str, str + len - 1);            //翻转整个字符串
    }

    return str;
}

int main(int argc, char *argv[])
{
    char str[] = "I am a studunt.";
    char str2[] = "I am a studunt.";
    printf("%s\n", ReverseSentence(str));
    printf("%s\n", leftRotationString(str2, 5));
    return 0;
}
