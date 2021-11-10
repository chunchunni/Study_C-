// write.cpp -- using cout.write()
#include <iostream>
#include <cstring>  // or else string.h

int main()
{
    using std::cout;
    using std::endl;
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";
    int len = std::strlen(state2);
    cout << "Increasing loop index:\n";
    int i;
    for (i = 1; i <= len; i++)
    {
        // write()的第一个参数提供要显示的字符串的地址，第二个参数指出要显示多少个字符
        cout.write(state2,i);
        cout << endl;
    }

    cout << "Decreasing loop index:\n";
    for (i = len; i > 0; i--)
        cout.write(state2,i) << endl;

    cout << "Exceeding string length:\n";
    // cout调用返回的是cout对象，即返回的还是输出流对象
    cout.write(state2, len + 5) << endl;
    
    return 0; 
}
