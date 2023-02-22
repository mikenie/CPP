/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-12 11:49:44
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-12 12:05:03
 * @FilePath: \CPP\class\operator_overload_4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_age = new int(age);
    }
    ~Person()
    {
        if(m_age != NULL) delete m_age;
        else return;
    }

    Person& operator=(Person& p)
    {
        if(this->m_age != NULL) delete this->m_age; // 先释放本身的堆区

        this->m_age = new int(*p.m_age);

        return p;
    }
    
    int* m_age;

private:

};

void test()
{
    Person p1(18);

    cout << *p1.m_age << endl;

    Person p2(29);

    cout << *p2.m_age << endl;

    p2 = p1; // 赋值操作, 浅拷贝函数m_age指针指向了同一个内存空间
    cout << *p1.m_age << endl;
    cout << *p2.m_age << endl;
    
    Person p3(33);

    p1 = p2 = p3;
    cout << *p1.m_age << ' ' << *p2.m_age << ' ' << *p3.m_age << endl;
}

int main()
{
    test();

    return 0;
}