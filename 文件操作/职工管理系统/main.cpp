/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 23:52:14
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 20:08:13
 * @FilePath: \CPP\文件操作\职工管理系统\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "worker_manager.h"
#include "worker.h"

using namespace std;

int main()
{
    Workermanager workermanager;

    int choice = 0; // 菜单选项
    
    while(true)
    {
        workermanager.show_menu();
        cout << "your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出
            workermanager.exit_menu();
            break;
        case 1:
            workermanager.add_emp();
            break;
        case 2:
            workermanager.show_worker_info();
            break;
        case 3:
            workermanager.del_emp();
            break;
        case 4:
            workermanager.modify_emp();
            break;
        case 5:
            workermanager.find_emp();
            break;
        case 6:
            workermanager.sort_emp();
            break;
        case 7:
            workermanager.clean_file();
            break;
        default:
            break;
        } 
    }
    

    return 0;
}