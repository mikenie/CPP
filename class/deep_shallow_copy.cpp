/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-09 18:16:33
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-09 19:23:56
 * @FilePath: \CPP\class\deep_shallow_copy.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Person
{
    public:
        Person()
        {
            cout << "default constructor func" << endl;
        }
        Person(int age, int height)
        {
            this->m_age = age;
            this->m_height = new int(height);
            cout << "param constructor func" << endl;
        }
        // deep copy
        Person(const Person& p)
        {
            this->m_age = p.m_age;
            this->m_height =  new int(*p.m_height);
        }
        ~Person()
        {
            delete this->m_height; // shallow copy bug!
            cout << "destructor func" << endl;
        }

        void write_age(int age)
        {
            this->m_age = age;
        }
        int read_age()
        {
            return this->m_age;
        }
        int read_height()
        {
            return *(this->m_height);
        }

    private:
        int m_age;
        int * m_height;
};

void test()
{
    Person p1(20, 170);
    p1.write_age(21);
    Person p2(p1);
    cout << p2.read_age() << endl;
    cout << p2.read_height() << endl;
}

int main()
{
    test();

    return 0;
}