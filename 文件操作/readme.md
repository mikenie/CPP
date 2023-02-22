<!--
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2023-01-15 17:03:51
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2023-01-15 23:29:51
 * @FilePath: \CPP\文件操作\readme.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# 文本操作
程序运行时的数据都是临时数据，通过文件可以将数据持久化。
C++中对文件操作需要包含 fstream

## 文件类型分两种
### 1、文本文件
### 2、二进制文件

## 操作文件的三大类
### 1、ofstream: write
### 2、ifstream: read
### 3、fstream: write&read

## 一、文本文件
### 写文件
#### 1、包含头文件
```c++
#include <fstream>
```
#### 2、创建流对象
```c++
ofstream ofs;
```
#### 3、打开文件
```c++
ofs.open(PATH, 打开方式);
```
#### 4、写数据
```c++
ofs << DATA;
```
#### 5、关闭文件
```c++
ofs.close();
```
### 打开方式
ios::in, ios::out, ios::ate, ios::app, ios::trunc, ios::binary
### 读文件
#### 1、包含头文件
```c++
#include <fstream>
```
#### 2、创建流对象
```c++
ifstream ifs;
```
#### 3、打开文件并判断是否打开成功
```c++
if(ifs.is_open())
{
    "do something"
}
```
#### 4、读数据
```c++ 
/* 1 */
char buf[N] = {0};
ifs >> buf;
/* 2 */
char buf[N] = {0};
while(ifs.getline(buf, sizeof(buf)))
{
    cout << buf << endl;
}
/* 3 */
string s;
while(getline(ifs, s))
{
    cout << s << endl;
}
/* 4 */ 
char c;
while((c = ifs.get()) != EOF)
{
    cout << c << endl;
}
```
#### 5、关闭文件
```c++
ifs.close();
```
## 二、二进制文件
以二进制方式对文件进行读写操作，打开方式指定为ios::binary
### 写文件
#### 1、包含头文件
#### 2、创建流对象
#### 3、打开文件
```c++
ofs.open(PATH， ios::out|ios::binary);
```
#### 4、写文件
#### 5、关闭文件
