#ifndef TIME_H_
#define TIME_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const; //把类成员函数声明为const 以表明它们不修改类对象
    void Show() const;
    Time & set(Time t);
};
#endif