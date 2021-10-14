#ifndef COOR
#define COOR

/*
    在同一个文件中，只能包含同一个头文件一次，因此如果导入的文件中，重复包含了同一个头文件，则导致出错。
    因此，使用预处理器编译指令#ifndef技术可以避免多次重复包含。

    当没有define指令定义名称COOR时，才会处理ifndef和endif之间的语句
*/

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect );
void showPolar(polar );

#endif
