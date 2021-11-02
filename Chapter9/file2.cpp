#include <iostream>
#include <cmath>
#include "coordin.h"

using namespace std;

extern int file_global; //声明外部变量，且此时不可以进行赋值操作

polar rect_to_polar(rect xypos)
{
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.x, xypos.y);
    file_global = 50; //使用外部变量
    cout << "使用外部变量file_global: " << file_global <<endl;
    return answer;
}

void showPolar(polar dapos)
{
    cout << "Distance = " << dapos.distance << endl;
    cout << "Angle = " << dapos.angle * 57.29 << endl;
}