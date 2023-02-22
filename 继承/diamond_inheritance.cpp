/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 12:21:03
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-14 18:04:00
 * @FilePath: \CPP\继承\diamond_inheritance.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    利用虚继承，解决棱形继承问题
    继承前加 virtual 关键字
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

    int m_a;
};

class Son1 : virtual public Base
{
public:
    Son1()
    {
        m_b = 2;
    }

    int m_b;
};

class Son2 : virtual public Base
{
public:
    Son2()
    {
        m_b = 3;
    }

    int m_b;
};

class Grandson : public Son1, public Son2
{
public:
    Grandson()
    {
        m_c = 4;
    }

    int m_c;
};

void test()
{
    Grandson g;

    cout << g.Son1::m_b << endl;
    cout << g.Son2::m_b << endl;

    cout << g.m_a << endl; // 利用虚继承之后，m_a只有一份，不会产生冲突问题
    cout << g.Son1::m_a << endl;
    cout << g.Son2::m_a << endl;
    
}

int main()
{
    test();

    return 0;
}

