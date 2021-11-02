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

    当使用g++编译器进行编译链接时，需要将相关的.cpp文件(不同的cpp中只能有一个main)都生成.o文件后进行链接
    常用方法为g++ *.cpp
*/

using namespace std;

int global = 100; //静态外部链接变量
static int file = 50; //静态内部链接变量

int file_global; 

    /*
    外部链接性：其他文件中可访问
    内部链接性：只能在当前文件中访问
    无链接性：只能在代码块中访问
    
    func中静态变量count和普通自动变量的区别在于，存在周期是全局的。
    
    静态变量会被系统自动初始化为0，但是用户给定的表达式或者常量会对其再进行赋值。

    外部变量的使用规则：
        每个使用外部变量的文件中都应该对该变量进行声明。
        变量只能有一次定义，声明和定义不能混淆。引用声明使用extern，且不进行初始化，否则声明为定义。

    如果要在其他文件中使用与外部变量名称相同的变量，则需要使用static关键字
    file1:
        int errors = 20;
    file2:
        static errors = 5;
    这并没有违反单定义规则，static指出标识符errors的链接性为内部，并非要提供外部定义

    */


int main()
{
    rect r;
    r.x = 5;
    r.y = 5;
    polar p;
    p = rect_to_polar(r);
    showPolar(p);

    int Outervalue = 3;
    {
        int Innervalue = 4;
        cout << "Outervalue = " << Outervalue << endl; //全局的可以在局部用
        cout << "Innervalue = " << Innervalue << endl;
    }
    //cout << "Innervalue = " << Innervalue << endl; 出错，因为Innervalue的作用域只在自己的局部代码块中

    {
        int Outervalue = 4;
        cout << "Outervalue = " << Outervalue << endl; //新的定义隐藏之前的定义
    } 
    cout << "Outervalue = " << Outervalue << endl; //离开代码块，此前的定义又可用

    
    cout << "file_global: " << file_global <<endl;
    file_global = 55;
    cout << "file_global: " << file_global <<endl;

    char buffer[50];
    char *p1;
    p1 = new (buffer) char; //一般情况下new在堆中找到满足要求的内存块，但是可以通过定位new运算符指定要使用的位置。
    cout << "buffer " << &buffer <<endl;
    cout << "p1 " << &p1 <<endl;




}

void func(int q)
{
    static int count = 0; //静态变量
}
