/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 17:24:36
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:38:05
 * @FilePath: \CPP\文件操作\read.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream ifs;

    ifs.open("./test.txt", ios::in);

    if(!ifs.is_open())
    {
        cout << "error when open file" << endl;
        return 0;
    }
    
    cout << "-----1-----" << endl;
    char buf[1024] = {0};
    ifs >> buf;
    cout << buf << endl;
    cout << "-----2-----" << endl;
    while(ifs.getline(buf, sizeof(buf)))
    {
        cout << buf;
    }
    cout << "-----3-----" << endl;
    string s;
    while(getline(ifs, s))
    {
        cout << s;
    }
    cout << "-----4-----" << endl;
    char c;
    while((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    return 0;
}