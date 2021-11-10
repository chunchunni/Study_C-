// inserts.cpp -- copy() and insert iterators
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void output(const std::string & s) {std::cout << s << " ";}

int main()
{
    using namespace std;
    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};
    vector<string> words(4);
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;
 
// back_insert_iterator迭代器只允许在尾部快速插入的容器，此处是此处是直接构建一个匿名迭代器
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

// insert_iterator只允许将元素插入到构造函数指定参数的位置前面
    copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin())); //插到words的最前面
    for_each(words.begin(), words.end(), output);
    cout << endl;
    
    return 0; 
}
