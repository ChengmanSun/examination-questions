/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : sort.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/16 16:00:12
*  @Last Modified  : 2017/07/26 10:28:43
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stack>
#include <algorithm>
#include <functional>

//------------------------------------------------------------------------------

//编译指令：g++ sort.cpp -std=c++11 -O3

void BubbleSort(int a[], int n)
{
    if(a == NULL || n < 2)
        return;

    int isSorted = true;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1 - i; ++j)
        {
            if(a[j] > a[j+1])
            {
                isSorted = false;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(isSorted)
            break;
    }
}

//------------------------------------------------------------------------------

void SelectSort(int a[], int n)
{
    if(a == NULL || n < 2)
        return;

    for(int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for(int j = i+1; j < n; ++j)
        {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

//------------------------------------------------------------------------------

/*
********************************************************************************
* Note : 直接插入排序。基本思想是不断取无序部分的第一个值插入有序部分。开始时设
*        数组第一个元素为有序部分。
********************************************************************************
*/
void InsertSort(int a[], int n)
{
    if(a == NULL || n < 2)
        return;

    for(int i = 1; i < n; ++i)                      //0到i是有序部分
    {
        if(a[i] < a[i-1])
        {
            int temp = a[i];                        //temp为要插入的数据
            int j = i-1;
            for(; j >= 0 && a[j+1] < a[j]; j -= 1)
                a[j+1] = a[j];
            a[j+1] = temp;                          //插入数据
        }
    }
}

//------------------------------------------------------------------------------

//使用了类似于冒泡排序的方法实现插入排序
void InsertSort2(int a[], int n, int (*compare)(int, int))
{
    if(a == NULL || n < 2 || compare == NULL)
        return;

    for(int i = 1; i < n; ++i)
    {
        for(int j = i-1; j >= 0 && a[j+1] < a[j]; --j)
        {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
}

//------------------------------------------------------------------------------

static void ShellInsert(int a[], int n, int k, bool (*compare)(int, int))
{
    for(int i = k; i < n; ++i)
    {
        if(compare(a[i], a[i-k]))
        {
            int temp = a[i];
            int j = i-k;
            for(; j >= 0 && compare(a[j+k], a[j]); j -= k)
                a[j+k] = a[j];
            a[j+k] = temp;
        }
    }
}

void ShellSort(int a[], int n, bool (*compare)(int, int))
{
    if(a == NULL || n < 2 || compare == NULL)
        return;
    for(int k = n/2; k >= 1; k /=2)
        ShellInsert(a, n, k, compare);
}

//------------------------------------------------------------------------------

//效率远远低于ShellInsert
static void ShellInsert2(int a[], int n, int k, bool (*compare)(int, int))
{
    for(int i = k; i < n; ++i)   
    {
        for(int j = i-k; j >= 0 && compare(a[j+1], a[j]); j -= k)
        {
            int temp = a[j];
            a[j] = a[j+k];
            a[j+k] = temp;
        }
    }
}

void ShellSort2(int a[], int n, bool (*compare)(int, int))
{
    if(a == NULL || n < 2 || compare == NULL)
        return;
    int k = n;
    while((k /= 2) >= 1)
        ShellInsert2(a, n, k, compare);
}

//------------------------------------------------------------------------------

/*
********************************************************************************
* Note :  当a[right]==pivot时仍然要让left或者right移步, 所快速排序的比较函数应该
*         返回1、-1、0三个值。
********************************************************************************
*/
//Partition第一种写法，这种写法的比较函数的返回值为 大于0，小于0，等于0 这三种值。
static int Partition(int a[], int low, int high, int (*compare)(int, int))
{
    //选中间的值作为基准数值，以防止如果数组已经有序时的最坏情况。
    // int pivot = a[low];  //直接先第一个数作为基准数值，但是当数组基本有序时将会是最坏情况。
    int middleIndex = low + (high - low) / 2;
    int pivot = a[middleIndex];
    a[middleIndex] = a[low];
    while(low < high)
    {
        while(low < high && compare(a[high], pivot) >= 0)
            high--;
        //直接写成a[low]=a[high]也是对的，但是当low==high时会有多余的赋值。
        //而且下面会重复比较一次a[low]和pivot
        // a[low] = a[high];
        if(low < high)
            a[low++] = a[high];
        while(low < high && compare(a[low], pivot ) <= 0)
            low++;
        //直接写成a[low]=a[high]也是对的，但是当low==high时会有多余的赋值。
        //而且下面会重复比较一次a[high]和pivot
        // a[high] = a[low];
        if(low < high)
            a[high--] = a[low];
    }
    a[low] = pivot;
    return low;
}

//快速排序递归法
void QuickSort(int a[], int low, int high, int (*compare)(int, int))
{
    if(a == NULL || low >= high || compare == NULL)
        return;

    int pivotIndex = Partition(a, low, high, compare);
    if(low < pivotIndex - 1)
        QuickSort(a, low, pivotIndex - 1, compare);
    if(high > pivotIndex + 1)
        QuickSort(a, pivotIndex + 1, high, compare);
}

//快速排序非递归法
void QuickSort(int a[], int n, int (*compare)(int, int))
{
    if(a == NULL || n < 2)
        return;
    std::stack<std::pair<int, int> > stk;
    stk.push(std::pair<int, int>(0, n - 1));
    while(!stk.empty())
    {
        std::pair<int, int> border = stk.top();
        stk.pop();
        int pivot = Partition(a, border.first, border.second, compare);
        if(border.first < pivot - 1)
            stk.push(std::pair<int, int>(border.first, pivot - 1));
        if(border.second > pivot + 1)
            stk.push(std::pair<int, int>(pivot + 1, border.second));
    }
}

//Partition第二种写法，这种写法的比较函数返回值只有true和false
static int Partition2(int a[], int low, int high, bool (*compare)(int, int))
{
    //选中间的值作为基准值，以防止如果数组已经有序时的最坏情况。
    int middleIndex = low + (high - low) / 2;
    std::swap(a[high], a[middleIndex]);

    int small = low - 1;
    for(int index = small + 1; index < high; ++index)
    {
        if(compare(a[index], a[high]))
        {
            ++small;
            if(small != index)
                std::swap(a[small], a[index]);
        }
    }
    std::swap(a[++small], a[high]);
    return small;
}

void QuickSort2(int a[], int low, int high, bool (*compare)(int, int))
{
    if(a == NULL || low >= high || compare == NULL)
        return;

    int pivotIndex = Partition2(a, low, high, compare);
    if(low < pivotIndex - 1)
        QuickSort2(a, low, pivotIndex - 1, compare);
    if(high > pivotIndex + 1)
        QuickSort2(a, pivotIndex + 1, high, compare);
}

//------------------------------------------------------------------------------

static void HeapAdjust(int heap[], int length, int i)
{
    //j指向左叶子结点
    int j = 2*i + 1;
    int temp = heap[i];
    while(j < length)
    {
        //如果存在右叶子结点，且右叶子结点较大，则j指向右叶子结点
        if(j < length - 1 && heap[j] < heap[j+1])
            ++j;
        if(temp >= heap[j])
            break;
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2*i + 1;
        }
    }
    heap[i] = temp;
}

static void HeapCreate(int heap[], int length)
{
    // length/2-1 为最后一个非叶子节点。
    for(int i = length / 2 - 1; i >= 0; --i)
        HeapAdjust(heap, length, i);
}

void HeapSort(int a[], int n)
{
    if(a == NULL || n < 2)
        return;
    HeapCreate(a, n);
    for(int index = n - 1; index > 0; --index)
    {
        //对于最大堆来说根节点就是最大值的节点。
        //每次取最大节点放在堆末尾，然后的大小减一，再重新生成最大堆。
        int temp = a[0]; a[0] = a[index]; a[index] = temp;
        HeapAdjust(a, index, 0);
    }
}

//------------------------------------------------------------------------------

//并归排序，循环实现
/*
 * static void Merge(int data[], int merge[], int n, int k)
 * {
 *     int i = 0;
 *     int mergeIndex = 0;
 *     //由于k的值为1 2 4 8，所以如果n是偶数，不会出现i+k>n时有数据没被从data复制到merge中的情况。
 *     //如果n为奇数，则当k==1时会把最后一个数据从data拷贝到merge中。然后当 k > 1 且 k*2 < n 时
 *     //最后一位数据都不会被比较排序，也就是不会从data中复制到merge中，但是没关系，这时候data和
 *     //merge中的最后一位数是相同的。直到当 k * 2 > n 时最后一位数据才会进行排序。
 *     while(i + k < n)
 *     {
 *         int i_end = i + k;
 *         int j = i_end;
 *         int j_end = j + k < n ?  j + k : n;
 *         while(i < i_end && j < j_end)
 *         {
 *             if(data[i] <= data[j])
 *                 merge[mergeIndex++] = data[i++];
 *             else
 *                 merge[mergeIndex++] = data[j++];
 *         }
 *         while(i < i_end)
 *             merge[mergeIndex++] = data[i++];
 *         while(j < j_end)
 *             merge[mergeIndex++] = data[j++];
 *         i = j_end;
 *     }
 * }
 * 
 * void MergeSort(int a[], int n)
 * {
 *     if(a == NULL || n < 2)
 *         return;
 *     int *pDataArray1 = a;
 *     int *pMergeArray = (int *)malloc(sizeof(int)*n);
 *     for(int k = 1; k < n; k *= 2)
 *     {
 *         //从DataArray排序合并数据到MergeArray
 *         Merge(pDataArray1, pMergeArray, n, k);
 *         //交换指针，使pDataArray1指向合并后的数据，然后再从DataArray合并数据到MergeArray
 *         std::swap(pDataArray1, pMergeArray);
 *     }
 * 
 *     if(pDataArray1 != a)
 *     {
 *         memcpy(a, pDataArray1, sizeof(int)*n);
 *         free(pDataArray1);
 *     }
 *     else
 *         free(pMergeArray);
 * }
 */

//并归排序递归实现
static void Merge(int data[], int copy[], int start, int end)
{
    if(start >= end)
        return;
    int middle = (start + end) / 2;
    Merge(copy, data, start, middle);
    Merge(copy, data, middle + 1, end);
    int i = start, j = middle + 1;
    int copyIndex = start;
    while(i <= middle && j <= end)
    {
        if(data[i] < data[j])
            copy[copyIndex++] = data[i++];
        else
            copy[copyIndex++] = data[j++];
    }
    while(i <= middle)
        copy[copyIndex++] = data[i++];
    while(j <= end)
        copy[copyIndex++] = data[j++];
}

void MergeSort(int a[], int n)
{
    if(a == NULL || n < 2)
        return;
    int *copy = (int *)malloc(sizeof(int) * n);
    //递归到最后第一次返回时并不确定是从a数组并归到copy数组，或者从copy数组并归到a数组。
    //所以刚开始需要使两个数组有相同的数据。
    memcpy(copy, a, sizeof(int) * n);
    Merge(a, copy, 0, n - 1);
    //数据最后被并归到了copy中，要把它复制回原来的数组中。
    memcpy(a, copy, sizeof(int) * n);
    free(copy);
}

//------------------------------------------------------------------------------

#define SIZE 500000
int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    int *array = new int[SIZE];
    int *array1 = new int[SIZE];

    srand(time(NULL));                                          //设置随机数种子
    for(unsigned i = 0; i < SIZE; ++i)
        array[i] = array1[i] = rand();                                      //生成随机数

    clock_t begin = clock();
    // BubbleSort(array, SIZE); 
    // SelectSort(array, SIZE); 
    // InsertSort(array, SIZE); 
    // InsertSort2(array, SIZE); 
    // ShellSort(array, SIZE, [](int a, int b)->bool{return a < b;}); 
    // ShellSort2(array, SIZE, [](int a, int b)->bool{return a < b;}); 
    // QuickSort(array, 0, SIZE - 1, [](int a, int b)->int{return a - b;});
    QuickSort(array, SIZE, [](int a, int b)->int{return a - b;});
    // QuickSort2(array, 0, SIZE - 1, [](int a, int b)->bool{return a < b;});
    // MergeSort(array, SIZE);
    // HeapSort(array, SIZE);
    // qsort(array1, SIZE, sizeof(int), [](const void*d1, const void*d2)->int{return *(int *)d1 - *(int *)d2;});
    std::sort(array1, array1+SIZE, std::less<int>());
    clock_t end = clock(); 
    printf("time ms:%ld\n", end - begin);

    for(unsigned i = 0; i < 100/* sizeof(array)/sizeof(int) */ ; ++i)
        printf("%d %d\n", array[i], array1[i]);

    delete []array;
    delete []array1;

    return 0;
}
