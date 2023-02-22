/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 15:30:16
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 15:41:15
 * @FilePath: \CPP\class\const_func.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    常函数：
        成员函数后加const修饰称为常函数
        常函数内不可修改成员属性
        成员属性声明时加关键字mutable后，在常函数中仍然可以修改
    
    常对象：
        声明对象前加const
        常对象只能调用常函数
*/
#include <iostream>

using namespace std;

class Person
{
public:
    // this指针的本质： 指针常量，指向不能够修改，但指向的值可以修改
    void show_person() const
    {
        m_a = 10;   
        // m_b = 10; // const的存在使得指针指向的值也不能够修改 
    }
    void show_person_2()
    {

    }
    mutable int m_a;
    int m_b;
    
private:

};

void test()
{
    const Person p_1; // 常对象
    //p_1.m_b = 10; // 常对象不能修改普通成员变量
    p_1.m_a = 10; 
    p_1.show_person();
    //p_1.show_person_2(); // 常对象不允许调用普通函数
}

int main()
{
    test();

    return 0;
}

