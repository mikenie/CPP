/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 21:52:48
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 21:58:28
 * @FilePath: \CPP\模板\类模板\base.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

template<class nametype, class agetype>
class Person
{
public:
    Person(nametype name, agetype age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void show_info()
    {
        cout << "name: " << m_name;
        cout << endl;
        cout << "age: " << m_age;
    }

    nametype m_name;
    agetype m_age;
};

void test()
{
    Person<string, int> p1("Zhang San", 10);
    p1.show_info();
}

int main()
{
    test();

    return 0;
}