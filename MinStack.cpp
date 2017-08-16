/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : MinStack.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 18:31:04
*  @Last Modified  : 2017/08/14 21:19:24
********************************************************************************
*/

#include <stdio.h>
#include <stack>
#include <assert.h>

template<typename T>
class MinStack
{
private:
    std::stack<T> m_dat;
    std::stack<T *> m_min;
public:
    void push(const T &data)
    {
        m_dat.push(data);
        if(m_min.empty() || data < *m_min.top())
            m_min.push(&m_dat.top());
        else
            m_min.push(m_min.top());
    } 

    void pop(void)
    {
        m_dat.pop();
        m_min.pop();
    }

    T &top()
    {
        return m_dat.top();
    } 

    T &min(void)
    {
        return *(m_min.top());
    }

    bool empty()
    {
        return m_dat.empty();
    }
};

int main(int argc, char *argv[])
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

