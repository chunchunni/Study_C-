#include <iostream>
#include "stock.h"

int main()
{
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);            // 构造函数
    stock1.show();
    Stock stock2 = Stock ("Boffo Objects", 2, 2.0); // 调用构造函数
    stock2.show();
    Stock stock3 = {"Boffo3 Objects", 2, 2.0}; // 调用构造函数
    stock3.show();
    Stock stock4; // 调用隐式构造函数
    stock4.show();

    Stock stocks[4] = {     //生成对象数组
        Stock("NanoSmart", 12, 20.0),   //调用构造函数
        Stock(),    //调用隐式默认构造函数
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    /*
    Stock stock2 = Stock ("Boffo Objects", 2, 2.0); 
    与
    Stock stock2;
    stock2 = Stock ("Boffo Objects", 2, 2.0);
    有本质差别，前一个是初始化，创建有指定值的对象，可能会创建临时对象
    第二个是赋值语句，使用构造函数会导致在赋值前创建一个临时对象
    */

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);    // 调用构造函数创建临时对象，再将该对象复制给stock1，然后调用析构函数删除临时对象
    cout << "Revised stock1:\n";
    stock1.show();

    Stock top;
    top = stock1.topval(stock2); //this指针指向调用成员函数的stock1
    top.show();

    cout << "Done\n";
    return 0; 
}