/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-10 15:53:16
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-10 16:05:08
 * @FilePath: \CPP\class\friend_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Building
{
    friend class Goodgay; // 友元类
    
public:
    Building()
    {
        m_sittingroom = "keting";
        m_bedroom = "woshi";
    }

    string m_sittingroom;

private:
    string m_bedroom;
};

class Goodgay
{
public:
    Goodgay()
    {
        building = new Building;
    }
    void visit()
    {
        cout << "visit sittingroom" << building->m_sittingroom << endl;
        cout << "visit bedroom" << building->m_bedroom << endl;
    }
    
    Building* building;

};

void test()
{
    Goodgay g_1;
    g_1.visit();
}

int main()
{
    test();

    return 0;
}