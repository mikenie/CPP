/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-08 18:37:25
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-08 21:42:21
 * @FilePath: \CPP\class\cube.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std; 

class Cube{

    public:
        Cube()
        {
            this->m_length = 0;
            this->m_width = 0;
            this->m_height = 0;
        }

        void set_cube(int length, int width, int height)
        {
            this->m_length = length;
            this->m_width = width;
            this->m_height = height;
        }

        int get_v()
        {
            return m_length*m_width*m_height;
        }

        bool is_same_v(Cube& cube_ex)
        {
            if(cube_ex.get_v() == this->get_v()) return true;
            else return false;
        }

    private:
        int m_length;
        int m_width;
        int m_height;
};

bool is_same_v(Cube& cube1, Cube& cube2)
{
    if(cube1.get_v() == cube2.get_v())
    {
        return true;
    }
    else
    { 
        return false;
    }
}

int main()
{
    Cube cube_1;
    Cube cube_2;    
    cube_1.set_cube(1,2,3);
    cube_2.set_cube(1,3,2);
    
    cout << "V1: " << cube_1.get_v() << endl;
    cout << "V2: " << cube_2.get_v() << endl;


    if(is_same_v(cube_1, cube_2)) cout << "same V" << endl;
    else cout << "diff V" << endl;

    if(cube_1.is_same_v(cube_2)) cout << "same V i" << endl;

    return 0;
}