/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : BinarySearch.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/19 10:19:15
*  @Last Modified  : 2017/07/11 16:40:16
********************************************************************************
*/

#include <stdio.h>

//模板函数使用只使用了小于比较函数，类型T如果是类或者结构体则只需要实现小于比较函
//就可以实现二分查找。
template<typename T>
int binary_search(T a[], int n, T key)
{
    int low = 0, high = n - 1, middle;

    if(a == NULL || n < 1)
        return -1;

    while(low <= high)
    {
        // middle = (low + high) / 2;
        middle = low + (high - low) / 2;
        if(a[middle] < key)
            low = middle + 1;
        else if(key < a[middle])
            high = middle - 1;
        else
            return middle;
    }
    return -1;
}

//二分查找循环方式实现
int BinarySearch(int a[], int n, int key)
{
    int low = 0, middle, high = n - 1;

    if(a == NULL || n < 1)
        return -1;

    while(low <= high)
    {
        middle = (low + high) / 2;
        if(a[middle] == key)
            return middle;
        else if(a[middle] < key)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

//二分查找递归方式实现
int BinarySearch(int a[], int low, int high, int key)
{
    if(a == NULL || low > high)
        return -1;

    // int middle = (low + high) / 2;
    int middle = low + (high - low) / 2;

    if(a[middle] == key)
        return middle;
    else if(a[middle] > key)
        return BinarySearch(a, low, middle-1, key);
    else
        return BinarySearch(a, middle+1, high, key);
}

//查找第一个大于key的成员的下标
/*
 * int firstGreater(int a[], int n, int key)
 * {
 *     int low = 0, high = n - 1, middle;
 * 
 *     if(a == NULL || n < 1)
 *         return -1;
 * 
 *     while(low < high)
 *     {
 *         // middle = (low + high) / 2;
 *         middle = low + (high - low) / 2;
 *         if(a[middle] <= key)
 *             low = middle + 1;
 *         else
 *             high = middle;
 *     }
 *     return a[high] > key ? high : -1;
 * }
 */

int firstGreater(int a[], int n, int key)
{
    if(a == NULL || n <= 0)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] <= key)
            low = middle + 1;
        else
        {
            if(middle == 0 || a[middle - 1] <= key)
                return middle;
            else
                high = middle - 1;
        }
    }
    return -1;
}

//查找大于或者第一个等于的成员的下标 (>=)
/*
 * int firstGreaterOrEqual(int a[], int n, int key)
 * {
 *     int low = 0, high = n - 1, middle;
 * 
 *     if(a == NULL || n < 1)
 *         return -1;
 * 
 *     while(low < high)
 *     {
 *         // middle = (low + high) / 2;
 *         middle = low + (high - low) / 2;
 *         if(a[middle] < key)
 *             low = middle + 1;
 *         else
 *             high = middle;
 *     }
 *     return a[high] < key ? -1 : high;;
 * }
 */

int firstGreaterOrEqual(int a[], int n, int key)
{
    if(a == NULL || n <= 0)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] < key)
            low = middle + 1;
        else
        {
            if(middle == 0 || a[middle - 1] < key)
                return middle;
            else
                high = middle - 1;
        }
    }
    return -1;
}

//查找第一个小于key的成员的下标(<)
/*
 * int firstLess(int a[], int n, int key)
 * {
 *     int low = 0, high = n - 1, middle;
 * 
 *     if(a == NULL || n < 1)
 *         return -1;
 * 
 *     while(low < high)
 *     {
 *         // middle = (low + high + 1) / 2;
 *         middle = low + (high - low + 1) / 2;
 *         if(a[middle] < key)
 *             low = middle;
 *         else
 *             high = middle - 1;
 *     }
 *     return a[low] < key ? low : -1;
 * }
 */

int firstLess(int a[], int n, int key)
{
    if(a == NULL || n <= 0)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] >= key)
            high = middle - 1;
        else
        {
            if(middle == 0 || a[middle + 1] >= key)
                return middle;
            else
                low = middle + 1;
        }
    }
    return -1;
}

int firstLessOrEqual(int a[], int n, int key)
{
    int greaterIndex = firstGreater(a, n, key);
    if(greaterIndex >= 0)
        return greaterIndex - 1;
    else
        return -1;
}

int findFirst(int a[], int n, int value)
{
    if(a == NULL || n <= 0)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] == value)
        {
            if(middle == 0 || a[middle - 1] < value)
                return middle;
            else
                high = middle - 1;
        }
        else if(a[middle] < value)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

int findLast(int a[], int n, int value)
{
    if(a == NULL || n < 1)
        return -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] == value)
        {
            if(middle == n - 1 || a[middle+1] > value)
                return middle;
            else
                low = middle + 1;
        }
        else if(a[middle] < value)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return - 1;
}

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    int key;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10, 11, 12, 13, 14, 15 };
    scanf("%d", &key);
    // int index = binary_search(array, sizeof(array)/sizeof(array[0]), key);  
    // int index = BinarySearch(array, sizeof(array)/sizeof(array[0]), key);  
    // int index = BinarySearch(array, 0, sizeof(array)/sizeof(array[0]) - 1, key); 
    // int index = firstGreater(array, sizeof(array)/sizeof(array[0]), key);
    // int index = firstLess(array, sizeof(array)/sizeof(array[0]), key);
    // int index = firstGreaterOrEqual(array, sizeof(array)/sizeof(array[0]), key);
    int index = firstLessOrEqual(array, sizeof(array)/sizeof(array[0]), key);
    // int index = lastEqual(array, sizeof(array)/sizeof(array[0]), key);
    printf("index:%d\n", index);
    return 0;
}
