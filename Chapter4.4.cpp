#include <iostream>
#include <cstring>
using namespace std;

struct things
{
    int good;
    int bad;
};




int main()
{
    int opps = 5;
    cout << "Num: " << opps << " Address: " << &opps <<endl;

    /*
    面向对象基本原理：
        面向对象强调在运行阶段而不是编译阶段进行决策。运行阶段是程序正在运行时，编译阶段是编译器将程序组织起来时。
        运行阶段决策可以提供更好的灵活性，例如申请一个数组时，数组的空间大小可以动态的根据需求决定。

    对于常规变量opps，值是指定的量，地址为派生量，使用取地址符&可以获得间接量
    对于指针变量popps，地址是指定的量，值是派生量，因此指针名是地址，使用*运算符称为间接值运算符或解除引用运算符
    两者相当于硬币之两面，在使用上是等价的

    指针在定义时，在*运算之前进行恰当的初始化。
    因为未定义指向地址的指针可能指向任意位置，当指向一个程序段时，在对*操作赋值会导致难以跟踪的bug。
    指针作用是在运行阶段动态分配未命名的内存空间以存储值。

    普通变量和指针的值都存在栈的内存区域中，而new运算符存放在堆或自由存储区。
    */
    
    int * popps; //指针的类型要和值相匹配，可以是popps是指针，而*popps是int型的值
    //*两边的空格可选，但是申请多个指针必须都加上*：int * p, p2;是指一个指针p和一个int值p2
    //指针变量不仅仅是指针，而且是指向特定类型的指针
    popps = &opps;
    cout << "Num: " << popps << " Address: " << *popps <<endl;

    int * pn = new int; //new int表示需要存储int的内存，new根据变量类型来分配内存，然后把地址给pn。内存不够或者分配失败时，new返回空指针。
    *pn = 100;
    cout << *pn << endl;

    delete pn; //delet释放内存

    double * p3 = new double [3]; //使用new运算符动态分配数组
    p3[0] = 0;  //C和C++都使用指针来处理数组，因此指针和数组的应用也基本等价
    p3[1] = 1;
    p3[2] = 2;
    cout << "p3[1]: " << p3[1] << endl; //访问第二个值

    p3 += 1; //指针和数组的根本差别，指针是变量，可以修改他的值，此时p3[0]指向的是之前的第二个值。也即是p3数组整体向后移动了。
    cout << "p3[0]: " << p3[0] << endl;
    cout << "p3[1]: " << p3[1] << endl;
    cout << "p3[2]: " << p3[2] << endl;

    p3 -= 1; //指针减一，指向原来的位置
    cout << "p3[0]: " << p3[0] << endl;
    cout << "p3[1]: " << p3[1] << endl;
    cout << "p3[2]: " << p3[2] << endl;

    delete [] p3; //对于动态数组的回收，也需要加上[]

    int size = 5;
    //cin >> size;    //可以动态调整数组的大小
    int* pz = new int [size];
    *pz = 5;
    cout << pz[1] << endl;    
    
    char animal[20] = "bear";
    const char * bird = "wren";
    char *ps;

    cout << "Before:" << endl;
    cout << animal << " and " << bird <<endl;
    cout << (int *) animal << " and " << (int *) bird <<endl;

    strcpy(animal, "fox");
    ps = animal;

    cout << "After:" << endl;
    cout << animal << " and " << ps <<endl;
    cout << (int *) animal << " and " << (int *) ps <<endl;

    ps = new char[strlen(animal) + 1]; //重新申请一个空间用来存储animal的值, 深拷贝
    strcpy(ps, animal);

    cout << "Final:" << endl;
    cout << animal << " and " << ps <<endl;
    cout << (int *) animal << " and " << (int *) ps <<endl;

    things grubnose = {1,2};
    things * pss = & grubnose; //申请结构体指针
    cout << grubnose.bad << " " << grubnose.good << endl; //结构体变量访问成员变量用“.”
    cout << pss -> bad << " " << pss -> good << endl; //结构体指针访问成员变量用“->”
    cout << (*pss).bad << " " << (*pss).good << endl; //*pss是被指向的值本身，即结构本身，故使用“.”来访问

}