/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 16:09:18
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 16:19:24
 * @FilePath: \CPP\多态\temp2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    利用多态技术实现饮品基类，提供子类制作咖啡和茶叶
*/
#include <iostream>

using namespace std;

class AbstractorDrinking
{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pour_in_cup() = 0;
    virtual void put_something() = 0;
    
    void make_drink()
    {
        boil();
        brew();
        pour_in_cup();
        put_something();

    }
};


class Coffe : public AbstractorDrinking
{
public:
    void boil()
    {   
        cout << "nongfushanquan" << endl;
    }
    void brew()
    {
        cout << "kafei" << endl;
    }
    void pour_in_cup()
    {
        cout << "dao beizi" << endl;
    }
    void put_something()
    {
        cout << "tang&niunai" << endl;
    }
};
class Tea : public AbstractorDrinking
{
public:
    void boil()
    {   
        cout << "kuangquanshui" << endl;
    }
    void brew()
    {
        cout << "chong cha" << endl;
    }
    void pour_in_cup()
    {
        cout << "dao beizi" << endl;
    }
    void put_something()
    {
        cout << "gouqi" << endl;
    }
};

void do_make(AbstractorDrinking* abs)
{
    abs->make_drink();
    delete abs;
}

void test()
{
    do_make(new Coffe);
    cout << "-----------" << endl;
    do_make(new Tea);
}

int main()
{
    test();

    return 0;
}