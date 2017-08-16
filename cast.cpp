/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : cast.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/31 09:00:29
*  @Last Modified  : 2017/05/31 16:32:34
********************************************************************************
*/

#include <stdio.h>

class A {
public:
    char m_a;
    A():m_a('a'){};
    virtual ~A(){};
};

class B {
public:
    char m_b;
    B():m_b('b'){};
    // virtual ~B(){};
};

class C : public A, public B 
{

};

class D : public A
{

};

int main(int argc, char *argv[])
{
    C *pc = new C;

    A *pa = dynamic_cast<A*>(pc);
    if(pa != NULL)
        printf("%c\n", pa->m_a);

    D *pd = dynamic_cast<D*>(pa);
    if(pd == NULL)
        printf("pa is not point to class D!\n");

    printf("%c\n", dynamic_cast<C*>(pa)->m_a);
    printf("%c\n", dynamic_cast<C*>(pa)->m_b);
    printf("%c\n", static_cast<C*>(pa)->m_a);
    printf("%c\n", static_cast<C*>(pa)->m_b);

    printf("----------------------------------\n");

    //B *pb = dynamic_cast<B*>(pc)可以正常编译，说明即使基类没有虚函数(多态)，dynamic_cast也可以从派生类转到基类。
    B *pb = dynamic_cast<B*>(pc);
    if(pb != NULL)
        printf("%c\n", pb->m_b);

    //dynamic_cast<C*>(pb)不能正常编译，说明dynamic_cast从基类转到派生类需要基类有虚函数。
    // printf("%c\n", dynamic_cast<C*>(pb)->m_a);
    // printf("%c\n", dynamic_cast<C*>(pb)->m_b);
    //static_cast不管是从派生类到基类，或者从基类到派生类的转换，都不需要有虚函数(多态)。
    printf("%c\n", static_cast<C*>(pb)->m_a);
    printf("%c\n", static_cast<C*>(pb)->m_b);

    printf("----------------------------------\n");

    //以下语句的结果是输出两个a，说明reinterpret_cast的转换结果保持二进制完全一致，不能
    //正确地转基类和派生类。
    printf("%c %c\n", reinterpret_cast<A*>(pc)->m_a, reinterpret_cast<B*>(pc)->m_b);

    delete pc;

    return 0;
}
