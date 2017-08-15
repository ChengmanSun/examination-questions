/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : queue_to_stack.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/07 15:10:40
*  @Last Modified  : 2017/08/15 20:25:13
********************************************************************************
*/

#include <stdio.h>
#include <queue>

template<typename T>
class Stack
{
private:
    mutable std::queue<T> q1;
    mutable std::queue<T> q2;
public:
    Stack(void){};
    ~Stack(void){};
    void push(const T &data);
    void pop(void);
    T top(void) const;
    size_t size(void) const;
    bool isEmpty(void) const;
};

template<typename T>
void Stack<T>::push(const T &data)
{
    if(q1.empty() && q2.empty())
        q1.push(data);
    else
    {
        if(!q1.empty())
            q1.push(data);
        else
            q2.push(data);
    }
}

template<typename T>
void Stack<T>::pop(void)
{
    if(q1.empty() && q2.empty())
        throw "stack is empty.";    
    if(!q1.empty())
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }
    else
    {
        while(q2.size() > 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
    }
}

template<typename T>
T Stack<T>::top(void) const
{
    T temp;
    if(isEmpty())
        throw "stack is empty.";
    if(q1.empty())
    {
        while(q2.size() > 0)
        {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
    }
    else
    {
        while(q1.size() > 0)
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
    }
    return temp;
}

template<typename T>
inline size_t Stack<T>::size(void) const
{
    return q1.size() + q2.size();
}

template<typename T>
inline bool Stack<T>::isEmpty(void) const
{
    return q1.empty() && q2.empty();
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
