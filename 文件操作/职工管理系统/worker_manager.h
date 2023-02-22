/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 23:47:07
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 19:55:55
 * @FilePath: \CPP\文件操作\职工管理系统\workerManager.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>

#define FILENAME "empFile.txt"

using namespace std;

class Workermanager
{
public:
    Workermanager();
    ~Workermanager();

    void show_menu();
    void exit_menu();
    void add_emp();
    void save_file();
    int get_emp_num_inFile();
    void init_emp();
    void show_worker_info();
    int is_emp_exist(int id);
    void del_emp();
    void modify_emp();
    void find_emp();
    void sort_emp();
    void clean_file();
    
    int m_emp_num;
    Worker** m_emp_array;

    bool is_File_OK;
};