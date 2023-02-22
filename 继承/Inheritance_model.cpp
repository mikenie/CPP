/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 11:22:09
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:32
 * @FilePath: \CPP\继承\Inheritance_model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class Son : public Base
{
public:
    int m_d;
};

void test()
{
    Son s1;
    cout << sizeof(s1) << endl; // m_c访问不到，但是继承了
}

int main()
{
    test();

    return 0;
}