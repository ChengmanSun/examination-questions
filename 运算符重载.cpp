/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 运算符重载.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/28 14:03:27
*  @Last Modified  : 2017/06/28 23:20:58
********************************************************************************
*/

#include <stdio.h>

/*
 * 不能重载的去算符：
 * (1) . 类成员访问运算符
 * (2) .* 类成员指针访问运算符
 * (3) :: 域访问运算符
 * (4) sizeof 长度运算符
 * (5) ?: 条件运算符
 */

/*
 * 运算符重载的限制：
 * (1) 不能创造新的运算符
 * (2) 不能改变原运算符的优先级
 * (3) 不能改变原运算符的结合性
 * (4) 不能改变原运算符的操作数个数
 * (5) 不能改变原运算符的语法结构
 */

 
// 运算符重载函数一般是类的成员函数或者友元函数。
class A
{
private:
    int value;
public:
    A(void):value(0){};
    A(int v):value(v){};

    int getVal(void){return value;};

    A operator+(const A &a);                        //运算符重载函数作为成员函数
    // friend A operator+(const A &a1, const A &a2);   //运算符重载函数为作友元函数

    A &operator++(void);                            //自加操作前置运算
    A operator++(int);                              //自加操作后置运算
};

// 如果是成员函数，则有this指针，则双目运算的参数只需要一个参数，如：
A A::operator+(const A &a)
{
    A temp;
    temp.value = this->value + a.value;
    return temp;
}

// 如果运算符重载函数是友元函数，当运算符是双目运算时：
/*
 * A operator+(const A &a1, const A &a2)
 * {
 *     A temp;
 *     temp.value = a1.value + a2.value;
 *     return temp;
 * }
 */

//自加操作前置运算
A &A::operator++(void)
{
    ++this->value;
    return *this;
}

//自加操作后置运算
//自加后置运算不能返回原实例的引用，和c/c++基本数据类型一样，自加后置运算符都是返回一个临时变量，而不是返回变量本身。
//正确：int i = 0; ++i = 5;
//错误：int i = 0; i++ = 5;
A A::operator++(int)
{
    A temp;
    temp = *this;
    ++this->value;
    return temp;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    A a1(1), a2(2);
    printf("a1 + a2: %d\n", (a1+a2).getVal());
    printf("++a1: %d\n", (++a1).getVal());
    printf("a1++: %d\n", (a1++).getVal());
    printf("after a1++: %d\n", a1.getVal());

    int i = 0;
    // i++ = 5;    //错误，无法编译
    ++i = 5;    //正确

    return 0;
}
