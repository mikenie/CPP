/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 16:38:46
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-11 11:26:01
 * @FilePath: \CPP\class\operator_overload_1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    重载方式：
    1、成员函数重载
    2、全局函数符号重载

    成员函数重载本质调用：
    Person p3 = p1.operator+(p2)

    全局函数重载本质调用：
    Person p3 = operator+(p1, p2)

    运算符重载也可以发生函数重载
*/
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_age = age;
    }
/*
    成员函数实现运算符重载
*/
    // Person operator+(Person& p) // 通过成员函数重载 + 号
    // {
    //     Person tmp(10);
    //     tmp.m_age = this->m_age + p.m_age; 
        
    //     return tmp;
    // }

    int m_age;

};

/*
    全局函数重载
*/
Person operator+(Person& p_2, Person& p) // 通过成员函数重载 + 号
{
    Person tmp(10);
    tmp.m_age = p_2.m_age + p.m_age; 
    
    return tmp;
}
Person operator+(Person& p, int a) // 运算符重载也可以发生函数重载
{
    Person tmp(10);
    tmp.m_age = p.m_age + a;

    return tmp;
}

void test()
{
    Person p_1(18);
    Person p_2(20);

    Person p_3 = p_1 + p_2;

    cout << p_1.m_age << endl; 
    cout << p_2.m_age << endl;
    cout << p_3.m_age << endl;

    Person p_3 = p_1 + 100; // 函数重载
}

int main()
{
    test();

    return 0;
}
