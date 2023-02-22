/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-16 00:07:38
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-18 16:48:42
 * @FilePath: \CPP\文件操作\职工管理系统\worker.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "worker.h"

/* Emplyee */
Employee::Employee(int id, string name, int department_id)
{
    m_id = id;
    m_name = name;
    m_department_id = department_id;
}
void Employee::show_info()
{
    cout << "id: "; cout << this->m_id << endl;
    cout << "name: " << this->m_name << endl;
    cout << "department id: " << this->m_department_id << endl;
}
string Employee::get_department_name()
{
    return "Employee";
} 

/* Manager */
Manager::Manager(int id, string name, int department_id)
{
    m_id = id;
    m_name = name;
    m_department_id = department_id;
}
void Manager::show_info()
{
    cout << "id: "; cout << this->m_id << endl;
    cout << "name: " << this->m_name << endl;
    cout << "department id: " << this->m_department_id << endl;
}
string Manager::get_department_name()
{
    return "Manager";
} 

/* Boss */
Boss::Boss(int id, string name, int department_id)
{
    m_id = id;
    m_name = name;
    m_department_id = department_id;
}
void Boss::show_info()
{
    cout << "id: "; cout << this->m_id << endl;
    cout << "name: " << this->m_name << endl;
    cout << "department id: " << this->m_department_id << endl;
}
string Boss::get_department_name()
{
    return "Boss";
} 
