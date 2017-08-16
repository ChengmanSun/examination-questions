/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : subSet.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/15 13:28:24
*  @Last Modified  : 2017/07/13 16:08:19
********************************************************************************
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

//打印出集合的所有子集

/*
********************************************************************************
* 一个奇技淫巧的方法：一个n位数的二进制可以表示的数为2^n个数，而有n个元素的集合
* 的子集也正好有n个子集。所以可以遍历0--2^n的数，当数为x时对比二进制上的第个位，如
* 果为1则输出集合中对应的元素，为0则不输出。则x的输出为一个子集。
* 但是局限是只能求n<=32的集合的子集。
********************************************************************************
*/
void SubSet(int a[], int n)
{
    if(a == NULL || n <= 0 || n > 32)
        return;
    int num = pow(2, n);
    for(int i = 0; i < num; ++i)
    {
        for(int mask = 1, index = 0; mask != 0; mask <<= 1, ++index) 
            if(i & mask)
                printf("%d ", a[index]);
        printf("\n");
    }
}

/*
********************************************************************************
* Note : 递归法 
********************************************************************************
*/
void PrintSubSet(int a[], bool masks[], int length)
{
    for(int i = 0; i < length; ++i)
        if(masks[i])
            printf("%d ", a[i]);
    printf("\n");
}

int SubSetRecursively(int a[], bool masks[], int mask_index, int length)
{
    if(mask_index == length)
    {
        PrintSubSet(a, masks, length);
    }
    else
    {
        masks[mask_index] = true;
        SubSetRecursively(a, masks, mask_index+1, length);
        masks[mask_index] = false;
        SubSetRecursively(a, masks, mask_index+1, length);
    }
}

void SubSet2(int a[], int length)
{
    if(a == NULL || length <= 0)
        return;
    bool *masks = new bool[length];
    int mask_index = 0;
    std::fill(masks, masks+length, 0);
    // memset(masks, 0, sizeof(sizeof(bool)*length));
    SubSetRecursively(a, masks, mask_index, length);
    delete []masks;
}

//求一个集合的所有排序
void Permutation(int a[], int length, int start)
{
    if(start == length)
    {
        for(int i = 0; i < length; ++i)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        for(int i = start; i < length; ++i)
        {
            int temp = a[i];
            a[i] = a[start];
            a[start] = temp;
            Permutation(a, length, start+1);
            temp = a[i];
            a[i] = a[start];
            a[start] = temp;
        }
    }
}

void SetPermutation(int a[], int n)
{
    if(a == NULL || n <= 0)
        return;
    Permutation(a, n, 0);
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4};
    SubSet(a, sizeof(a)/sizeof(a[0]));
    printf("---------------------------------------------------------\n");
    SubSet2(a, sizeof(a)/sizeof(a[0]));
    printf("---------------------------------------------------------\n");
    SetPermutation(a, sizeof(a)/sizeof(a[0]));

    return 0;
}
