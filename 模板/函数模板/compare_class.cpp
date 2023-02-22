/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 21:42:24
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 21:46:08
 * @FilePath: \CPP\模板\compare_class.cpp
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
        this->m_name = name;
        this->m_age = age; 
    }
    string m_name;
    int m_age;
};

template<class T>
bool my_compare(T& a, T& b) 
{
    return (a==b)?true:false;
}

/* 具体化优先调用 */
template<> bool my_compare(Person& p1, Person& p2) // 上边用的引用，这里也要用引用，否则报错
{
    if(p1.m_name == p2.m_name) 
        return true;
    else 
        return false;
}

void test()
{
    Person p1("a", 12);
    Person p2("b", 13);

    my_compare(p1, p2);
}

int main()
{
    test();

    return 0;
}