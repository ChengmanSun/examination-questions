/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : stack_to_queue.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/06 20:58:03
*  @Last Modified  : 2017/08/16 20:52:01
********************************************************************************
*/

#include <stdio.h>
#include <stack>

template<typename T>
class Queue
{
private:
    std::stack<T> stk1;
    std::stack<T> stk2;
public:
    Queue(void){};
    ~Queue(void){};
    void push(const T &t);
    T pop(void);
    size_t size(void) const;
    bool isEmpty(void) const;
};

template<typename T>
void Queue<T>::push(const T &element)
{
    stk1.push(element);
}

template<typename T>
T Queue<T>::pop(void)
{
    if(stk1.empty() && stk2.empty())
        throw "queue is empty.";
    if(stk2.empty())
    {
        while(!stk1.empty())
        {
            T t = stk1.top();
            stk1.pop();
            stk2.push(t);
        }
    }
    T temp = stk2.top();
    stk2.pop();
    return temp;
}

template<typename T>
size_t Queue<T>::size(void) const
{
    return stk1.size() + stk2.size();
}

template<typename T>
bool Queue<T>::isEmpty(void) const
{
    return stk1.empty() && stk2.empty();
}

int main(int argc, char *argv[])
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    printf("size:%llu\npop:", q.size());
    while(!q.isEmpty())
        printf("%d ", q.pop());
    printf("\nsize:%llu\n", q.size());
    return 1;
}
