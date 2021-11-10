#include <iostream>
int main()
{
    using namespace std;
    int n = 20;

    cout << "n     n*n\n";
    cout << n << "     " << n * n << " (decimal)\n";
// 使用hex控制整数以16进制输出
    cout << hex;
    cout << n << "     ";
    cout << n * n << " (hexadecimal)\n";

// 使用oct控制整数以8进制输出
    cout << oct << n << "     " << n * n << " (octal)\n";

// 使用dec控制整数以10进制输出
    dec(cout);
    cout << n << "     " << n * n << " (decimal)\n";

    return 0; 
}
