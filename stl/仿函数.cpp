/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 仿函数.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/30 13:56:21
*  @Last Modified  : 2017/06/30 20:06:18
********************************************************************************
*/

#include <stdio.h>
#include <functional>
#include <algorithm>

/*
 * 仿函数指重载了operator()的类或者结构体，使类或者结构体像函数一样可调用。它比函数
 * 灵活，因为它是类所以可以用类成员保存状态。而如果普通函数想要达到保存状态的功能就
 * 要用static变量保存，但是会使函数变得不可重入。仿函数类似于python里的闭包。
 * 仿函数调用时是使用运算符重载operator()，效率比函数指针更高。
 */

/*
 * 头文件<functional>中包含了一些常用仿函数：
 * negate<T>          :   -param
 * plus<T>            :   param1 + param2
 * minus<T>           :   param1 - param2
 * multiplies<T>      :   param1 * param2
 * devide<T>          :   param1 / param2
 * modulus<T>         :   param1 % param2
 * equal_to<T>        :   param1 == param2
 * not_equal_to<T>    :   param1 != param2
 * less<T>            :   param1 <param2
 * greater<T>         :   param1 > param2
 * less_equal<T>      :   param1 <= param2
 * greater_equal<T>   :   param1 >= param2
 * logical_not<T>     :   !param
 * logical_and<T>     :   param1 && param2
 * logical_or<T>      :   param1 || param2
 */

class Add
{
private:
    int m_add;
public:
    Add(int add):m_add(add){};
    int operator()(int val)
    {
        return m_add + val;
    }
};

class AddPrint
{
private:
    int m_value;
public:
    AddPrint(void):m_value(1){};
    void operator()(int val)
    {
        printf("%d ", m_value++ + val);
    }
};

typedef void (*callback)(const char *);
callback g_callback;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;


    Add add3(3);
    Add add5(5);
    printf("add3(2) = %d\n", add3(2));
    printf("add5(2) = %d\n", add5(2));

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    AddPrint ap;

    //为什么下面的两次for_each的执行效果是一样的？因为仿函数的传参方式是值传递，而不是传引用！
    std::for_each(a, a+sizeof(a)/sizeof(a[0]), ap); printf("\n");
    std::for_each(a, a+sizeof(a)/sizeof(a[0]), ap); printf("\n");

    //for_each会返回仿函数，这样就可以不断地累加。
    ap = std::for_each(a, a+sizeof(a)/sizeof(a[0]), ap); printf("\n");
    ap = std::for_each(a, a+sizeof(a)/sizeof(a[0]), ap); printf("\n");

    printf("---------------------------------------------------------------\n");

    int array[] = {10, 2, 5, 7, 9, 8, 6, 3, 0, 1};
    int *pivot = std::partition(array, array+sizeof(array)/sizeof(array[0]), std::bind2nd(std::less<int>(), 3));
    printf("pivot : %d\n", *pivot);
    for(size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
