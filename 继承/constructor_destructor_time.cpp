/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 11:40:58
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:31
 * @FilePath: \CPP\继承\constructor_destructor_time.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    | Base c
    | Son c
    | Son d
    | Base d
*/
#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son constructor" << endl;
    }
    ~Son()
    {
        cout << "Son destructor" << endl;
    }
};

void test()
{
    Son s1;
}

int main()
{
    test();

    return 0;
}