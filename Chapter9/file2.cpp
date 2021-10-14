#include <iostream>
#include <cmath>
#include "coordin.h"

using namespace std;

polar rect_to_polar(rect xypos)
{
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.x, xypos.y);
    return answer;
}

void showPolar(polar dapos)
{
    cout << "Distance = " << dapos.distance << endl;
    cout << "Angle = " << dapos.angle * 57.29 << endl;
}