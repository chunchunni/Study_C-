// strgstl.cpp -- applying the STL to a string
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    using namespace std;
    string letters;

    cout << "Enter the letter grouping (quit to quit): ";
    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        // string虽然不是STL的组成部分，但是也包含begin，end，rbegin，rend成员，因此可以使用这些接口
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        // next_permutation将区间的内容转化为下一种排列方式，会自动去重
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;
        cout << "Enter next sequence (quit to quit): ";
    }
    cout << "Done.\n";
    return 0;
}
