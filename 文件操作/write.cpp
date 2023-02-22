/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 17:16:49
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:19:43
 * @FilePath: \CPP\文件操作\write.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <fstream>
#include <iostream>

using namespace std;

void test()
{
    ofstream ofs;

    ofs.open("./test.txt", ios::out);
    ofs << "write something here" << endl;
    ofs << "another line" << endl;
    ofs.close();
}

int main()
{
    test();

    return 0;
}