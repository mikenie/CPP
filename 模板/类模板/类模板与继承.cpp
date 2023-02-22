/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 22:24:53
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 22:35:23
 * @FilePath: \CPP\模板\类模板与继承.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Base
{
public:
    Base()
    {
        cout << "type of T in Base: " << typeid(T).name() << endl;
    }
    T m_a;
};

// 1. 给定父类中T的类型
class Son1 : public Base<string> 
{
public:
    int m_b;
};

// 2. 子类也声明为类模板
template<class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "type T1: " << typeid(T1).name() << endl;
        cout << "type T2: " << typeid(T2).name() << endl;
    }
    int m_c;
};

void test()
{
    Son1 s1;

    Son2<string, int> s2; // int传给s2的T2，同时给父类T2
}

int main()
{
    test();

    return 0;
}