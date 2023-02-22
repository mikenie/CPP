/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 16:06:10
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 16:36:43
 * @FilePath: \CPP\class\friend_3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Building; // 前向声明

class Goodgay
{
public:
    Goodgay();
    void visit_1();
    void visit_2();

    Building* building; // 前向声明的类不能实例化对象
};

class Building
{
    friend void Goodgay::visit_1();
    
public:
    Building();
    
    string sittingroom;
private:
    string bedroom;
};

// 先定义Building类的函数，再定义Goodgay类的定义
Building::Building()
{   
    sittingroom = "keting";
    bedroom = "woshi";
}

Goodgay::Goodgay()
{
    building = new Building;
}
void Goodgay::visit_1()
{
    cout << "visit sittingroom" << building->sittingroom << endl;
    cout << "visit bedroom" << building->bedroom << endl;
}
void Goodgay::visit_2()
{
    cout << "visit sittingroom" << building->sittingroom << endl;
    //cout << "visit bedroom" << building->bedroom << endl;
}


void test()
{
    Goodgay g_1;
    g_1.visit_1();
    g_1.visit_2();
}

int main()
{
    test();

    return 0;
}