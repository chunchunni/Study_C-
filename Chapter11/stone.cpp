// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    Stonewt pop;
    pop = 3;
    /*
        pop = 3;
        调用构造函数，其实是生成了一个值为3的对象，将对象赋值给pop
        也可以用 pop = (3,4);
    
    
    */
    double p_wt = poppins;
    /*
        强制类型转换。
        当将类对象转化为类型时，系统检测是否有转换函数，没有则会报错。
        其实相当于是对类型进行了重载。
        注意：
            转换函数必须是类方法，不能指定返回类型，不能有参数
    */

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
	// std::cin.get();
    return 0; 
}
