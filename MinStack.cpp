/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : MinStack.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 18:31:04
*  @Last Modified  : 2017/07/11 18:32:28
********************************************************************************
*/

#include <stdio.h>
#include <stack>
#include <assert.h>

template<typename T>
class MinStack
{
private:
    std::stack<T> m_Data;
    std::stack<T *> m_Min;
public:
    void push(int data)
    {
        m_Data.push(data);
        if(m_Min.empty() || data < *(m_Min.top()))
            m_Min.push(&m_Data.top());
        else
            m_Min.push(m_Min.top());
    } 

    void pop(void)
    {
        m_Data.pop();
        m_Min.pop();
    }

    T &top()
    {
        return m_Data.top();
    } 

    T &min(void)
    {
        return *(m_Min.top());
    }

    bool empty()
    {
        return m_Data.empty();
    }
};

int main(int argc, const char *argv[])
{
    MinStack<int> min;
    min.push(1);
    min.push(6);
    min.push(0);
    min.push(2);
    while(!min.empty())
    {
        printf("top: %d ", min.top());
        printf("min: %d\n", min.min());
        min.pop();
    }
    return 0;
}

