/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : set_map.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/29 15:51:31
*  @Last Modified  : 2017/06/30 10:00:54
********************************************************************************
*/

#include <stdio.h>

#include <set>  //包括set和multiset
#include <map>  //包括map和multimap
#include <string>

//关联容器使用的是红黑树也就是一种平衡二叉搜索树，所以它的插入、删除、查找的时间效率都为O(logn)
//set和map使用的数据结构都是红黑二叉树，所以set和map在插入时会根据compare比较方法进行排序生成平衡二叉搜索树。
//set和multiset在插入数据以后就无法再修改，因为如果允许修改则会打乱二叉搜索树的排序。只能通过删除原来的值，再插入新值来修改。std::remove()也无法删除。
//map是通过key来排序的，所以可以对同一个key插入新的值来进行修改。
//multimap由于同一个键能对应多个值，所以也无法修改某个对(pair)的值，只能插入同一个键的不同值形成新的对。

//关联容器内建的二分搜索方法效率比std::find()和std::count()等等通用算法的效率更高，所以查找最好使用关联容器的内建搜索方法：
//count(T &key):        // 查找key在multiset和multimap中的数量
//find(T &key):         // (==) 查找第一个等于key的元素
//lower_bound(T &key):  // (>=) 查找大于等于key的第一个元素，返回其迭代器。
//upper_bound(T &key):  // (<) 查找大于key的第一个元素，返回其它迭代器。
//equal_bound(T &key):  // (>= && <) 大于等于key的第一个元素的迭代器，和大于key的第一个元素的迭代器组成一个组。返回这个迭代器组。

typedef std::pair<int, std::string> CustomPair;

class Compare
{
public:
    bool operator()(const int &a, const int &b)
    {
        return a > b;
    }
};

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    printf("--------------------------set----------------------------------\n");

    // std::set<int> s;    //使用默认比较方法std::less<typename T>
    std::set<int, Compare> s; //使用自定义比较方法
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for(std::set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
        printf("%d ", *iter);
    printf("\n");
    for(std::set<int>::iterator iter = s.find(2); iter != s.end(); ++iter)
        printf("%d ", *iter);

    printf("\n--------------------------multiset---------------------------\n");

    // std::multiset<int, std::less<int> > ms;
    std::multiset<int, std::greater<int> > ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    for(std::set<int>::iterator iter = ms.begin(); iter != ms.end(); ++iter)
        printf("%d ", *iter);
    printf("\ncount of 3:%llu\n", ms.count(3));
    for(std::set<int>::iterator iter = ms.find(3); iter != ms.end(); ++iter)
        printf("%d ", *iter);

    printf("\n--------------------------map--------------------------------\n");

    std::map<std::string, int> mp;
    mp["one"] = 1;                                      //可以使用下标来插入数据
    mp.insert(std::pair<std::string, int>("tow", 2));   //也可以使用insert来插入数据
    mp["three"] = 3;                                    //相同的键会覆盖原来的值
    printf("key:%s value:%d\n", "three", mp["three"]);
    mp["three"] = 9;                                    //相同的键会覆盖原来的值
    printf("key:%s value:%d", "three", mp["three"]);

    printf("\n--------------------------multimap---------------------------\n");

    // std::multimap<int, std::string> mmp;
    // std::multimap<int, std::string, std::greater<int> > mmp;
    std::multimap<int, std::string, Compare> mmp;
    mmp.insert(std::pair<int, std::string>(1, "one"));  //multimap只能使用insert方法来插入数据
    mmp.insert(CustomPair(2, "tow"));
    mmp.insert(CustomPair(3, "three"));
    mmp.insert(CustomPair(3, "THREE"));                 //同一个键可以有多个值
    for(std::map<int, std::string>::iterator iter = mmp.begin(); iter != mmp.end(); ++iter)
        printf("key:%d value:%s\n", iter->first, iter->second.c_str());

    return 0;
}
