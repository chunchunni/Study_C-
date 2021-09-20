#include <iostream>
#include <cctype>
#include <fstream> //由于文件输出

using namespace std;

enum {red, orange, blue};

int main()
{
    char ch = '.';
    cout << ch + 1;
    
    int i =5;
    
    // C++中的and，or，not可以取代逻辑标识符来使用
    if (i > 1 && i < 10) //不能使用 1 < i < 10，因为这个等价于(1 < i) < 10, 小括号是逻辑表达式的值
        cout << i <<endl;
    
    /*
    cctype是一个关于字符判断的软件包，其中isalpha(ch)用来判断ch是否是一个字符，是则返回非零值，否则返回0
    ispunct(ch)用来判断ch是否是一个标点符号，例如逗号句号。
    isdigits(ch)用来判断ch是否是数字
    isspace判断是否为空白字符，例如空格、换行、制表
    
    if ((ch >= 'a' && ch <= 'z) || (ch >= 'A' && ch <= 'Z))
    等价于
    if (isalpha(ch))
    */

    int b = 2, c = 3;
    int a = b > c ? b : c; //条件运算符?:，当?前面的条件成立则选择:左边的值作为表达式的值，否则选:右边的值
    
    int key = 1;
    switch (key)
    {
        case red:           //使用枚举量作为标签
            cout << red <<endl;
            break;
        case orange:
            cout << orange <<endl;
            break;
        case blue:
            cout << blue <<endl;
            break;
        default:
            break;
    }

    char choice = 'q';
    switch (choice)
    {
    case 'a':                           //标签case的值必须是整数常量表达式
    case 'A':                           //case并不是选项之间的界限，当choice跳转到符合条件的case之后，
        cout << "This is a/A" << endl;  //会执行包括后续case在内的所有代码,而break的作用才是停止执行
        break;
    case 'b':
    case 'B':                           //因此b和B才会有一样的输出内容
        cout << "This is b/B" << endl;
        break;
    case 'c':
    case 'C':
        cout << "This is c/C" << endl;
        break;
    default:
        break;
    }


    /*
    输入输出：
        对于输入行38.5
        
        char ch;
        cin >> ch;
        //ch只能得到第一个字符3，后面的不会传入ch
        
        int n;
        cin >> n;
        //这种情况下cin会不断读取，直到遇到非数字字符，即读取3和8，句点会称为输出队列的下一个字符
        //cin通过计算发现3和8组成了38，将38给n
        
        double x;
        cin >> x;
        //cin会不断读取，直到遇到非浮点数的字符，即38.5都会给x

        char word[50];
        cin >> word;
        //cin会不断读取，直到遇到空白字符。即3 8 . 5四个字符存在数组word中，并再末尾添加空字符。
    
        char word[50];
        cin.getline(word,50);
        //cin会不断读取，直到遇到换行字符（示例输入少于50）.所有字符会被存在word中，而且末尾加上空字符。
    */

    ofstream outFile;
    outFile.open("Test.txt"); //没有这个文件则新建一个；有这个文件则完全覆盖其中的内容。
    outFile << "BBBBB" << endl; //表示将字符写入到文件中
    outFile.close(); //使用完文件需要关闭

    ifstream inFile;
    inFile.open("Test.txt"); //没有这个文件，打开失败，并不会报错
    // inFile.isopen() 判断文件打开是否成功
    double x = 0, sum = 0;
    int count = 0;
    while (inFile.good()) //有输入且不为空
    {
        count++;
        sum += x;
        inFile >> x;
    }
    cout << sum << " " << count << endl;
}