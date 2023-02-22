/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-08 21:44:16
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-08 22:17:46
 * @FilePath: \CPP\class\point_and_circle.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int x = 0, int y = 0)
        {
            this->m_x = x;
            this->m_y = y;
        }
        
        void set_point(int x, int y)
        {
            this->m_x = x;
            this->m_y = y;
        }
        int get_x()
        {
            return this->m_x;
        }
        int get_y()
        {
            return this->m_y;
        }
    private:
        int m_x;
        int m_y;
};

class Circle
{   
    public:
        Circle()
        {
            this->m_r = 0;
            this->location.set_point(0, 0);
        }
        void set_r(int r)
        {
            this->m_r = r;
        }
        void set_location(int x, int y)
        {
            this->location.set_point(x, y);
        }
        bool is_in_circle(Point& p)
        {
            int tmp = (this->location.get_x() - p.get_x())*(this->location.get_x() - p.get_x());
            tmp += (this->location.get_y() - p.get_y())*(this->location.get_y() - p.get_y());
            
            if(this->m_r*this->m_r >= tmp) return true;
            else return false;
        }
    private:
        int m_r;
        Point location;
};

int main()
{
    Circle circle_1;
    circle_1.set_location(0, 0);
    circle_1.set_r(1);

    Point p_1(1, 1);

    bool ret = circle_1.is_in_circle(p_1);
    if(ret) cout << "in circle" << endl;
    else cout << "not in circle" << endl;
    
    return 0;
}