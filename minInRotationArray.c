/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : minInRotationArray.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/07/11 16:05:06
*  @Last Modified  : 2017/07/11 17:59:58
********************************************************************************
*/

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
//{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <stdio.h>

int minInOrder(int a[], int n)
{
    for(int i = 1; i < n; ++i)
        if(a[i-1] > a[i])
            return i;
}

//a[low] == a[middle] 有两种情况：
//第一种情况middle在旋转数组的后半部分，这时候a[low] == a[middle] && a[middle] == a[high]，就只能用遍历法寻找最小值。
//第二种情况middle在旋转数组的前半部分，这时候令low = middle + 1，然后继续寻找最小值。
int minInRotationArray(int a[], int n)
{
    if(a == NULL || n <= 0)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[low] == a[middle] && a[middle] == a[high])
            return minInOrder(a, n);
        if(middle > 0 && a[middle - 1] > a[middle])
            return middle;
        else if(a[low] <= a[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return 0; //如果没有找到a[middle - 1] > a[middle]的数，则说明这个旋转数组旋转了0个元素 
}

int main(int argc, const char *argv[])
{
    int a1[] = {3, 4, 5, 1, 2};
    int a2[] = {1, 1, 1, 1, 0, 1};
    int index = minInRotationArray(a1, sizeof(a1)/sizeof(a1[0]));
    printf("%d\n", a1[index]);
    index = minInRotationArray(a2, sizeof(a2)/sizeof(a2[0]));
    printf("%d\n", a2[index]);
    return 0;
}
