// funadap.cpp -- using function adapters
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void Show(double);
const int LIM = 6;
using namespace std;

int main()
{
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;

    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);
    /*
        transform函数的作用是：将某操作应用于指定范围的每个元素。transform函数有两个重载版本：
        transform(first,last,result,op);
        //first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。

        transform(first1,last1,first2,result,binary_op);
        //first1是第一个容器的首迭代器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，result为存放结果的容器，binary_op为要进行操作的二元函数对象或sturct、class。
        //二元操作先不管

        注意：第二个重载版本必须要保证两个容器的元素个数相等才行，否则会抛出异常。
    */
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    
    /*
        bind1st(multiplies<double>(), 2.5)
        STL提供函数bind1st，用来简化binder1st类的使用，可以问其提供用于构建binder1st类对象的函数名称和值，他将返回一个此类对象
        是指将二元函数multiplies()转化为一个将参数乘以2.5的一元函数
    */    
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;
    
    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}
