#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

/*
    vector, list这些指的是序列容器
    而 map， set这些指的是关联容器

    set 关联集合，键唯一(键值对)
    multiset
    map
    multimap

*/

int main()
{
    using namespace std;
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out); //会自动排除重复的键，而且会排序
    cout << endl;
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out); //将两个集合选定区间内的键值进行求集合，并输出给最后一个迭代器参数
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); //求交集
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out); //求两个集合的差
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    //求两个集合的区间之后，再复制给另一个容器
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    //lower_bound指向集合中第一个不小于键参数的成员，upper_bound指向第一个大于该键的成员
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;

    return 0;
}
