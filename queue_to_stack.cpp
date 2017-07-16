/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : queue_to_stack.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/07 15:10:40
*  @Last Modified  : 2017/06/07 16:23:05
********************************************************************************
*/

#include <stdio.h>
#include <queue>

template<typename T>
class Stack
{
private:
    mutable std::queue<T> queue1;
    mutable std::queue<T> queue2;
public:
    Stack(void){};
    ~Stack(void){};
    void push(const T &element);
    void pop(void);
    T top(void) const;
    size_t size(void) const;
    bool isEmpty(void) const;
};

template<typename T>
void Stack<T>::push(const T &element)
{
    if(isEmpty())
    {
        queue1.push(element);
    }
    else
    {
        if(queue1.empty())
            queue2.push(element);
        else
            queue1.push(element);
    }
}

template<typename T>
void Stack<T>::pop(void)
{
    if(isEmpty())
        throw "stack is empty.";    
    if(queue1.empty())
    {
        while(queue2.size() > 1)
        {
            T temp = queue2.front();
            queue2.pop();
            queue1.push(temp);
        }
        queue2.pop();
    }
    else
    {
        while(queue1.size() > 1)
        {
            T temp = queue1.front();
            queue1.pop();
            queue2.push(temp);
        }
        queue1.pop();
    }
}

template<typename T>
T Stack<T>::top(void) const
{
    T temp;
    if(isEmpty())
        throw "stack is empty.";
    if(queue1.empty())
    {
        while(queue2.size() > 0)
        {
            temp = queue2.front();
            queue2.pop();
            queue1.push(temp);
        }
    }
    else
    {
        while(queue1.size() > 0)
        {
            temp = queue1.front();
            queue1.pop();
            queue2.push(temp);
        }
    }
    return temp;
}

template<typename T>
inline size_t Stack<T>::size(void) const
{
    return queue1.size() + queue2.size();
}

template<typename T>
inline bool Stack<T>::isEmpty(void) const
{
    return queue1.empty() && queue2.empty();
}

int main(int argc, const char *argv[])
{
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    printf("size:%d\n", stk.size());
    while(!stk.isEmpty())
    {
        printf("top:%d ", stk.top());
        stk.pop();
    }
    return 0;
}
