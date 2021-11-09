#include <iostream>
#include <iterator>     //提供一些迭代器类型
#include <vector>

/*
    要访问顺序容器和关联容器中的元素，需要通过“迭代器（iterator）”进行。
    迭代器是一个变量，相当于容器和操纵容器的算法之间的中介。
    迭代器可以指向容器中的某个元素，通过迭代器就可以读写它指向的元素。从这一点上看，迭代器和指针类似。

    不同的容器，它的迭代器不同，但是，他们有共同的目标，就是可以通过该迭代器，来遍历访问这个容器里面的元素。
    这样带来的好处是在STL设计算法时，可以脱离容器而设计更加通用的算法。
*/

int main()
{
    using namespace std;

    int casts[10] = {6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5};
    vector<int> dice(10);
    
    copy(casts, casts + 10, dice.begin()); //表示将casts的0-9的元素复制到dice的开始位置
    cout << "Let the dice be cast!\n";

    //输出流迭代器，<int, char>表示int是发送给输出流的数据类型，char是输出流使用的字符类型，
    //(cout, " ")表示使用的输出流是cout，流中每个数据项的分隔符是" "
    ostream_iterator<int, char> out_iter(cout, " "); 
    
    // out_iter迭代器现在是一个接口，能够让用户使用cout显示信息
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;
    cout <<"Implicit use of reverse iterator.\n";
    
    //采用反向迭代器，反向指针通过先递减再解除引用来反向遍历容器
    //rbegin和end返回相同的值（超尾），但类型不同，前者是反向迭代器
    //rend和begin返回相同的值（指向第一个元素的迭代器），但类型不同
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;
    cout <<"Explicit use of reverse iterator.\n";
    
    // vector<int>::reverse_iterator ri;  // use if auto doesn't work
    for (auto ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;
	// cin.get();
    return 0; 
}
