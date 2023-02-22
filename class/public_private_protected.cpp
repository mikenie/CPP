/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-07 11:30:03
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-07 11:53:04
 * @FilePath: \CPP\class\public_private_protected.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Person{

    public:
        string name;
    protected:
        string car;
    private:    
        string m_password;

    public:
        void setup_info(const string& car, const string& password)
        {
            this->car = car;
            this->m_password = password;
        }

        void show_info()
        {
            cout << "name: " << this->name << endl;
            cout << "car: " << this->car << endl;
            cout  << "password: " << this->m_password << endl;
        }
};

int main()
{
    Person father;
    
    father.name = "Zhang San";
    //father.car  = "Wu ling"; // illegal
    //father.m_password = "mmmm"; // illegal

    father.setup_info("wu ling", "kkkk");
    father.show_info();
    
    return 0;
}