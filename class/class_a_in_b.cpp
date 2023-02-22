/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-09 19:34:13
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-09 19:47:31
 * @FilePath: \CPP\class\class_a_in_b.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    Phone先构造,然后是Person。
    Person先析构，然后是Phone。

*/
#include <iostream>
#include <string>

using namespace std;

class Phone
{
    public:
        Phone(string phone_name)
        {
            cout << "phone constructor" << endl;
            m_phone_name = phone_name;
        }
        ~Phone()
        {
            cout << "phone destructor" << endl;
        }

        string m_phone_name;
};

class Person
{
    public:
        Person(string name, string p_name):m_name(name), m_phone(p_name)
        {
            cout << "list init constructor operation" << endl;
        }
        ~Person()
        {
            cout << "person destructor" << endl;
        }

        string m_name;
        Phone m_phone;
};



void test()
{
    Person p_1("Zhang San", "Iphone14 pro");

    cout << p_1.m_phone.m_phone_name << endl;
    
}

int main()
{
    test(); 
    
    return 0;
}