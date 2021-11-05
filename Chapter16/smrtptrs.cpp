// smrtptrs.cpp -- using three kinds of smart pointers
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;

public:
    Report(const std::string s) : str(s) { std::cout << "Object created!\n"; }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main()
{
    {
        //std::auto_ptr<Report> ps (new Report("using auto_ptr"));  新版C11已经将该方法取消
        //ps->comment();   // use -> to invoke a member function
    } 
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr")); //智能指针，在使用后自动销毁
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    // std::cin.get();
    return 0;
}
