/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-06 14:43:35
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-06 14:59:06
 * @FilePath: \CPP\new.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

int *fun()
{
    int * p = new int(10); // new will return the point it create
    return p;
}

using namespace std;
int main()
{
    int * p_fun = fun();

    cout << *p_fun << endl; 

    delete p_fun; // if create a list, [] is required before p_fun
    
    // cout << *p_fun << endl; // illegal

    return 0;
}