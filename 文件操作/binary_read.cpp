/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 23:26:02
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 23:29:35
 * @FilePath: \CPP\文件操作\binary_read.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <fstream>
#include <iostream>

using namespace std;

class Person
{
public:    
    char m_name[128];
    int m_age;
};

void test()
{
    ifstream ifs;

    ifs.open("./binary_write.txt", ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout << "read error" << endl;
    }

    Person p;
    ifs.read((char*)&p, sizeof(Person));
    cout << p.m_name << ":" << p.m_age << endl;
    ifs.close();
}

int main()
{
    test();

    return 0;
}