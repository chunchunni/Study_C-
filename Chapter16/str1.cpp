// str1.cpp -- introducing the string class
#include <iostream>
#include <string>
// using string constructors

int main()
{
    using namespace std;
    string one("Lottery Winner!");     // ctor #1
    cout << one << endl;               // overloaded <<
    
    string two(20, '$');               // ctor #2  将字符$拷贝20次
    cout << two << endl;
    
    string three(one);                 // ctor #3
    cout << three << endl;
    one += " Oops!";                   // overloaded +=
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';
    
    string four;                       // ctor #4
    four = two + three;                // overloaded +, =
    cout << four << endl;
    char alls[] = "All's well that ends well";
    
    string five(alls,20);              // ctor #5  整数参数表示要复制多少个字符
    cout << five << "!\n";
    
    string six(alls+6, alls + 10);     // ctor #6  表示截取[begin,end)
    cout << six  << "\n";
    
    //string seven(five + 6, five + 10);  是错误的，因为对象名不会被当作对象的地址
    string seven(&five[6], &five[10]); // ctor #6   对象名不会被当作对象的地址，而five[6]是一个char值，故&是其地址
    cout << seven << "\n";
    
    string eight(four, 7, 16);         // ctor #7   从7开始，将four中的16个字符复制过来
    cout << eight << endl;

    string a = alls;    //可以直接将数组用于初始化，也可以用{}列表进行初始化
    cout << a << endl;


    return 0; 
}
