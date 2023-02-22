/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 12:06:55
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-13 12:22:36
 * @FilePath: \CPP\继承\mul_inheritance.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    多继承不建议使用
*/
#include <iostream>

using namespace std;

class Base1
{
public:
    Base1()
    {
        cout << "Base1 c" << endl;
        m_a = 1;
    }

    int m_a;
};

class Base2
{
public:
    Base2()
    {
        cout << "Base2 c" << endl;
        m_a = 2;
    }
    
    int m_a;
};

class Son : public Base1, public Base2
{
public:
    Son()
    {
        cout << "Son c" << endl;
        m_b = 3;
    }

    int m_b;
};

void test()
{
    Son s1;
    
    // s1.a; // 父类重名
    cout << "Base1 m_a:" << s1.Base1::m_a << endl;
    cout << "Base2 m_a:" << s1.Base2::m_a << endl;
}

int main()
{
    test();

    return 0;
}