#include <iostream>
#include <cstring>
using namespace std;

struct inflatable
{
    /* 结构体 
    定义在函数之外成为外部声明，声明在函数内部即为内部声明
    内部声明只能函数自己使用，但外部声明都可以。
    对于结构体提倡外部声明，对于变量提倡内部声明。
    */
    char name[20];
    float volume;
    double price;
};

union id
{
    /* 共用体
    共用体中声明了多种成员变量，但是声明对象时，只能使用其中一个    
    */
    int int_age;
    long long_age;
    double double_age;
};

enum spectrum
{
    /*
    枚举量，可以直接使用其中定义的符号常量。
    在默认情况下，整数值按顺序从0开始赋值给符号常量
    也可以使用：
    red = 2,
    orange = 100,
    yellow = 1
    */
    red,
    orange,
    yellow
};

int main()
{
    inflatable guest = {"Mike", 1.8, 20.3};
    cout << "Name: "<< guest.name << " Volume: " << guest.volume << " Price: " << guest.price << endl;

    inflatable duck {"Duck", 1.2, 23}; //支持列表初始化。但是不允许缩窄转换。

    inflatable choct;
    choct = duck; //使用成员赋值，就算时结构体中有数组也可以
    char a[] = "Cat";
	strcpy(choct.name, a);
    cout << "Name: "<< duck.name << " Volume: " << duck.volume << " Price: " << duck.price << endl;
    cout << "Name: "<< choct.name << " Volume: " << choct.volume << " Price: " << choct.price << endl;

    /*
    其他初始化方法
    struct inflatable
    {
        char name[20];
        float volume;
        double price;
    }mr, ms;
    在末尾声明了两个变量。
    
    struct inflatable
    {
        char name[20];
        float volume;
        double price;
    }mr = {"Mike", 1.8, 20.3};
    声明的同时进行初始化

    struct
    {
        char name[20];
        float volume;
        double price;
    }mr = {"Mike", 1.8, 20.3};
    声明没有名称的结构体，只是定义一个这种类型的变量
    */

    inflatable gifts[2] =   //结构数组，其中每个成员都是一个结构体
        {
            {"Bam", 2.4, 43.4},
            {"Adm", 34.5, 45.2}
        };

    id me;
    me.int_age = 14;
    cout << "Int: " << me.int_age << " Long: "<< me.long_age <<endl;
    me.long_age = 144;
    cout << "Int: " << me.int_age << " Long: "<< me.long_age <<endl;

    spectrum band;
    band = orange;
    cout << band;

}
