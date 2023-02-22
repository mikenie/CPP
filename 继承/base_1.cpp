/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-13 10:38:43
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:33
 * @FilePath: \CPP\继承\base_1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Basepage
{
public:
    void header()
    {
        cout << "head" << endl;
    }
    void footer()
    {
        cout << "footer"<< endl;
    }
    void left()
    {
        cout << "left" << endl;
    }
};

class Java : public Basepage
{
public:
    void content()
    {
        cout << "Java video" << endl;
    }
};

class Python : public Basepage
{
public:
    void content()
    {
        cout << "Python video" << endl;
    }
};

void test()
{
    Java ja;
    ja.footer();
    ja.header();
    ja.left();
    ja.content();
    cout << "---------" << endl;
    Python py;
    py.footer();
    py.header();
    py.left();
    py.content();

}

int main()
{
    test();

    return 0;
}
