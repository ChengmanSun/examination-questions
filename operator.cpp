/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : operator.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/19 15:38:04
*  @Last Modified  : 2017/05/19 15:58:15
********************************************************************************
*/

#include <stdio.h>

class A 
{
private:
    int data;
    friend bool operator<(const A &obj1, const A &obj2);
public:
    A(int value)
        :data(value)
    {

    }
};

bool operator<(const A &obj1, const A &obj2)
{
    return obj1.data < obj2.data;
}

//有类A以及A的小于比较函数，假设你并不知道比较的细节，如何用这个小于比较函数
//写出大于比较函数、等于比较函数和不等于比较函数？

//答案：
inline bool operator==(const A &obj1, const A &obj2)
{
    return !(obj1 < obj2) && !(obj2 < obj1);
}

inline bool operator>(const A &obj1, const A &obj2)
{
    return !(obj1 < obj2) && !(obj1 == obj2);
}

inline bool operator!=(const A &obj1, const A &obj2)
{
    return !(obj1 == obj2);
}

int main(int argc, char *argv[])
{
    A a(1), b(2);
    printf("a < b: %d\n", a<b);
    printf("a > b: %d\n", a>b);
    printf("a == b: %d\n", a==b);
    printf("a != b: %d\n", a!=b);
    return 0;
}
