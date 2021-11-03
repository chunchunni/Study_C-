#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>  

class Stock  // class declaration
{
private: //类的数据成员默认为private，表示只能通过公共成员访问类成员
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; } //类成员可以是数据类型，也可以是函数
public: //public标志公共接口的类成员
    Stock();        // 默认构造函数
    Stock(const std::string & co, long n = 0, double pr = 0.0); //显示构造函数
    ~Stock();       // 析构函数，由于销毁对象，释放内存
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    const Stock & topval(const Stock & s) const;
};    // note semicolon at the end

#endif

/*
    定义（实现）位于类声明中的函数都是内联函数，
    如void set_tot() { total_val = shares * share_val; }
    也可以写成：
    class Stock  
    {
    private: 
        void set_tot() { total_val = shares * share_val; } 
    };   

    inline void Stock::set_tot()
    {
        total_val = shares * share_val;
    }
    inline关键字表示内联函数

*/