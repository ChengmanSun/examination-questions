/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : PrintMatrixClockwisely.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 15:26:58
*  @Last Modified  : 2017/07/12 11:34:07
********************************************************************************
*/

#include <stdio.h>

void PrintMatrixInCircle(int *a, int rows, int columns, int start)
{
    int endX = columns - start -1;
    int endY = rows - start - 1;
    for(int i = start; i <= endX; ++i)
        printf("%d ", a[columns * start + i]);
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; ++i)
            printf("%d ", a[columns * i + endX]);
    }
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; --i)
            printf("%d ", a[columns * endY + i]);
    }
    if(start < endX && start < endY - 1)
    {
        for(int i = endY - 1; i > start; --i)
            printf("%d ", a[columns * i + start]);
    }
}

void PrintMatrixClockwisely(int *a, int rows, int columns)
{
    if(a == NULL || rows <= 0 || columns <= 0)
        return;
    int start = 0;
    while(start*2 < rows && start*2 < columns)
    {
        PrintMatrixInCircle(a, rows, columns, start);
        ++start;
    }
}

int main(int argc, const char *argv[])
{
    int matrix[][6] = {{1, 3, 3, 5, 8, 9},
                       {9, 4, 3, 2, 1, 4},
                       {8, 9, 3, 5, 2, 1}};
    PrintMatrixClockwisely(&matrix[0][0], 3, 6);
    return 0;
}
