/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : GetLeastNumber.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/14 15:43:22
*  @Last Modified  : 2017/07/10 17:13:55
********************************************************************************
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

//寻找数组中最小的K个数值

//方法一：使用快速排序思想，让patition返回值不断逼近K

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
            --high;
        if(low < high)
            a[low++] = a[high];
        while(low < high && a[low] <= pivot)
            ++low;
        if(low <high)
            a[high--] = a[low];
    }
    a[low] = pivot;
    return low;
}

void GetLeastNumber(int input[], int n, int output[], int k)
{
    if(input == NULL || output == NULL || n < k || n <= 0 || k <= 0)
        return;

    if(n != k) //如果n==K则直接把input中的数据都复制给output
    {
        int index = partition(input, 0, n - 1);
        while(index != k)
        {
            if(index < k)
                index = partition(input, index+1, n-1);
            else
                index = partition(input, 0, index-1);
        }
    }

    for(int i = 0; i < k; ++i)
        output[i] = input[i];
}

//方法二：建一个大小为K的容器，遍历数组往K里埴数据，K满后不断比较数组中的数和K
//中的最大值，或比最大值小则去掉原来的最大值，并埴入新值。
typedef std::multiset<int, std::greater<int> > IntSet;
void GetLeastNumber(std::vector<int> &data, IntSet &leastNumber, int k)
{
    if(data.empty() || data.size() < k)
        return;

    for(auto it = data.begin(); it != data.end(); ++it)
    {
        if(leastNumber.size() < k)
            leastNumber.insert(*it);
        else
        {
            if(*it < *leastNumber.begin())
            {
                leastNumber.erase(leastNumber.begin());
                leastNumber.insert(*it);
            }
        }
    }
}

//方法三，使用优先队列
//使用less作为比较，则最大的数会被放在top()位置。
typedef std::priority_queue<int, std::vector<int>, std::less<int> > PriorityQueue;
void GetLeastNumber(int a[], int n, PriorityQueue &output, int k)
{
    PriorityQueue empty_queue = PriorityQueue();
    output.swap(empty_queue); //由于优先队列没有clear()函数，所以只能用这个方法清除。

    for(int i = 0; i < n; ++i)
    {
        if(output.size() < k)
            output.push(a[i]);
        else
        {
            if(a[i] < output.top())
            {
                output.pop();
                output.push(a[i]);
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {1, 4, 5, 8, 6, 7, 9, 3, 2};
    int b[] = {1, 4, 5, 8, 6, 7, 9, 3, 2};
    int min[3];
    GetLeastNumber(a, sizeof(a)/sizeof(a[0]), min, sizeof(min)/sizeof(min[0]));
    for(int i = 0; i < sizeof(min)/sizeof(min[0]); ++i)
        printf("%d ", min[i]);

    printf("\n");

    std::vector<int> data = {b, b+sizeof(b)/sizeof(b[0])};
    IntSet leastNumber;
    GetLeastNumber(data, leastNumber, 3);
    for(auto it = leastNumber.begin(); it != leastNumber.end(); ++it)
        printf("%d ", *it);
    printf("\n");

    PriorityQueue queue;
    GetLeastNumber(b, sizeof(b)/sizeof(b[0]), queue, 3);
    while(!queue.empty())
    {
        printf("%d ", queue.top());
        queue.pop();
    }

    return 0;
}
