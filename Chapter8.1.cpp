#include <iostream>
#include <string>

using namespace std;

inline double square(double x) //内联函数
{
    return x * x;
}

#define SQUARE(x) x*x

/*
    内联函数：
        内联函数的编写与普通函数一致，但调用时其实是将代码复制到了使用的地方。
        这样做提高了运行速度，但消耗了更多内存空间。
    内联函数无法递归，不能调用自己。
    当函数过大时，编译器可能不会满足内联的要求。

    宏定义：
        宏定义其实是文本替换，x只是参数的符号标记
    eg:
        a = SQUARE(5.0) //a = 5.0 * 5.0
        b = SQUARE(4 + 5) //b = 4 + 5 * 4 + 5
        c = SQUARE(c++) //c = c++*c++

*/

void swapr(int &, int &); //按引用传值
void swapp(int *, int *); //按指针传值
void swapv(int, int); //传入形参

struct tree
{
    string name;
    int height;
};

tree & accunumlaye(tree &, const tree &); //指向结构的引用
void display(const tree &);

int main()
{
    double a = 5, b;
    cout << square(a) <<endl;
    b = SQUARE(a++);
    cout << b <<endl;
    cout << a <<endl;

    int rats = 100;
    int & rodents = rats; //&用于声明
    cout << "rats = " << rats << " address = " << &rats << endl; //&用于取地址
    cout << "rodents = " << rodents << " address = " << &rodents << endl;
    /*
        引用变量：
            使用&声明一个指向同一个变量的引用。
            此处的rondents和rats对程序来说，就是一个int型变量的两个名字，修改其中任一个的值都有影响另一个。
        引用变量不同于指针。
            指针可以声明，再赋值。但引用变量必须在创建时就进行初始化，这一点与const型变量类似。
            int & rodents = rats;
            int * pr = &rats;
            rodent和*pr作用相同

        当数据对象很大时，优先使用引用。
        当数据对象是数组时，只能使用指针。
        当数据对象是类对象时，只能使用引用。
    */
    int x = 1, y = 2;
    cout << "x = " << x << " y = " << y << endl;
    swapr(x , y); //传引用等价于对原变量的操作
    cout << "Swappv: " << "x = " << x << " y = " << y << endl;
    x = 1, y = 2; //传指针等价于对原变量地址的操作
    swapp(&x , &y);
    cout << "Swappp: " << "x = " << x << " y = " << y << endl;

    x = 1, y = 2;
    swapv(x , y); //只传入值时，并没有对原来的值进行处理
    cout << "Swappv: " << "x = " << x << " y = " << y << endl;

    tree tree_a = {"TreeA", 10}, tree_b = {"TreeB", 15};
    display(tree_a);
    display(tree_b);

    accunumlaye(tree_a, tree_b); //对结构体的引用
    display(tree_a);
    display(accunumlaye(tree_a, tree_b)); //对函数的引用，直接对函数的返回值做了引用，指向同一个地址

    /*
        tree result;
        result = accunumlaye(a, b);
        
        //报错。原因在于accunumlaye中的返回变量c是一个局部变量，局部变量在其中运行时不会有问题，但函数运行之后就会被释放
        //将已经释放的数据赋值给result时，就会报错。

        const tree & accunumlaye(tree & a, const tree & b)
        {
            tree c
            c.name = a.name + b.name;
            c.height =  a.height + b.height;
            return c;
        }
    */


}

void swapr(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

tree & accunumlaye(tree & a, const tree & b)
{
    a.name += b.name;
    a.height += b.height;
    return a;
}

void display(const tree & ft)
{
    cout << "Name: " << ft.name << endl;
    cout << "Height: " << ft.height << endl;
}