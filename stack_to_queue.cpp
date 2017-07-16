/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : stack_to_queue.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/06 20:58:03
*  @Last Modified  : 2017/06/06 23:59:55
********************************************************************************
*/

#include <stdio.h>
#include <stack>

template<typename T>
class Queue
{
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
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
    stack1.push(element);
}

template<typename T>
T Queue<T>::pop(void)
{
    if(stack1.empty() && stack2.empty())
        throw "queue is empty.";
    if(stack2.empty())
    {
        while(!stack1.empty())
        {
            T t = stack1.top();
            stack1.pop();
            stack2.push(t);
        }
    }
    T temp = stack2.top();
    stack2.pop();
    return temp;
}

template<typename T>
size_t Queue<T>::size(void) const
{
    return stack1.size() + stack2.size();
}

template<typename T>
bool Queue<T>::isEmpty(void) const
{
    return stack1.empty() && stack2.empty();
}

int main(int argc, const char *argv[])
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    printf("size:%d\npop:", q.size());
    while(!q.isEmpty())
        printf("%d ", q.pop());
    printf("\nsize:%d\n", q.size());
    return 1;
}
