/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintMinNumber.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/15 17:07:19
*  @Last Modified  : 2017/08/15 15:44:40
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数。打印出能拼接出的数中最
//小的一个。例如输入数组{3, 32, 321}，则打印出这三个数组拼接出的最小整数321323。

#define BUFF_LENGTH 64

int strcompare(const void *p1, const void *p2)
{
    char strNum1[BUFF_LENGTH * 2];   
    char strNum2[BUFF_LENGTH * 2];   
    strcpy(strNum1, *(char **)p1);
    strcat(strNum1, *(char **)p2);
    strcpy(strNum2, *(char **)p2);
    strcat(strNum2, *(char **)p1);
    return strcmp(strNum1, strNum2);
}

void PrintMinNumber(int a[], int n)
{
    if(a == NULL || n < 1)
        return;
    char **strArray = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; ++i)
    {
        strArray[i] = (char *)malloc(sizeof(char) * BUFF_LENGTH);
        snprintf(strArray[i], BUFF_LENGTH, "%d", a[i]);
    }
    qsort(strArray, n, sizeof(char *), strcompare);
    for(int i = 0; i < n; ++i)
    {
        printf("%s ", strArray[i]);
        free(strArray[i]);
    }
    free(strArray);
}

int main(int argc, const char *argv[])
{
    int a[] = {3, 32, 321, 5};
    PrintMinNumber(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
