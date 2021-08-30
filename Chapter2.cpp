#include <iostream> // C++头文件无扩展名，但兼容C的.h后缀
#include <cmath> // 老版为math.h

using namespace std; // 将编译指令放在所有函数前，可以使它们共享名称空间

void simon(int); // 函数头，声明函数

int main() // 括号为空等同于不接受任何参数(void)
{
    /*
    using编译指令。程序可以使用命名空间来区分不同的版本，
    属于C++特性，有助于组织程序，可以便于开发人员将产品封装在一个空间中，使用名称空间的名称区分不同版本
    按照这种方式，类、函数、变量都是一个空间中的标准组件，现状都被放入std的空间之中
    using意思是可以使用std空间中的组件名称而不必带上std::前缀
    */
    using namespace std; 
    cout << "Hello World!"; // cout是预定义对象，知道如何显示传给他的输出流
    cout << endl; // endl表示重起一行；cout的输出是接着前一个输出的末端
    cout << "What is next?\n";

    int a,b,c;
    a = b = c = 8; // 从右到左依次赋值
    cout << a; // cout可以根据后面的数据类型进行运算符重载，而并不需要你指定数据类型
    cout << "\n";
    cout << "How many money you have?";
    //cin >> a; // 数据流向a，a用于接收cin对象抽取的信息
    cout << "You have " << a << " money" << endl;

    cout << "This is "
         << "a "
         << "long data"
         << endl; // 拼接版本

    double x;
    x = sqrt(6.25);
    cout << x <<endl;

    simon(3000);

    return 0; // 隐含返回语句，只适用于main函数。0可以返回给操作系统，0意味着测试成功，非0意味着出现问题
}

void simon(int n)
{
    using namespace std;
    cout << "Love you " << n << " times" << endl;
}