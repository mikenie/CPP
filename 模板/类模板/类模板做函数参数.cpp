/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 22:11:28
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 22:22:42
 * @FilePath: \CPP\模板\类模板\类模板做函数参数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    
    void show_info()
    {
        cout << "-------" << endl;
        cout << m_name << endl;
        cout << m_age << endl;
    }
    T1 m_name;
    T2 m_age;
};

// 1.指定传入的类型:最为常用
void print_person1(Person<string, int>& p)
{
    p.show_info();
}

// 2.参数模板化
template<class T1, class T2>
void print_person2(Person<T1, T2>& p)
{
    p.show_info();
}

// 3.整个类模板化
template<class T1, class T2>
void print_person3(Person<T1, T2>& p)
{
    p.show_info();
}

void test()
{
    Person<string, int> p1("Zhang San", 18);
    print_person1(p1);
    print_person2(p1);
    print_person3(p1);
    
}

int main()
{
    test();

    return 0;
}