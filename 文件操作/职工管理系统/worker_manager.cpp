/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 23:48:17
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 20:17:07
 * @FilePath: \CPP\文件操作\职工管理系统\workerManager.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "worker_manager.h"

Workermanager::Workermanager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    /* 1. 文件不存在 */
    if(!ifs.is_open())
    {
        cout << "file not exist, new file created" << endl;
        /* 创建文件 */
        ofstream ofs;
        ofs.open(FILENAME, ios::out);
        ofs.close();
        
        m_emp_num = 0;
        m_emp_array = NULL;

        is_File_OK = false;

        return;    
    }

    /* 2. 文件存在，但是数据被清零 */
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "file empty" << endl;
        
        m_emp_num = 0;
        m_emp_array = NULL;

        ifs.close(); // 关闭文件
        
        is_File_OK = false;
        
        return;
    }

    /* 3. 文件存在，且数据不为空 */
    m_emp_num = this->get_emp_num_inFile(); // 获取worker数
    cout << "num of employee: " << m_emp_num << endl;
    this->m_emp_array = new Worker*[m_emp_num]; // 初始化数组
    this->init_emp(); // 文件数据复制到数组中

    is_File_OK = true;
}

Workermanager::~Workermanager()
{
    if(this->m_emp_array != NULL)
    {
        delete [] this->m_emp_array;
        this->m_emp_array = NULL;
    }
}

void Workermanager::show_menu()
{
    cout << "----------" << endl;
    cout << "welcome" << endl;
    cout << "0:quit" << endl;
    cout << "1:add" << endl;
    cout << "2:show" << endl;
    cout << "3:delete" << endl;
    cout << "4:change" << endl;
    cout << "5:find" << endl;
    cout << "6:queue" << endl;
    cout << "7:clear" << endl;
    cout << "----------" << endl;
    cout << endl;
}

void Workermanager::exit_menu()
{
    cout << "welcome your next visit" << endl;
    exit(0);
}

void Workermanager::add_emp()
{
    int add_num = 0;
    cout << "num of employee:";
    cin >> add_num;
    
    if(add_num <= 0)
    { 
        cout << "error"<< endl;
        return;
    }
    int new_size = this->m_emp_num + add_num; // 加新员工后， 员工总数 
    Worker** new_space = new Worker*[new_size]; // 创建新空间
    /* 拷贝原数据 */
    for(int i = 0; i < this->m_emp_num; i++)
    {
        new_space[i] = m_emp_array[i];
    }
    /* 添加新数据 */
    for(int i = 0; i<add_num; i++)
    {
        int id;
        string name;
        int ds;

        cout << "the " << i+1 << " worker " << "id: ";
        cin >> id;
        cout << "the " << i+1 << " worker " << "name: ";
        cin >> name;
        cout << "the " << i+1 << " worker " << "department_id: ";
        cin >> ds;

        Worker* tmp_worker = NULL;
        switch (ds)
        {
        case 1:
            tmp_worker = new Employee(id, name, ds);
            break;
        case 2:
            tmp_worker = new Manager(id, name, ds);
            break;
        case 3:
            tmp_worker = new Boss(id, name , ds);
            break;
        default:
            break;
        }

        new_space[this->m_emp_num + i] = tmp_worker;       
    }

    delete [] this->m_emp_array; // 将数据更新
    this->m_emp_array = new_space;
    this->m_emp_num = new_size;

    cout << "success" << endl;

    this->save_file();

    is_File_OK = true;
}

void Workermanager::save_file()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 不会进行追加

    for(int i = 0; i<this->m_emp_num; i++)
    {
        ofs << this->m_emp_array[i]->m_id << " "
            << this->m_emp_array[i]->m_name << " "
            << this->m_emp_array[i]->m_department_id << endl;
    }

    ofs.close();
}

int Workermanager::get_emp_num_inFile()
{
    int tmp_emp_num = 0;

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int tmp_id;
    string tmp_name;
    int tmp_department_id;

    while(ifs >> tmp_id && ifs >> tmp_name && ifs >> tmp_department_id)
    {
        tmp_emp_num++; 
    }
    
    ifs.close();
    
    return tmp_emp_num;
}

void Workermanager::init_emp()
{
    ifstream ifs;

    ifs.open(FILENAME, ios::in);

    int tmp_id;
    string tmp_name;
    int tmp_department_id;

    int tmp_emp_num = 0;

    while(ifs >> tmp_id && ifs >> tmp_name && ifs >> tmp_department_id)
    {
        Worker* worker = NULL;
        switch (tmp_department_id)
        {
        case 1:
            worker = new Employee(tmp_id, tmp_name, tmp_department_id);
            break;
        case 2:
            worker = new Manager(tmp_id, tmp_name, tmp_department_id);
            break;
        case 3:
            worker = new Boss(tmp_id, tmp_name, tmp_department_id);
            break;
        default:
            break;
        }

        this->m_emp_array[tmp_emp_num++] = worker;
    }

    ifs.close();
}

void Workermanager::show_worker_info()
{
    if(!is_File_OK) cout << "no worker" << endl;
    else 
    {
        for(int i = 0; i<this->m_emp_num; i++)
        {
            // cout << "id:" 
            //      << this->m_emp_array[i]->m_id << " "
            //      << "name:"
            //      << this->m_emp_array[i]->m_name << " "
            //      << "department:" 
            //      << this->m_emp_array[i]->m_department_id << endl;
            this->m_emp_array[i]->show_info(); // 多态特性
        }
    }
}

int Workermanager::is_emp_exist(int id)
{
    for(int i = 0; i<this->m_emp_num; i++)
    {
        if(this->m_emp_array[i]->m_id == id)
        {
            cout << "find worker index: " << i << endl;
            return i;
        } 
    }

    return -1; // -1表示没有找到
}

void Workermanager::del_emp()
{
    int tmp_id;
    int index;

    cout << "worker id:";
    cin >> tmp_id;
    cout << endl;

    if((index = this->is_emp_exist(tmp_id)) != -1)
    {    
        if(m_emp_num > 1)
        {
            Worker** worker = new Worker*[m_emp_num-1];
            for(int i = 0; i<index; i++)
            {
                worker[i] = this->m_emp_array[i];
            }
            if(index < this->m_emp_num-1)
            {
                for(int i = index; i<m_emp_num-1; i++)
                {
                    worker[i] = this->m_emp_array[i+1];
                }
            }

            delete [] this->m_emp_array;
            this->m_emp_array = worker;
            this->m_emp_num--;
        }
        else
        {
            this->m_emp_array = NULL;
            this->m_emp_num = 0;
            delete [] this->m_emp_array;
        }

        this->save_file();
    }
    else
    {   
        cout << "worker don't exist" << endl;
    }
}

void Workermanager::modify_emp()
{
    int tmp_id;
    int index;
    
    cout << "id:";
    cin >> tmp_id;
    cout << endl;

    if((index = this->is_emp_exist(tmp_id)) != -1)
    {
        delete this->m_emp_array[index];
        
        int new_id;
        string new_name;
        int new_department_id;

        cout << "new id:"; cin >> new_id; cout << endl;
        cout << "new name:"; cin >> new_name; cout << endl;
        cout << "new department id:"; cin >> new_department_id; cout << endl;
        
        Worker* worker = NULL;
        switch (new_department_id)
        {
        case 1:
            worker = new Employee(new_id, new_name, new_department_id);
            break;
        case 2:
            worker = new Manager(new_id, new_name, new_department_id);
            break;
        case 3:
            worker = new Boss(new_id, new_name, new_department_id);
            break;        
        default:
            break;
        }

        this->m_emp_array[index] = worker;
        this->save_file();
    }
    else cout << "not find" << endl;
}

void Workermanager::find_emp()
{   
    int f_type;
    bool is_find = false;
    int index_ret;

    int tmp_id;
    string tmp_name;

    cout << "name:1 or id:2 ?";
    cin >> f_type;
    cout << endl;

    if(f_type == 1)
    {   
        cout << "name:"; cin >> tmp_name; cout << endl;
        for(int i=0; i<this->m_emp_num; i++)
        {
            if(this->m_emp_array[i]->m_name == tmp_name)
            {
                this->m_emp_array[i]->show_info();
                is_find = true;
                break;
            }
        }
    }
    else 
    {
        cout << "id:"; cin >> tmp_id; cout << endl;
        if((index_ret = this->is_emp_exist(tmp_id)) != -1)
        {
            this->m_emp_array[index_ret]->show_info();
            is_find = true;
        }
    }

    if(!is_find) cout << "not find" << endl;
}

void Workermanager::sort_emp()
{
    if(!is_File_OK) 
    {
        cout << "no worker" << endl;
        return;
    }

    int choice;

    cout << "big first:1" << endl << "low first:2\n";
    cin >> choice; cout << endl;

    int temp_id;
    string temp_name;
    int temp_department_id;
    if(choice == 1)
    {
        /* 愚蠢的冒泡 */
        for(int i = 0; i<this->m_emp_num; i++)
        {
            for(int j = i; j<this->m_emp_num; j++)
            {
                if(this->m_emp_array[i]->m_id < this->m_emp_array[j]->m_id)
                {
                    temp_id = this->m_emp_array[i]->m_id;
                    temp_name = this->m_emp_array[i]->m_name;
                    temp_department_id = this->m_emp_array[i]->m_department_id;

                    this->m_emp_array[i]->m_id = this->m_emp_array[j]->m_id;
                    this->m_emp_array[i]->m_name = this->m_emp_array[j]->m_name;
                    this->m_emp_array[i]->m_department_id = this->m_emp_array[j]->m_department_id;

                    this->m_emp_array[j]->m_id = temp_id;
                    this->m_emp_array[j]->m_name = temp_name;
                    this->m_emp_array[j]->m_department_id = temp_department_id;
                } 
            }
        }
    }
    else 
    {
        for(int i = 0; i<this->m_emp_num; i++)
        {
            for(int j = i; j<this->m_emp_num; j++)
            {
                if(this->m_emp_array[i]->m_id > this->m_emp_array[j]->m_id)
                {
                    temp_id = this->m_emp_array[i]->m_id;
                    temp_name = this->m_emp_array[i]->m_name;
                    temp_department_id = this->m_emp_array[i]->m_department_id;

                    this->m_emp_array[i]->m_id = this->m_emp_array[j]->m_id;
                    this->m_emp_array[i]->m_name = this->m_emp_array[j]->m_name;
                    this->m_emp_array[i]->m_department_id = this->m_emp_array[j]->m_department_id;

                    this->m_emp_array[j]->m_id = temp_id;
                    this->m_emp_array[j]->m_name = temp_name;
                    this->m_emp_array[j]->m_department_id = temp_department_id;
                } 
            }
        }
    } 

    this->save_file();
}

void Workermanager::clean_file()
{   
    string choice;

    cout << "type yes for sure: ";
    cin >> choice; cout << endl;

    if(choice != "yes")
    {
        cout << "op cancle" << endl;
        return;
    } 

    /* 清除文件 */
    ofstream ofs;
    ofs.open(FILENAME, ios::trunc);
    ofs.close();

    /* 释放堆区 */
    if(this->m_emp_array != NULL)
    {
        for(int i = 0; i<m_emp_num; i++)
        {
            if(this->m_emp_array[i] != NULL) 
            {
                delete this->m_emp_array[i];
            }
        }
    }

    delete [] this->m_emp_array;
    this->m_emp_array = NULL;

    this->is_File_OK = false;
    
    cout << "clean op done" << endl;
}
