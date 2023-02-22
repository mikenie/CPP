/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 21:06:11
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 21:10:03
 * @FilePath: \CPP\模板\swap.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

template<typename T>
void my_swap(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    float c = 1.1;
    float d = 2.2;

    cout << "a   b   c   d" << endl;
    cout << a << "   " 
         << b << "   " 
         << c << "   "
         << d << endl;
    cout << "----------------" << endl;
    my_swap(a, b);
    my_swap(c, d);
    
    cout << a << "   " 
         << b << "   " 
         << c << "   "
         << d << endl;

}