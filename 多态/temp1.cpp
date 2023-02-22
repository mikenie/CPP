/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-14 23:05:22
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:27
 * @FilePath: \CPP\多态\temp1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    两种方法实现计算器类
*/
#include <iostream>
#include <string>

using namespace std;

class Calculator
{
public:
    int get_result(string opt)
    {
        if(opt == "+")
        {
            return m_num1 + m_num2;
        }
        else if(opt == "-")
        {
            return m_num1 - m_num2;
        }
        else if(opt == "*")
        {
            return m_num1*m_num2;
        }
        else if(opt == "/")
        {
            return m_num1/m_num2;
        }
        /*
            如果需要扩展新的功能，需要修改源码
            开闭原则：对扩展进行开发，对修改进行关闭
        */
    }
    
    int m_num1;
    int m_num2;
};

/*
    利用多态实现
*/
class AbstractCalculator
{
public:
    virtual int get_result()
    {
        return 0;
    }

    int m_num1;
    int m_num2;
};

class Add : public AbstractCalculator
{
public:
    int get_result()
    {
        return m_num1 + m_num2;
    }
};

class Mul : public AbstractCalculator
{
public:
    int get_result()
    {
        return m_num1 * m_num2;
    }
};

void test()
{
    // 普通写法
    Calculator cal;
    
    cal.m_num1 = 1;
    cal.m_num2 = 2;

    cout << cal.get_result("*") << endl;

    // 多态写法
    AbstractCalculator *abc = new Add;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->get_result() << endl;
    delete abc;

    abc = new Mul;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->get_result() << endl;
}

int main()
{
    test();

    return 0;
}