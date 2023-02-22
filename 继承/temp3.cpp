/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 16:39:41
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 17:02:25
 * @FilePath: \CPP\继承\temp3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    内容：
    三个零件实现电脑组装:CPU, GPU, MEMORY
    将每个零件封装成抽象基类，并提供不同的厂商生产不同的零件
*/
#include <iostream>

using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
};

class GPU
{
public:
    virtual void display() = 0;
};

class MEMROTY
{
public:
    virtual void store() = 0;
};

class Computer
{
public:
    Computer(CPU* cpu, GPU* gpu, MEMROTY* memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    ~Computer()
    {
        if(m_cpu != NULL) delete m_cpu;
        if(m_gpu != NULL) delete m_gpu;
        if(m_memory != NULL) delete m_memory;
    }

    void do_work()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_memory->store();
    }

private:
    CPU* m_cpu;
    GPU* m_gpu;
    MEMROTY* m_memory;
};

/* Intel */
class Intel_CPU : public CPU
{
public:
    void calculate()
    {
        cout << "Intel cpu working" << endl;
    }
};

class Intel_GPU : public GPU
{
public: 
    void display()
    {
        cout << "Nvdia gpu working" << endl;
    }
};

class Intel_MEMORY : public MEMROTY
{
public:
    void store()
    {
        cout << "Intel memroty storing" << endl;
    }
};
/* DIY */
class DIY_CPU : public CPU
{
public:
    void calculate()
    {
        cout << "DIY cpu working" << endl;
    }
};

class DIY_GPU : public GPU
{
public: 
    void display()
    {
        cout << "DIY gpu working" << endl;
    }
};

class DIY_MEMORY : public MEMROTY
{
public:
    void store()
    {
        cout << "DIY memroty storing" << endl;
    }
};

void test()
{
    CPU* intel_cpu = new Intel_CPU;
    GPU* intel_gpu = new Intel_GPU;
    MEMROTY* Intel_memory = new Intel_MEMORY;

    Computer* computer1 = new Computer(intel_cpu, intel_gpu, Intel_memory);
    computer1->do_work();
    delete computer1;

    cout << "--------------" << endl;
    Computer* computer2 = new Computer(new DIY_CPU, new DIY_GPU, new DIY_MEMORY);
    computer2->do_work();
    delete computer2;

    cout << "--------------" << endl;
    Computer* computer3 = new Computer(new DIY_CPU, new Intel_GPU, new DIY_MEMORY);
    computer3->do_work();
    delete computer3;   
}

int main()
{
    test();

    return 0;

