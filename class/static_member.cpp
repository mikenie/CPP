/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-09 19:48:45
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 12:56:04
 * @FilePath: \CPP\class\static_member.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    静态成员变量：
        所有成员公用同一个静态数据。
        编译阶段分配内存。
        类内声明，类外初始化。
    静态成员函数：
        所有对象共享一个函数。
        静态成员函数只能访问静态成员变量。
*/
#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        cout << "default constructor" << endl;
    }

    int m_b;
    static int m_a;

    static int read_m_a()
    {
        // return m_b // 只能访问静态变量，无法区分是哪一个对象的m_b。
        return m_a; // 所有对象共享一个m_a，无需区分。
    }
    
private:
    static int m_c;

    static int read_m_a_2()
    {
        return m_a;
    }
        
};

int Person::m_a = 10;  
int Person::m_c = 20; 

void test()
{
    Person p_1;
    cout << p_1.m_a << endl;
    Person p_2;
    p_2.m_a = 20;
    cout << p_1.m_a << endl; // 对象访问
    cout << Person::m_a << endl; // 类名访问
    
    cout << Person::read_m_a() << endl; // 类名访问
    cout << p_1.read_m_a() << endl; // 通过对象访问
    // cout << p_1.m_c << endl; // inaccessable

    // cout << Person::read_m_a_2() << endl; // inaccessable
}

int main()
{
    test();

    return 0;
}