/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 16:00:33
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:26
 * @FilePath: \CPP\多态\纯虚函数和抽象类.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    在多态中，父类中虚函数的实现毫无意义，因此可以将虚函数改为纯虚函数
    当类中有了纯虚函数，这个类也称为 抽象类
    
    语法：
        virtual 返回值类型 函数名 参数列表 = 0
    特点：
        1、无法实例化
        2、抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
*/
#include <iostream>

using namespace std;

class Base
{
public: 
    virtual void func() = 0; // 纯虚函数,只要含有一个纯虚函数，就称为抽象类
};

class Son : public Base
{
public:
    void func() // 重写父类中的纯虚函数
    {
        cout << "func" << endl;
    }
};

void test()
{
    /* 抽象类无法实例化对象 */
    // Base b; 
    // new Base;
    
    /* 需要重写父类中的纯虚函数，否则子类也是抽象类 */
    Base* base = new Son;
    base->func();
    delete base;
}

int main()
{
    test();

    return 0;
}