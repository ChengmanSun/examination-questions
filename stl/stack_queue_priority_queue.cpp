/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : stl.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/29 13:24:15
*  @Last Modified  : 2017/07/13 19:08:55
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <stack>
#include <queue>    //包括queue和priority_queue
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

//队列的主要方法为：  front()、push()、pop()、size()、empty()。pop()时出队的是最先入队的front()。
//优先队列的主要方法：top()、push()、pop()、size()、empty()。pop()时出队的是最大优先的top()。
//栈的主要方法为：    top()、push()、pop()、size()、empty()。pop()时出栈的是最后入栈的top()。

//优先队列，用比较方法在容器中使用堆算法，所以优先队列实际上是一个堆。
//默认情况下最大值具有最大的优先权，所在排在堆顶。所以默认是一个最大堆。
/*
 * namespace std
 * {                    类型            容器                            比较方法
 *      template<typename T, typename Container = vector<T>, typename Compare = less<T> >
 *      class priority_queue;
 * };
 */

//自定义优先队列的比较方法
class mycomp
{
    public:
        bool operator()(std::string s1, std::string s2)
        {
            return s1 > s2;
        }
};

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    srand(time(NULL));

    // std::priority_queue<int> pq; //默认
    // std::priority_queue<int, std::vector<int>, std::less<int> > pq;  //和默认一样，最大值具有最大优先
    std::priority_queue<int, std::deque<int>, std::greater<int> > pq;   //修改成最小值具有最大优先权
    for(int i = 0; i < 10; ++i)
        pq.push(rand()); 
    printf("priority_queue size: %llu\n", pq.size());
    while(!pq.empty())
    {
        printf("priority_queue top : %d\n", pq.top());
        pq.pop();
    }

    std::priority_queue<std::string, std::vector<std::string>, mycomp> mpq;
    mpq.push("Monday");
    mpq.push("Tuesday");
    mpq.push("Wednesday");
    mpq.push("Thursday");
    mpq.push("Friday");
    mpq.push("Saturday");
    mpq.push("Sunday");
    while(!mpq.empty())
    {
        printf("priority_queue top : %s\n", mpq.top().c_str());
        mpq.pop();
    }

    std::queue<int> q;
    std::stack<int> s;

    return 0;
}
