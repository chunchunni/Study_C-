#include <iostream>
#include "coordin.h"

/*
    文件名在尖括号中表示编译器在主机的文件系统中查找
    在双引号中，编译器会首先查找当前的工作目录或源代码目录

    头文件“.h”应该包括：
        函数原型
        #define或const定义的符号常量
        结构声明
        类声明
        模板声明
        内联函数
    
    函数源代码文件：
        包含与结构有关的函数的代码。即专门用于编写函数主体内容。
    
    调用源代码文件：
        包含调用与结构有关的函数的代码。即主程序所在的文件。

    当使用g++编译器进行编译链接时，需要将相关的.cpp文件都生成.o文件后进行链接
    常用方法为g++ *.cpp
*/

using namespace std;

int main()
{
    rect r;
    r.x = 5;
    r.y = 5;
    polar p;
    p = rect_to_polar(r);
    showPolar(p);
}
