/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 11:55:26
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-13 12:04:39
 * @FilePath: \CPP\继承\same_name_static.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Base
{
public:
    static void func()
    {
        cout << "Base m_b: " << m_b << endl;
    }

    int m_a;
    static int m_b;
};

int Base::m_b = 1;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son m_b: " << m_b << endl;
    }

    static int m_b;
};

int Son::m_b = 2;

void test()
{
    Son s1;
    cout << s1.m_b << endl; // Son.m_b
    cout << s1.Base::m_b << endl; // Base.m_b
    cout << Son::m_b << endl; // Son.m_b
    cout << Base::m_b << endl; // Base.m_b
    cout << Son::Base::m_b << endl; // Base.m_b, 第一个::表示用类名方式访问，第二个::表示作用域

    s1.func();
    Son::func();
    Son::Base::func();
    //Son::Base.func(); // 错误
}

int main()
{
    test();

    return 0;
}