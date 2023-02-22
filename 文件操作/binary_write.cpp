/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 17:44:57
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 23:43:18
 * @FilePath: \CPP\文件操作\binary_write.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    将binary_write写入的Person对象读出
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
    ofstream ofs;
    ofs.open("./binary_write.txt", ios::out | ios::binary);

    Person p = {"Zhang San", 18};

    ofs.write((const char*)&p, sizeof(Person));

    ofs.close();
}

int main()
{
    test();

    return 0;
}