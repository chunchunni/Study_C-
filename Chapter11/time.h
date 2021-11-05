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

    Time operator*(double n) const; //操作符重载
    friend Time operator*(double m, const Time & t) { return t * m; }   //友元函数
    friend std::ostream & operator<<(std::ostream & os, const Time & t);   //重载运算符，返回对象的引用
    /*
        友元函数：
            友元函数不是类的成员函数，虽然在类中进行了声明，因此不能使用成员运算符来调用
            通过使用关键字friend，使得函数拥有与类的成员函数相同的访问权限。
    */
};
#endif