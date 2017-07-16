/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : ReverseSentence.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/17 11:57:43
*  @Last Modified  : 2017/06/17 13:56:36
********************************************************************************
*/

#include <stdio.h>
#include <string.h>

//输入一个英文句子，翻转单词的顺序，但单词内的字符的顺序不变。为简单起见，标点
//符号的普通字母一样处理。例如输入字符串"I am a student."，则输出字符串
//"student. a am I"。
void Reverse(char *begin, char *end)
{
    while(begin < end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
}

char *ReverseSentence(char *str)
{
    if(str == NULL)
        return NULL;
    Reverse(str, str + strlen(str) - 1);
    char *begin, *end;
    begin = end = str;
    while(*end != '\0')
    {
        while(*end == ' ')
        {
            ++begin;
            ++end;
        }
        while(*end != ' ' && *end != '\0')
            ++end;
        Reverse(begin, end - 1);
        begin = end;
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

int main(int argc, const char *argv[])
{
    char str[] = "I am a studunt.";
    char str2[] = "I am a studunt.";
    printf("%s\n", ReverseSentence(str));
    printf("%s\n", leftRotationString(str2, 5));
    return 0;
}
