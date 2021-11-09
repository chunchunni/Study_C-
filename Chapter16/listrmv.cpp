#include <iostream>
#include <list>
#include <algorithm>

void Show(int);
const int LIM = 10;
int main()
{
    using namespace std;
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> la(ar, ar + LIM);
    list<int> lb(la);
    
    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    //remove方法可以删除所有值为4的节点，而且会自动修改链表长度
    la.remove(4);
    cout << "After using the remove() method:\n";
    cout << "la:\t";    
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    list<int>::iterator last;
    // 此处的remove是STL算法，不是由对象调用，而是接受区间参数
    // 由于remove不是成员函数，因此不能调整链表的长度，他将没被删除的元素放在链表的开始位置，并返回一个指向新的超尾值的迭代器
    // 这里的remove函数将非4的值重新拿出来放在list的最前面，而且返回的last指向这个非4部分的最后面
    // 然后last到lb.end()的部分就都是应该被舍弃的
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";    
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    //erase删除给定区间的元素。左闭右开
    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";    
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    return 0;
}

void Show(int v)
{
    std::cout << v << ' ';
}
