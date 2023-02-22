/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 11:45:31
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-13 11:54:46
 * @FilePath: \CPP\继承\same_name.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        m_a = 1;
    }
    
    void func()
    {
        cout << "Base func" << endl;
    }
    void func(int a)
    {
        cout << a << endl;
    }

    int m_a;

};

class Son : public Base
{
public:
    Son()
    {
        m_a = 2;
    }

    void func()
    {
        cout << "Son func" << endl;
    }

    int m_a;
};

void test()
{
    Son s1;

    cout << s1.m_a << endl; // Son.ma
    cout << s1.Base::m_a << endl; // Base.ma

    s1.func(); // Son.func()
    s1.Base::func(); // Base.func()
    // s1.func(10); // 同名，父类所有都被隐藏，只能添加作用域才能访问
    s1.Base::func(19);
}


int main()
{
    test();

    return 0;
}