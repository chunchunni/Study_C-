// setf.cpp -- using setf() to control formatting
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;

    cout << "Today's water temperature: ";
    // showpos表示在正数前加上+号
    cout.setf(ios_base::showpos);    // show plus sign
    cout << temperature << endl;

    cout << "For our programming friends, that's\n";
    cout << std::hex << temperature << endl; // use hex
    // uppercase表示使用16进制输出，使用大写字母E表示
    cout.setf(ios_base::uppercase);  // use uppercase in hex
    // 对于输出，使用c++基数前缀
    cout.setf(ios_base::showbase);   // use 0X prefix for hex
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "!  oops -- How ";
    cout.setf(ios_base::boolalpha);
    cout << true << "!\n";
	// std::cin.get();
    return 0; 
}
