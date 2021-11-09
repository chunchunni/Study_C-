#include <iostream>
#include <string>
#include <vector>

/*
    vector模板类，用于表示一组同类型的值
*/

using namespace std;

struct Review {
    std::string title;
    int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;   //<type>指出要使用的类型，NUM表示要使用多少个矢量
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);  //将元素添加到矢量末尾
    int num = books.size();     //size统计长度
    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
            << "Rating\tBook\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        cout << "Reprising:\n"
            << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)   
        //begin返回一个指向容器第一个元素的迭代器，end返回一个指向超过容器尾的迭代器。迭代器只指针
            ShowReview(*pr);
        vector <Review> oldlist(books);     // copy constructor used
        if (num > 3)
        {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3); //erase删除给定区间的元素。左闭右开
            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            // insert 1 item
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            // insert在指定区间插入元素。上述指把oldlist的第一个元素插入到books的最前面
            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    // std::cin.get();
	return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    /*
        cin.getline(s,50,'\n');
            其中s需要时char *或unsigned char *，50表示读入大小（最大），'\n'表示分隔符，可以省略，默认就是这个
        getline(cin,s)
            s需要是string，需要引入string头文件，std::string空间引入
        cin.getline(s, 长度, 分隔符)
            适合你知道读入大小，固定char数组，速度快
        getline(cin,s)
            不需要指定大小，但速度慢、生成的文件大，适合偷懒用
    */
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl; 
}

