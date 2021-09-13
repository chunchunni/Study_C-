#include <iostream>
#include <string>
/*
    string类型变量可以用来替代数组存储字符串，使用更简单
*/
#include <cstring>

using namespace std;

int main()
{
    string str1;
    /*
    string和数组的区别在于可以将对象声明为简单变量
    而且string对象可以根据输入动态调整大小，因此使用起来比数组更安全    
    */
    cin >> str1; // string的输入和数组一致
    cout << "This is a string: " << str1 << endl;
    cout << "The str1[2] is : " << str1[2] << endl; //string的访问和数组也一致，可以访问下标

    string str2 = "hi!";
    string str3;
    str3 = str1 + str2; //字符串赋值、拼接
    str1 += str2;
    cout << "s3: " << str3 << endl;
    cout << "s1: " << str1 << endl;
    
    char charstr1[20];
    char charstr2[20] = "hi !";

    strcpy(charstr1, "mike"); //字符数组和字符数组不能直接互相赋值，只能依靠函数来实现
    strcat(charstr1, charstr2); //字符数组拼接，将str2拼接到str1后面
    /*
    strcpy和strcat的共同问题时可能导致复制时，数组内存不够溢出到临近的内存单元，这样会导致程序异常终止
    解决方法：
    strncat和strncpy，这两个操作的函数只会接受目标数组所允许的最大长度，但是会增加程序复杂性。
    */
    cout << charstr1;
    
    int len1 = str1.size(); //两种求字符串长度的方法,size时string类中的方法，string对象可以直接调用
    int len2 = strlen(charstr1); //strlen是用来对字符数组求长度

    char charr[20];
    string str;

    /*
    charr初始化数组时，内部空间的内容并没有被定义，因此输出的长度并不确定。
    未初始化的数据，空字符可能出现在任意位置
    而未初始化的str对象直接被设置为0
    */
    cout << "Length of charr: "
         << strlen(charr) << endl;
    cout << "Length of str: "
         << str.size() << endl;

    cin.getline(charr, 20); //getline作为cin类方法
    cout << "You enter the " << charr << endl;

    getline(cin, str); //此处的getline不是作为类方法，而是将cin作为参数
    cout << "You enter the " << str << endl;

    //其他形式的字符串类型
    wchar_t title[] = L"ssssss"; //前缀L
    char16_t name[] = u"aaaaaa"; //前缀u
    char32_t car[] = U"bbbbbb"; //前缀U

    /*
    原始字符串 R"(字符串内容)"
    在()括号内的所有内容都会保留为字符串的内容，例如\n就会分别保留为\和n，就连换行符都会保留

    如果要在字符串中包含()，则需要：
    R"+*(字符串内容)+*" ，此时定界符就不是之前的"(而是"+*(
    */
    cout << R"( This is a row string. This is \n  )" << endl;
    cout << R"+*( This is a row string. This is \n and () )+*" << endl;

}
