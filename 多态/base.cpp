/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-14 18:06:52
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:29
 * @FilePath: \CPP\多态\base.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    动态多态的满足条件：
        1、需要有继承关系
        2、子类要重写父类中的虚函数（区别于重载，函数的返回值、名称、参数列表完全相同）
           重写的时候，virtual关键字可写可不写
    动态多态的使用：
        父类的指针或者引用指向子类对象
*/

#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak() // 加上虚函数之后，实现地址晚绑定
    {
        cout << "animals are talking" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "cats are talking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "dogs are talking" << endl;
    }
};

// 执行说话的函数，地址早绑定，在编译阶段确定函数地址
// 如果想让猫说话，地址需要晚绑定
void do_speak(Animal& animal) // Animal& animal = cat
{
    animal.speak();
}

void test()
{
    Cat cat;
    Dog dog;

    do_speak(cat);
    do_speak(dog);
}

int main()
{
    test();

    return 0;
}