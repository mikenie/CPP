/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-09 19:25:37
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-09 19:33:27
 * @FilePath: \CPP\class\list_init.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Person
{
    public:
        // Person(int a, int b, int c)
        // {
        //     cout << "param constructor func\n";
        //     m_a = a;
        //     m_b = b;
        //     m_c = c;
        // }
        Person(int a, int b, int c):m_a(a),m_b(b),m_c(c) 
        {
            cout << "list init constructor operation" << endl;
        }

        int read_a()
        {
            return m_a;
        }
        int read_b()
        {
            return m_b;
        }
        int read_c()
        {
            return m_c;
        }
    private:
        int m_a;
        int m_b;
        int m_c;

};

void test()
{
    Person p(1, 2, 3);
    cout << p.read_a() << p.read_b() << p.read_c() << endl;
}

int main()
{
    test();
    
    return 0;
}