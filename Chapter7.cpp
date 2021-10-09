#include <iostream>
#include <array>

using namespace std;

void cheers(int); //函数原型，只需要提供参数的类型列表，变量名并不需要
int sum(int [], int);

const array<string, 4> Snames = {"Spring", "Summer", "Fall", "Winter"};

void fill(array<double, 4> *pa); //指向对象的指针
void show(array<double, 4>);

void countdown(int);

int countnum(int);
void estimate(int , int (*pt)(int)); //指向函数的指针, 表示该函数参数为int，返回值为int

const double * test_func (const double *, int);

int main()
{
    int n = 5;
    cheers(n); //函数调用

    int a[5] = {1,2,3,4,5};
    cout << sizeof(a) / sizeof(a[0]) << endl;
    cout << sum(a, sizeof(a) / sizeof(a[0])) <<endl; //如果a为const int数组，则传参失败。因为指针的类型和数组的类型必须一致。

    /*
    声明：
    int a = 10;
    int b = 11;
    const int * p = &a;
    此时：
    *p = 5; //不对；禁止修改p指向的的值
    p = &b; //对；可以修改p指向另外一个变量

    声明：
    int a = 10;
    int b = 11;
    int * const p = &a;
    此时：
    *p = 5; //对；可以修改p指向的值
    p = &b; //不对，p不能指向别的变量
    */

    array<double, 4> expenses;
    //fill(&expenses);
    //show(expenses);

    countdown(5); //实现递归操作

    estimate(10, countnum);//使用函数指针时，直接调用函数名，不加参数

    const double * (*p1) (const double *, int); //指针p1指向一个特征标为(const double *, int), 返回类型为const double *的函数
    const double * (*p2) (const double *, int) = test_func; //声明的同时进行初始化
    auto p3 = test_func; //也可以使用自动类型判断功能进行初始化指针

    const double * (*pa[3]) (const double *, int) = {test_func, test_func, test_func};//包含三个函数指针的数组
    //auto只能用于单值初始化，不能用于初始化列表
    auto pb = pa; //但声明同类型数组可以这样，pa和pb其实是指向数组的指针

    const double b= 3.0;
    auto av = &b;
    const double * px = pa[0](av,3); //调用函数
    double x = *pa[0](av,3); //获得函数处理后可以返回的值


}

void cheers(int x) //函数定义，有返回值时返回值的类型必须和函数类型一致。且数组类型不能被直接返回，可以作为结构或对象的部分返回
{
    for(int i = 0; i < x; i++)
        cout << "cheers" << endl;
}

int sum(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

void fill(array<double, 4> *pa)
{
    for(int i=0; i < (*pa).size(); i++)
    {
        cout << "Enter " << Snames[i] << " expenses :";
        cin >> (*pa)[i];
    }

}

void show(array<double, 4> da)
{
    for(int i=0; i <= da.size(); i++)
    {
        cout << Snames[i] << " expenses :" << da[i] << endl;
    }
}

void countdown(int n)
{
    cout << "Counting down ... " << n << endl;
    if (n > 0)
        countdown(n-1);
    cout << n << ": die." <<endl;
}

int countnum(int num)
{
    return int(0.5 * num);
}

void estimate(int num, int (*pt)(int))
{
    cout << num << " estimate by countnum is ";
    cout << (*pt)(num) << "\n";
}