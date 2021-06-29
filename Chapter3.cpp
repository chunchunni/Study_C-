#include <iostream>
#include <climits> //定义符号常量
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
    cout.put(ch);




}