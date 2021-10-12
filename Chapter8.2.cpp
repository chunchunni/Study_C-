#include <iostream>
#include <string>

using namespace std;

int add(int a = 1, int b = 2, int c = 3); //给函数设置默认参数时，只能在声明处添加，且实现处不能添加

long left(int num1, int num2);
string left(string str1, string str2);
/*
    函数重载的关键在于函数的参数列表的不同，也即函数特征标的不同。
    而变量名和变量名的返回类型是无关紧要的。
    eg：
        long left(int num1, int num2);
        double left(int num1, int num2);
        错误例子，因为不能通过改变返回类型来设置重载

        类型引用和类型本身是同一个特征标
        double cube(int x);
        double cube(int &x);
        错误例子，因为x和int x以及int &x都匹配，编译器无法选择用哪一个。

*/

template <typename T>
void Swap(T &a, T &b);

/*
    模板可以不指定类型来定义函数。
    即通过template来将类型进行重新命名，使用时编译器会将类型作为参数传递给模板，使编译器生成该类型的函数。
    需要注意的是，template的声明在函数的定义和函数原型处都需要加上。

    显示具体化是指提供一个具体化函数定义，其中包括模板重载所需的其他代码。
    eg:
        例如Swap模板只能用于交换变量、整个结构体，而不能用于交换结构体中的一部分变量。
        此时如果要实现这一部分功能，就需要添加额外的代码。
    当编译器找到与函数调用相匹配的具体化定义时，将使用该定义，不再找其他模板。

    编译器调用优先级：
        非模板函数>具体化模板>常规模板
*/

struct job
{
    string jobname;
    int salary;
};

template <> void Swap<job> (job &, job &); //模板显示具体化


int main()
{
    int a = 5, b =6;
    // 默认参数是让用户使用不同数目的参数调用同一个函数
    cout << add(a,b) << endl; // a + b + 3
    cout << add(4) << endl; // 4 + 2 + 3
    cout << add(4, 5) << endl; // 4 + 5 + 3
    cout << add() << endl; // 1 + 2 + 3

    // 函数多态(重载)是指可以有多个同名的函数
    cout << left(1,2) << endl;
    cout << left("a","b") << endl;

    cout << "a: " << a << " b: " << b << endl;
    Swap(a, b); //此时模板被初始化为int型;小写swap是C++中自带的函数，这样会使得重载分不清到底作用于谁
    cout << "a: " << a << " b: " << b << endl;

    double c = 1.0, d = 2.0;
    cout << "c: " << c << " d: " << d << endl;
    Swap(c, d); //此时模板被初始化为int型;小写swap是C++中自带的函数，这样会使得重载分不清到底作用于谁
    cout << "c: " << c << " d: " << d << endl;

    job j1 = {"Worker", 100}, j2 = {"Zibenjia", 10000};
    cout << j1.jobname << " " << j1.salary << endl;
    cout << j2.jobname << " " << j2.salary << endl;
    Swap(j1, j2);
    cout << j1.jobname << " " << j1.salary << endl;
    cout << j2.jobname << " " << j2.salary << endl;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

long left(int num1, int num2)
{
    return num1 + num2;
}

string left(string str1, string str2)
{
    return str1 + str2;
}


template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job> (job & j1, job & j2)
{
    string temp1;
    int temp2;
    temp1 = j1.jobname;
    temp2 = j1.salary;
    j1.jobname = j2.jobname;
    j1.salary  = j2.salary;
    j2.jobname = temp1;
    j2.salary = temp2;
}
