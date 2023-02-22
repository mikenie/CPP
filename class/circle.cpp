/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-07 11:11:20
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-07 11:16:48
 * @FilePath: \CPP\class\circle.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle{

    public:
        int m_r;
        double calculateZC()
        {
            return 2*PI*m_r;
        }
    private:

};

int main()
{
    Circle Circle_1;
    Circle_1.m_r = 10;

    cout << "circle length: " << Circle_1.calculateZC() << endl;
    
    return 0;
}