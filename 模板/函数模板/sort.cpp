/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-20 21:21:00
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-20 21:30:29
 * @FilePath: \CPP\模板\sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

template<class T>
void my_sort(T arr[], int len) // 选择排序
{
    for(int i = 0; i<len; i++)
    {
        int max_index = i; // 认定最大值下标
        for(int j = i+1; j<len; j++)
        {
            if(arr[max_index] < arr[j])
            {
                max_index = j; // 更新最大值下标
            }
        } 
        if(max_index != i)
        {
            /* 交换元素 */
            T temp = arr[max_index];
            arr[max_index] = arr[i];
            arr[i] = temp;
        }
    }
}

template<class T>
void print_arr(T arr[], int len)
{
    for(int i = 0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
}
void test()
{
    char ch_arr[] = "adfas";
    my_sort(ch_arr, sizeof(ch_arr));
    print_arr(ch_arr, sizeof(ch_arr));

    cout << "-----------" << endl;
    int int_arr[] = {1,3421,5312,534,43};
    my_sort(int_arr, sizeof(int_arr)/sizeof(int));
    print_arr(int_arr, sizeof(int_arr)/sizeof(int));
}

int main()
{
    test();
    
    return 0;
}