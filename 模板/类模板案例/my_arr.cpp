/*
 * @Author: Nie Chun
 * @Date: 2023-01-21 14:44:28
 * @LastEditors: niemike niemike@outlook.com
 * @LastEditTime: 2023-01-26 23:22:28
 * @FilePath: \CPP\模板\类模板案例\my_arr.cpp
 */
#include "my_arr.h"
#include <iostream>

using namespace std;

/* 有参构造 */
template<class T>
My_arr<T>::My_arr(int cap)
{
    cout << "param constructor" << endl;
    this->m_cap = cap;
    this->m_size = 0;
    this->p_addr = new T[this->m_cap];
}

/* 拷贝构造 */
template<class T>
My_arr<T>::My_arr(const My_arr<T>& arr)
{   
    cout << "copy constructor" << endl;
    this->m_cap = arr.m_cap;
    this->m_size = arr.m_size;

    this->p_addr = new T[arr.m_cap];
    for(int i = 0; i<this->m_size; i++)
    {
        this->p_addr[i] = arr.p_addr[i];
    }
}

template<class T>
My_arr<T>& My_arr<T>::operator=(const My_arr<T>& arr)
{
    cout << "operator =" << endl;
    if(this->p_addr != NULL)
    {
        delete [] this->p_addr;
        this->p_addr = NULL;
        this->m_cap = 0;
        this->m_size = 0; 
    }

    this->m_cap = arr.m_cap;
    this->m_size = arr.m_size;
    this->p_addr = new T[arr.m_cap];
    for(int i = 0; i<arr.m_size; i++)
    {
        this->p_addr[i] = arr.p_addr[i];
    }

    return *this;
}

template<class T>
My_arr<T>::~My_arr()
{
    cout << "destructor" << endl;
    if(this->p_addr != NULL)
    {
        delete [] p_addr;
    }
}

/* 尾插 */
template<class T>
void My_arr<T>::push_back(const T& val)
{
    if(this->m_cap == this->m_size)
    {
        cout << "full, return" << endl;
        return;
    }

    this->p_addr[this->m_size] = val;
    this->m_size++;
}

/* 尾删 */
template<class T>
void My_arr<T>::pop_back()
{
    if(this->m_size == 0)
    {
        cout << "empty, return" << endl;
        return;
    }

    this->m_size--;
}

template<class T>
T& My_arr<T>::operator[](int index)
{
    return this->p_addr[index];
}

template<class T>
int My_arr<T>::get_cap()
{
    return this->m_cap;
}

template<class T>
int My_arr<T>::get_size()
{
    return this->m_size;
}
