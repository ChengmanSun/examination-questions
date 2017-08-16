/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : BinarySearch.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/19 10:19:15
*  @Last Modified  : 2017/08/11 14:52:06
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

int findFirstEqual(int a[], int n, int key)
{
    if(a == NULL || n < 1) return -1;
    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] < key)
            low = middle + 1;
        else /* if (a[middle] >= key) */
            high = middle;
    }
    return a[low] == key ? low : -1;
}

//查找第一个大于key的成员的下标
//uper_bound(int a[], int n, int key)
int firstGreater(int a[], int n, int key)
{
    if(a == NULL || n < 1)
        return -1;
    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] <= key)
            low = middle + 1;
        else
            high = middle;
    }
    return a[low] > key ? high : -1;
}

//查找大于或者第一个等于的成员的下标 (>=)
// int lower_bound(int a[], int n, int key)
int firstGreaterOrEqual(int a[], int n, int key)
{
    if(a == NULL || n < 1)
        return -1;

    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low) / 2;
        if(a[middle] < key)
            low = middle + 1;
        else
            high = middle;
    }
    return a[high] >= key ? high : -1;
}

int findLastEqual(int a[], int n, int key)
{
    if(a == NULL || n < 1)
        return -1;
    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low + 1) / 2;
        if(a[middle] <= key)
            low = middle;
        else
            high = middle - 1;
    }
    return a[low] == key ? low : -1;
}

//查找最后一个小于key的成员的下标(<)
int lastLess(int a[], int n, int key)
{
    if(a == NULL || n < 1)
        return -1;

    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low + 1) / 2;
        if(a[middle] < key)
            low = middle;
        else
            high = middle - 1;
    }
    return a[low] < key ? low : -1;
}

int lastLessOrEqual(int a[], int n, int key)
{
    if(a == NULL || n < 1)
        return -1;
    int low = 0, high = n - 1;
    while(low < high)
    {
        int middle = low + (high - low + 1) / 2;
        if(a[middle] <= key)
            low = middle;
        else
            high = middle - 1;
    }
    return a[low] <= key ? low : -1;
}

//------------------------------------------------------------------------------

/*
 * //uper_bound(int a[], int n, int key)
 * int firstGreater(int a[], int n, int key)
 * {
 *     if(a == NULL || n <= 0)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] <= key)
 *             low = middle + 1;
 *         else
 *         {
 *             if(middle == 0 || a[middle - 1] <= key)
 *                 return middle;
 *             else
 *                 high = middle - 1;
 *         }
 *     }
 *     return -1;
 * }
 * 
 * // int lower_bound(int a[], int n, int key)
 * int firstGreaterOrEqual(int a[], int n, int key)
 * {
 *     if(a == NULL || n <= 0)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] < key)
 *             low = middle + 1;
 *         else
 *         {
 *             if(middle == 0 || a[middle - 1] < key)
 *                 return middle;
 *             else
 *                 high = middle - 1;
 *         }
 *     }
 *     return -1;
 * }
 * 
 * int lastLess(int a[], int n, int key)
 * {
 *     if(a == NULL || n <= 0)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] >= key)
 *             high = middle - 1;
 *         else
 *         {
 *             if(middle == 0 || a[middle + 1] >= key)
 *                 return middle;
 *             else
 *                 low = middle + 1;
 *         }
 *     }
 *     return -1;
 * }
 * 
 * int lastLessOrEqual(int a[], int n, int key)
 * {
 *     if(a == NULL || n < 1)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] > key)
 *             high = middle - 1;
 *         else
 *         {
 *             if(middle == n - 1 || a[middle + 1] > key)
 *                 return middle;
 *             else
 *                 low = middle + 1;
 *         }
 *     }
 *     return -1;
 * }
 * 
 * int findFirstEqual(int a[], int n, int key)
 * {
 *     if(a == NULL || n <= 0)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] == key)
 *         {
 *             if(middle == 0 || a[middle - 1] < key)
 *                 return middle;
 *             else
 *                 high = middle - 1;
 *         }
 *         else if(a[middle] < key)
 *             low = middle + 1;
 *         else
 *             high = middle - 1;
 *     }
 *     return -1;
 * }
 * 
 * int findLastEqual(int a[], int n, int key)
 * {
 *     if(a == NULL || n < 1)
 *         return -1;
 *     int low = 0, high = n - 1;
 *     while(low <= high)
 *     {
 *         int middle = low + (high - low) / 2;
 *         if(a[middle] == key)
 *         {
 *             if(middle == n - 1 || a[middle+1] > key)
 *                 return middle;
 *             else
 *                 low = middle + 1;
 *         }
 *         else if(a[middle] < key)
 *             low = middle + 1;
 *         else
 *             high = middle - 1;
 *     }
 *     return - 1;
 * }
 */

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int key;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10, 11, 12, 14, 15 };
    scanf("%d", &key);
    // int index = binary_search(array, sizeof(array)/sizeof(array[0]), key);  
    // int index = BinarySearch(array, sizeof(array)/sizeof(array[0]), key);  
    // int index = BinarySearch(array, 0, sizeof(array)/sizeof(array[0]) - 1, key); 
    // int index = firstGreater(array, sizeof(array)/sizeof(array[0]), key);
    // int index = firstGreaterOrEqual(array, sizeof(array)/sizeof(array[0]), key);
    // int index = lastLess(array, sizeof(array)/sizeof(array[0]), key);
    // int index = lastLessOrEqual(array, sizeof(array)/sizeof(array[0]), key);
    int index = findFirstEqual(array, sizeof(array)/sizeof(array[0]), key);
    // int index = findLastEqual(array, sizeof(array)/sizeof(array[0]), key);
    printf("index:%d\n", index);
    return 0;
}
