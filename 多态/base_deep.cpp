/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-14 22:54:18
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:29
 * @FilePath: \CPP\多态\base_deep.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    C++必须掌握的内容
*/
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "animals are talking" << endl;
    }
};

void test()
{
    cout << sizeof(Animal) << endl; // speak函数加上virtual关键字之后，变为8：指针的大小
}

int main()
{
    test();

    return 0;
}