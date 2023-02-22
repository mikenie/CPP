/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 15:23:49
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 15:29:03
 * @FilePath: \CPP\class\void_pointer.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:

    void show_class_name()
    {
        cout << "Person" << endl;
    }
    void show_person_age()
    {
        if(this == NULL) return; // 防止空指针对其调用

        cout << m_age << endl;
    }

    int m_age;

private:

};

void test()
{
    Person* p_Person = NULL;
    p_Person->show_class_name();
    p_Person->show_person_age(); // 错误, 传入的指针为空
}

int main()
{
    test();

    return 0;
}