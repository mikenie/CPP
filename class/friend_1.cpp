/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 15:42:28
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 15:52:02
 * @FilePath: \CPP\class\friend_1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */ 
/*
    友元的三种实现：
        1、全局函数做友元
        2、类做友元
        3、成员函数做友元
*/
#include <iostream>
#include <string>

using namespace std;

class Person
{
public: 
    Person(string name, string dog)
    {
        m_name = name;
        m_dog = dog;
    }

    friend void friend_func(Person& p);

    string m_name;

private:
    string m_dog;
    
};

void friend_func(Person& p)
{
    p.m_name = "Li Si";
    cout << p.m_name << endl;
    cout << p.m_dog << endl;
}

void test()
{
    Person p_1("Zhang San", "bianmu");
    friend_func(p_1);

}

int main()
{
    test();
    
    return 0;
}