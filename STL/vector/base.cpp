/*
 * @Author: Nie Chun
 * @Date: 2023-01-26 23:57:10
 * @LastEditors: niemike niemike@outlook.com
 * @LastEditTime: 2023-01-27 00:12:29
 * @FilePath: \CPP\STL\vector\base.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void my_print(int val)
{
    cout << val << endl;
}

void test()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(10);
    v.push_back(100);
    
    vector<int>::iterator it_begin = v.begin();
    vector<int>::iterator it_end = v.end(); // ->last_index + 1

    for(;it_begin != it_end; it_begin++)
    {
        cout << *it_begin << endl; 
    } 
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << endl;        
    }
    for_each(v.begin(), v.end(), my_print);
}

int main()
{
    test();

    return 0;
}
