#include <iostream>
#include <climits> //定义符号常量
#include <typeinfo>
using namespace std;

int main()
{
    /*
    C++中变量的命名区分大小写，其余特征同C和Python
    */
    int A, a; //至少和short一样长，通常情况下自然长度（int）是计算机处理效率最高的长度
    short b; //至少16位，可以用于节省空间
    long c; //至少32位，且至少与int一样长
    long long d; //至少64位，且至少与long一样长
    a = INT_MAX;
    b = SHRT_MAX;
    c = LONG_MAX;
    d = LLONG_MAX;

    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "short is " << sizeof(short) << " bytes" << endl;
    cout << "long is " << sizeof(long) << " bytes" << endl;
    cout << "long long is " << sizeof(long long) << " bytes" << endl;

    cout << "Max Value is:" << endl;
    cout << "int: " << a << endl;
    cout << "short: " << b << endl;
    cout << "long: " << c << endl;
    cout << "long long: " << d << endl;

    cout << "Min int Value is：" << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

    // 无符号整型，可以增大变量能够存储的最大值;
    // unsigned int 等同于 unsigned
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << "sam is short and sam has " << sam << endl;
    cout << "sue is unsigned short and sue has " << sue << endl;
    sam += 1; // sam已经达到上界，再加一导致溢出
    sue += 1; // sue远未达到上界，可以正常加一
    cout << "Add 1" << endl;
    cout << "sam is short and sam has " << sam << endl;
    cout << "sue is unsigned short and sue has " << sue << endl;
    sam = 0;
    sue = 0;
    sam -= 1; // sam是有符号数，0减1没有问题
    sue -= 1; // sue是无符号数，减1之后会向下溢出，再到上界处
    cout << "De 1" << endl;
    cout << "sam is short and sam has " << sam << endl;
    cout << "sue is unsigned short and sue has " << sue << endl;

    int chest = 42; //非0开头，表示十进制
    int waist = 0x42; //0x或者0X开头表示16进制
    int inseam = 042; // 0加上非0数字表示8进制
    cout << "chest waist inseam: " << chest << " " << waist << " " << inseam << endl;
    cout << "chest " << chest << endl;
    cout << hex << "waist " << waist << endl;
    cout << oct << "inseam " << inseam << endl;

    chest = 42;
    waist = 42;
    inseam = 42;
    cout << "chest waist inseam: " << chest << " " << waist << " " << inseam << endl;
    cout << "chest " << chest << endl;
    cout << hex << "waist " << waist << endl; // hex表示cout修改显示方式为16进制
    cout << oct << "inseam " << inseam << endl; // oct表示cout修改显示方式为8进制

    char ch = 'A';
    int i = ch; // 将A的assic码给i
    cout << "The ASSIC of " << ch << " is " << i << endl;
    ch += 1;
    i = ch;
    cout << "The ASSIC of " << ch << " is " << i << endl;
    cout << "Using cout.put ";
    cout.put(ch); //cout的成员函数put，用于输出字符

    cout << "$" <<endl;

    const int tos = 1; //const常量初始化之后，就不能再被修改，const优于define，因为const可以确定变量的类型
    //tos = 2; 错误，因为tos是只读变量
    cout << tos;

    float tub = 10e4; //指数型表示，不能打空格，e4表示10的四次方
    float minb = 10e-4; //e-4表示10的负四次方
    cout << tub << " " << minb <<endl;

    //算数运算部分
    cout << 17 / 3 << endl; //两个整数，则结果为整数
    cout << 17 / 3.0 << endl; //有一个为浮点数，则结果为浮点数

    cout << 17 % 2 << endl; //取余

    char s1 = 'Q';
    char s2 = 'W';
    int s11 = int (s1); //强制类型转换
    cout << s11 <<endl;
    int s22 = (int) s2; //强制类型转换的两种方式
    cout << s22 <<endl;
    auto x = 0.0; //auto关键字让编译器能够根据初始值的类型定义变量的类型。编译器会把变量类型设置为和初始值相同。
    cout << typeid(x).name() <<endl;

}