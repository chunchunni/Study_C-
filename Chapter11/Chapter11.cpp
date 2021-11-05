#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;
 
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing; //运算符重载, 即通过重新编写函数对运算符的操作进行重载
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);

    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    /*
        this指针的使用条件是函数得声明为和对象一样的类型。
        可以使用：
            (*this).成员变量
            this->成员变量
        两种方式访问

        也可以直接在函数中使用成员变量，此时默认的成员变量是来自于调用函数的对象   
    */
    
    Time temp;
    temp = morefixing * 4;
    cout << temp;   //对<<进行重载

    temp = 5 * morefixing;
    cout << temp;
    /*
        一般情况下重载*运算符只能处理：
            对象 * 数字
        而不能处理
            数字 * 对象
        因为前者相当于 对象.operator*(数字)，这是一般的成员函数调用方法
        而后者的数字是没有成员函数的，为了解决这一问题，就引入友元函数，将函数声明为类的友元，就可以访问对象的隐藏参数。
    */
    


    return 0;
}
