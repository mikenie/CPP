/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-12 12:09:27
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-12 12:15:20
 * @FilePath: \CPP\class\operator_overload_5.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    bool operator==(Person& p)
    {
        if(this->m_age == p.m_age) return true;
        else return false;
    }
    bool operator!=(Person& p)
    {
        if(this->m_age != p.m_age) return true;
        else return false;
    }

    string m_name;
    int m_age;
};

void test()
{
    Person p1("Mike", 18);
    Person p2("Tom", 20);

    if(p1 == p2) cout << "Mike == Tom" << endl;
    if(p1 != p2) cout << "Mike != Tom" << endl;
    
}

int main()
{
    test();

    return 0;
}
