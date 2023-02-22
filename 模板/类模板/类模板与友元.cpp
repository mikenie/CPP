/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 22:46:52
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 22:58:39
 * @FilePath: \CPP\模板\类模板\类模板与友元.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
using namespace std;

// 提前知道Person类存在
template<class T1, class T2>
class Person;

template<class T1, class T2>
void print_person_e(Person<T1, T2>& p)
{
    cout << "name: " << p.m_name << endl;
    cout << "age: " << p.m_age << endl;
}

template<class T1, class T2>
class Person
{
    // 全局函数 类内 实现测试
    friend void print_person(Person<T1, T2>& p)
    {
        cout << "name: " << p.m_name << endl;
        cout << "age: " << p.m_age << endl;
    }

    // 全局函数 类外 实现
    // 加空模板参数列表
    friend void print_person_e<>(Person<T1, T2>& p);

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

private:
    T1 m_name;
    T2 m_age;
};

void test()
{
    Person<string, int> p1("Zhang San", 18);
    print_person(p1);
    cout << "-------" << endl;
    print_person_e(p1);
}

int main()
{
    test();

    return 0;
}