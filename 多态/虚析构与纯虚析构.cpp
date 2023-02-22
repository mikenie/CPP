/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 16:20:37
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 16:39:24
 * @FilePath: \CPP\多态\虚析构与纯虚析构.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    多态使用时，如果子类中有属性开辟到了堆区，则父类指针在释放时无法调用到子类的析构代码
    解决:
        将父类中的析构函数改为虚析构或者纯虚析构

    虚析构和纯虚析构共性：
        1、可以解决父类指针释放子类对象
        2、都需要有具体的函数实现
    区别：
        如果是纯虚析构，属于抽象类，无法实例化对象

    虚析构：
        virtual 类名();
    纯虚析构：
        virtual 类名() = 0;

    如果子类中堆区没有数据，可以不写虚析构或者纯虚析构
*/
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "animal constructor" << endl;
    }
    // virtual ~Animal() // 虚析构，解决父类指针释放子类对象时不干净的问题
    // {
    //     cout << "animal destructor" << endl;
    // }
    virtual ~Animal() = 0; // 无法解析的外部命令, 需要代码实现
    
    virtual void speak() = 0;
};

Animal::~Animal() // 代码实现
{
    cout << "pvirtual_destructor_func" << endl;
}

class Cat : public Animal
{
public: 
    Cat(string name)
    {
        cout << "cat constructor" << endl;
        m_name = new string(name); // 堆区有东西
    }
    ~Cat()
    {   
        cout << "cat destructor" << endl; 
        if(m_name != NULL) delete m_name; // 普通析构，父类走不到这
    }

    void speak()
    {
        cout << *m_name << " speaking" << endl;
    }

    string* m_name;
};

void test()
{
    Animal* animal = new Cat("Tom");

    animal->speak();
    delete animal;
}

int main()
{
    test();

    return 0;
}