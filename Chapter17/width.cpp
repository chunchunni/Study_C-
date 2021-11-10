// width.cpp -- using the width method
#include <iostream>

int main()
{
    using std::cout;
    int w = cout.width(30);
    // cout.width(30)返回的是之前的字段宽度0
    cout << "default field width = " << w << ":\n";

    // width方法将长度不同的数字放到宽度相同的字段中，将字段宽度设置为5个空格
    // 只作用于紧邻的一次cout输出控制，其后的就恢复默认了
    cout.width(5);
    cout << "N" <<':';
    cout.width(8);
    cout << "N * N" << ":\n";

    for (long i = 1; i <= 100; i *= 10)
    {
        cout.width(5);
        cout << i <<':';
        cout.width(8);
        cout << i * i << ":\n";
    }
    
    // 默认情况下cout使用空格填充字段中未被使用的部分，可以用fill成员函数来改变填充的字符
    // 与设置宽度不同的是，新的填充字符始终有效
    cout.fill('*');
    const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper"};
    long bonus[2] = {900, 1350};

    for (int i = 0; i < 2; i++)
    {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }
    
    return 0; 
}
