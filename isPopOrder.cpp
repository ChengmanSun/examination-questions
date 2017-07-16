/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : isPopOrder.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 21:01:06
*  @Last Modified  : 2017/07/11 00:12:17
********************************************************************************
*/

//题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈
//的弹出顺序。假设压入的所有数字都不相等。

#include <stdio.h>
#include <stack>

/*
 * bool isPopOrder(int pushArr[], int popArr[], int length)
 * {
 *     int pushIndex = 0, popIndex = 0;
 *     std::stack<int> stackData;
 * 
 *     if(pushArr == NULL || popArr == NULL || length < 1)
 *         return false;
 * 
 *     while(popIndex < length)
 *     {
 *         while(stackData.empty() || stackData.top() != popArr[popIndex])
 *         {
 *             stackData.push(pushArr[pushIndex++]);
 *             if(pushIndex == length)
 *                 break;
 *         }
 *         if(stackData.top() != popArr[popIndex])
 *             break;
 *         stackData.pop();
 *         popIndex++;
 *     }
 * 
 *     return stackData.empty() && popIndex == length;
 * }
 */

bool isPopOrder(int *push, int *pop, int n)
{
    if(push == NULL || pop == NULL || n <= 0)
        return false;

    int *pushEnd = push + n;
    int *popEnd = pop + n;
    std::stack<int> stk;
    while(pop < popEnd)
    {
        if(stk.empty() || stk.top() != *pop)
        {
            if(push < pushEnd)
                stk.push(*push++);
            else
                break;
        }
        else
        {
            stk.pop();
            ++pop;
        }
    }
    return stk.empty() && pop == popEnd;
}

int main(int argc, const char *argv[])
{
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 5, 3, 2, 1};
    bool result = isPopOrder(push, pop, sizeof(push)/sizeof(push[0]));
    printf("result:%d", result);
    return 0;
}
