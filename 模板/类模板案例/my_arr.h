/*
 * @Author: Nie Chun
 * @Date: 2023-01-21 14:44:18
 * @LastEditors: niemike niemike@outlook.com
 * @LastEditTime: 2023-01-26 23:22:57
 * @FilePath: \CPP\模板\类模板案例\my_arr.h
 */
#pragma once 
#include <iostream>

using namespace std;

template<class T>
class My_arr
{
public:
    My_arr(int cap);
    My_arr(const My_arr& arr);
    ~My_arr();

    My_arr& operator=(const My_arr& arr);
    void push_back(const T& val);
    void pop_back();
    T& operator[](int index);   
    int get_cap();
    int get_size();

private:
    T* p_addr;
    int m_cap;
    int m_size;
};