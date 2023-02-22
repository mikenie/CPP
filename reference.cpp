/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-06 15:01:42
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-07 11:16:30
 * @FilePath: \CPP\reference.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

int& ref(int& a)
{
    int c = a;
    static int b = 10;
    cout <<  "type: a " << endl;
    return b;
}

int& ref(const int& a)
{
    int c = a; 
    static int b  = 10; // should not return reference of local variable 
    cout << "type: b " << endl;
    return b;
}

int main()
{ 
    int a = 10;
    int & b = a; // reference must be initialized  

    b = 9;

    int & p_ref = ref(10);
    ref(10) = 20; // ref() return reference of a, so ref() can be a left value
    cout << p_ref << endl; 

    return 0;
}