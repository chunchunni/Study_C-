#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);

    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    // 将单词不分大小写按照字母顺序排序
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string> > (wordset, wordset.begin()), ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    // 计算单词出现频率
    map<string, int> wordmap;
    set<string>::iterator si;
    for (si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);

    // 展示频率
    cout << "\nWord frequency:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << endl;
    
    vector<int> a{1,2,3,4,5,6,7,8,9,10}, b(10), c(10);
    for (int i=0; i < c.size(); i++)
    {
        c[i] = a[i] + b[i];
        printf("%d", c[i]);
    }
    // 与上面的遍历是同样的效果
    transform(a.begin(), a.end(), b.begin(), c.begin(), plus<int>());
    
    return 0;
}

string & ToLower(string & st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st; 
}

void display(const string & s)
{
    cout << s << " ";
}
