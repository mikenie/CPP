/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-11 19:26:34
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-13 10:57:47
 * @FilePath: \CPP\class\operator_overload_3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class M_int
{
    friend ostream& operator<<(ostream& cout, M_int& i);

public:
    M_int()
    {
        m_a = 0;
    }

    M_int& operator++()
    {
        m_a++;
        
        return *this;
    }

    M_int& operator++(int) // int代表占位参数，用于区分前置和后置递增
    {
        static M_int tmp = *this;
        m_a++;

        return tmp;
    }

private:
    int m_a;
};

//ostream& operator<<(ostream& cout, M_int& i) 
ostream& operator<<(ostream& cout, M_int& i) // 第二个参数若是传递的引用，则需要保证传入的不是临时变量
{
    cout << i.m_a; 
    
    return cout;
}

void test()
{
    M_int i_1;

    cout << ++i_1 << endl;
    cout << i_1 << endl;

    cout << i_1++ << endl;
    cout << i_1 << endl;

}


int main()
{
    test();

    return 0;
}
