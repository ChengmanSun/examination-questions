/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : isPopOrder.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 21:01:06
*  @Last Modified  : 2017/08/14 16:30:58
********************************************************************************
*/

//题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈
//的弹出顺序。假设压入的所有数字都不相等。

#include <stdio.h>
#include <stack>

bool isPopOrder(int pushSequence[], int popSequence[], int length)
{
    int pushIndex = 0, popIndex = 0;
    std::stack<int> stk;

    if(pushSequence == NULL || popSequence == NULL || length < 1)
        return false;

    while(popIndex < length)
    {
        while(stk.empty() || stk.top() != popSequence[popIndex])
        {
            stk.push(pushSequence[pushIndex++]);
            if(pushIndex == length)
                break;
        }
        if(stk.top() != popSequence[popIndex])
            break;
        stk.pop();
        popIndex++;
    }

    return stk.empty() && popIndex == length;
}

bool isPopOrder(int pushSequence[], int popSequence[], int length)
{
    if(pushSequence == NULL || popSequence == NULL || length < 1)
        return false;

    int pushIndex = 0, popIndex = 0;
    std::stack<int> stk;

    while(popIndex < length)
    {
        if(stk.empty() || stk.top() != popSequence[popIndex])
        {
            if(pushIndex < length)
                stk.push(pushSequence[pushIndex++]);
            else
                break;
        }
        else
        {
            stk.pop();
            popIndex++;
        }
    }
    return stk.empty() && popIndex == length;
}

int main(int argc, char *argv[])
{
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 5, 3, 2, 1};
    bool result = isPopOrder(push, pop, sizeof(push)/sizeof(push[0]));
    printf("result:%d", result);
    return 0;
}
