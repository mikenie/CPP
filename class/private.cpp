/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-08 18:19:42
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-08 18:31:29
 * @FilePath: \CPP\class\private.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

class Person{

    public:
        Person()
        {
            this->m_name = "Li Si";
            this->m_age = 10;
            this->m_lover = "No";
        }
        
        void write_name(const string& name)
        {
            this->m_name = name;
        }
        
        string read_name()
        {
            return this->m_name;
        } 

        int read_age()
        {
            return this->m_age;
        }
    private:
        string m_name;
        int m_age;
        string m_lover;
};

int main()
{
    Person person_1;

    person_1.write_name("Zhang San");
    cout << person_1.read_name() << endl;
    cout << "age: " << person_1.read_age() << endl;

    return 0;
}