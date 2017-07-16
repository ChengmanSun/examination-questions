/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : matrix_find.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/14 22:44:56
*  @Last Modified  : 2017/07/09 17:55:26
********************************************************************************
*/

/*
********************************************************************************
* Note :  题目：在一个二维数组中，每一行按照从左到右递增，每一列按照从上到下递增。
*         请写一个函数在二维数组中查找数值，如果找到则返回true，否则返回false;
*         解决的方法是从右上角或者左下角的点开始寻找。
* 
********************************************************************************
*/

#include <stdio.h>

int matrix[][4] = {
    {1, 2, 8, 9},
    {2, 4, 9, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}
};

bool isInMatrix(int *a, int rows, int columns, int value)
{
    if(a == NULL || rows <= 0 || columns <= 0)
        return false;
    int rowIndex = 0;
    int colIndex = columns - 1;
    while(rowIndex < rows && colIndex >= 0)
    {
        int temp = a[columns * rowIndex + colIndex];
        if(temp == value)
            return true;
        else if(temp > value)
            --colIndex; 
        else
            ++rowIndex;
    }
    return false;
}

int main(int argc, char *argv[])
{
    bool result;
    result = isInMatrix(&matrix[0][0], 4, 4, 1);
    printf("%s\n", result ? "found!" : "not found!");
    return 0;
}
