/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-16 00:07:31
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-18 16:48:47
 * @FilePath: \CPP\文件操作\职工管理系统\worker.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    virtual void show_info() = 0;
    virtual string get_department_name() = 0;

    int m_id;
    string m_name;
    int m_department_id;
};

class Employee : public Worker
{
public:
    Employee(int id, string name, int department_id);
    ~Employee();

    void show_info();
    string get_department_name();
};

class Manager : public Worker
{
public:
    Manager(int id, string name, int department_id);
    ~Manager();

    void show_info();
    string get_department_name();
};

class Boss : public Worker
{
public:
    Boss(int id, string name, int department_id);
    ~Boss();

    void show_info();
    string get_department_name();
};

