/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 12:57:21
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 15:05:09
 * @FilePath: \CPP\class\class_model_this_pointer.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    成员变量和成员函数是分开存储的
    空对象占用1字节。c++编译器给每一个空对象分配一个字节空间用以区分空对象占内存的位置
    只有费静态成员变量，属于类的对象上
*/
#include <iostream> 

using namespace std;

class Person
{
public:
    int m_a; // 非静态成员变量，属于类的对象上

    static int m_b; // 静态成员变量，不属于类的对象上
    void func() // 非静态成员函数，不属于类的对象上
    {

    }
    static void func_2() // 静态成员函数，不属于类的对象上
    {
        
    }

private:

};

void test()
{
    Person p;
    cout << sizeof(p) << endl; 
}

int main()
{
    test();

    return 0;
}