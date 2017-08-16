/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : uglyNumber.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/15 21:02:18
*  @Last Modified  : 2017/07/15 16:07:40
********************************************************************************
*/

#include <stdio.h>
#include <algorithm>

//把只包含因子2、3和5的数称作导丑数。从从小到大的顺序的第1500个丑数。例如6、8都
//是丑数，但14不是，因为它包含因子7。习惯上我们把1当作第一个丑数。

//常规法
bool isUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;
    return number == 1;
}

int getUglyNumber(int index)
{
    if(index <= 0)
        return 0; 
    int count = 0;
    int number = 1;
    while(count < index)
    {
        if(isUgly(number++))
            ++count;
    }
    return number - 1;
}

//用空间换时间方法
int getUglyNumber2(int index)
{
    int *uglyArray = new int[index];
    uglyArray[0] = 1;
    int *mutiply2 = uglyArray;
    int *mutiply3 = uglyArray;
    int *mutiply5 = uglyArray;
    int nextUglyIndex = 1;
    while(nextUglyIndex < index)
    {
        int min = std::min(*mutiply2 * 2, *mutiply3 * 3);
        min = std::min(min, *mutiply5 * 5);
        uglyArray[nextUglyIndex] = min;

        while(*mutiply2 * 2 <= uglyArray[nextUglyIndex])
            ++mutiply2;
        while(*mutiply3 * 3 <= uglyArray[nextUglyIndex])
            ++mutiply3;
        while(*mutiply5 * 5 <= uglyArray[nextUglyIndex])
            ++mutiply5;
        ++nextUglyIndex;
    }
    int ugly = uglyArray[index-1];
    delete []uglyArray;
    return ugly;
}

int main(int argc, char *argv[])
{
    printf("%d\n", getUglyNumber(150));
    printf("%d\n", getUglyNumber2(150));
    return 0;
}
