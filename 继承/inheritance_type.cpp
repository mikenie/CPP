/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 11:01:12
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-13 11:21:44
 * @FilePath: \CPP\继承\inheritance_type.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    public
    protected 
    private
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

class Son1 : public Base
{
public:
    void func()
    {
        m_a = 1; // 变为公有
        m_b = 2; // 仍为保护
        // m_c = 3; // 不可访问
    }
};

class Son2 : protected Base
{
public:
    void func()
    {
        m_a = 1; // 变为保护
        m_b = 2; // 变为保护
        // m_c = 3; // 不可访问
    }
};

class Son3 : private Base
{
public:
    void func()
    {
        m_a = 1; // 变为私有
        m_b = 2; // 变为私有
        // m_c = 3; // 不可访问
    }
};

class Grandson3 : public Son3
{
public:
    void func()
    {
        /* Son3中全为私有成员，因此都不能访问了 */
        // m_a = 1;
        // m_b = 2;
    }
};

void test()
{
    Son1 s1;
    Son2 s2;
    Son3 s3;

    Grandson3 g3;

    s1.func();
    s2.func();
    s3.func();
    g3.func();

    s1.m_a;

}

int main()
{
    test();

    return 0;
}