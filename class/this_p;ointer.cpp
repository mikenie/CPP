/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 15:06:25
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 15:23:25
 * @FilePath: \CPP\class\this_p;ointer.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    每一个非静态成员函数只会诞生一份函数实例，多个同类型的对象共用一块代码，如何区分是哪个对象调用自己？
    C++通过this指针，解决上述问题。 this指针指向被调用的成员函数所属的对象。 
    this指针是隐含每一个非静态成员函数内的一种指针。
*/
/*
    常用：
    1、解决名称冲突
    2、返回对象本身用*this
*/
#include <iostream>

using namespace std;

 class Person
 {
public:
    Person(int age)
    {
        // this指针指向p_1
        this->m_age = age;
    }

    Person& person_add_age(Person& p) // 注意返回的是引用，而不是值
    {
        this->m_age += p.m_age;
        
        return *this;  // 链式编程思想
    } 
    
    int m_age;

private:

 };

 void test()
 {
    Person p_1(18);
    cout << p_1.m_age << endl;

    Person p_2(18);
    p_1.person_add_age(p_2);
    cout << p_1.m_age << endl;

    p_1.person_add_age(p_2).person_add_age(p_2); // 链式追加
    cout << p_1.m_age  << endl;
 }

 int main()
 {
    test();

    return 0;
 }

