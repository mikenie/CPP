/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-07 11:18:42
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-07 11:27:57
 * @FilePath: \CPP\class\student.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

class Student{
    public:
        std::string name; // namespace std is requiredd 
        int id;

        void show_info()
        {
            std::cout << "name: " << name << std::endl;
            std::cout << "id: " << id << std::endl;            
        }
        void setup_info(const std::string& name, const int& id)
        {
            this->name = name;
            this->id = id;
        }
};

int main()
{
    Student student_1;

    student_1.name = "Zhang san";
    student_1.id   = 1;

    student_1.show_info();

    student_1.setup_info("Li Si", 2);
    student_1.show_info();
    
    return 0;
}