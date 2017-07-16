/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 虚基类.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/28 16:58:45
*  @Last Modified  : 2017/07/04 00:03:45
********************************************************************************
*/

//所谓虚基类并不是指基类中有虚函数。而是指派生类以 public virtual 或者 protected virtual
//或者 private virtual 的方式继承基类。虚继承是多重继承特有的概念，是为了解决多重继承有多个
//相同基类的情况而出现的。

#include <stdio.h>

class Base
{
public:
    int value;
    Base(void):value(0){};
    // virtual ~Base(); //这叫虚函数继承，是为了实现多态而出现，和虚基类继承是不一样的。
};

//------------------------------------------------------------------------------

class A : public Base
{
};

class B: public Base
{

};

//类D中有两份类Base
class D: public A, public B
{

};

//------------------------------------------------------------------------------

class vA : public virtual Base
{

};

class vB : public virtual Base
{

};

//类vD中只有一份类Base
class vD : public vA, public vB
{

};

//------------------------------------------------------------------------------

int main(int argc, const char *argv[])
{
    (void)argc;
    (void)argv;

    D d;
    d.A::value = 1;
    d.B::value = 2;
    printf("D::A::Base::value: %d\n", d.A::value);
    printf("D::B::Base::value: %d\n", d.B::value);

    vD vd;
    vd.vA::value = 1;
    vd.vB::value = 2;
    printf("vD::vA::Base::value: %d\n", vd.vA::value);
    printf("vD::vB::Base::value: %d\n", vd.vB::value);

    return 0;
}
