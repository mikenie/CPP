/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-11 11:26:44
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-11 19:25:26
 * @FilePath: \CPP\class\operator_overload_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person& p);

public:
    Person()
    {
        m_c = 3;
        m_b = 2;
        m_a = 1;
    }

    
    int m_a;
    int m_b;

private:
    int m_c;

};

ostream& operator<<(ostream& cout, Person& p)
{
    cout << p.m_a << endl;
    cout << p.m_b << endl;
    cout << p.m_c << endl;

    return cout;
}

void test()
{
    Person p_1;

    cout << p_1.m_a << endl;
    cout << p_1 << endl;
}

int main()
{
    test();

    return 0;
}