/*
 * @Author: Nie Chun
 * @Date: 2023-01-21 14:43:55
 * @LastEditors: niemike niemike@outlook.com
 * @LastEditTime: 2023-01-26 23:38:46
 * @FilePath: \CPP\模板\类模板案例\main.cpp
 */
/* 因为模板类分文件编写，因此直接包含.cpp */
#include "my_arr.cpp"
#include <iostream>

using namespace std;

class Person
{
public:
    Person() {}; // 后面用new生成Person类型的变堆区空间时，会自动调用无参构造函数
    Person(int age, string name)
    {
        m_name = name;
        m_age = age;
    }

    int m_age;
    string m_name;
};

void test()
{
    My_arr<int> a1(10);
    My_arr<int> a2(a1);

    My_arr<int> a3(20);
    a3 = a1;

    for(int i = 0; i<10; ++i)
    {
        a1.push_back(i);
    }

    for(int i = 0; i<a1.get_size(); ++i)
    {
        cout << a1[i] << endl;
    }

    cout << "size" << " " << a1.get_size() << endl;
    a1.pop_back();
    cout << "size" << " " << a1.get_size() << endl;
    a1.push_back(29);
   
    for(int i = 0; i<a1.get_size(); ++i)
    {
        cout << a1[i] << endl;
    }

   
}

void test_my_data()
{
    My_arr<Person> arr(10);

    Person p1(10, "zhangsan");
    Person p2(20, "lisi");
    Person p3(30, "wangwu");

    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);

    for(int i = 0; i<arr.get_size(); ++i)
    {
        cout << arr[i].m_name << ": " << arr[i].m_age << endl;
    }
}

int main()
{
    test();

    cout << "-----------" << endl;

    test_my_data();

    return 0;
}