/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-09 17:58:19
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-09 18:15:01
 * @FilePath: \CPP\class\constructor.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

/*
    1、如果提供了有参构造函数，则编译器不再提供默认构造函数，但仍然提供拷贝构造函数；
    2、如果提供了拷贝构造函数，则默认、有参构造函数都不再提供。
*/
#include <iostream>

using namespace std;

class Person
{
    public:
        Person()
        {
            this->age = 10;
            cout << "default constructor fun" << endl;
        }
        Person(int age)
        {
            this->age = age;
            cout << "constructor fun with param" << endl;
        }
        // Person(const Person& p)
        // {
        //     this->age = p.age;
        //     cout << "copy constructor fun" << endl;
        // }
        ~Person()
        {
            this->age = 0;
            cout << "destructor fun" << endl;
        }

        void write_age(int age)
        {
            this->age = age;
        }
        int read_age()
        {
            return this->age;
        }

    private:
        int age;
};

void test()
{
    Person p1;
    p1.write_age(20); 
    Person p2(p1); // if no copy_constructor_func, only copy the value.
    cout << p2.read_age() << endl;
}

int main()
{
    test();

    return 0;
}