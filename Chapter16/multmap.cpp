#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

/*
     multimap是可反转的、经过排序的关联容器，但键和值的类型不同
     
     multimap<KeyType, std::string> MapCode; 
     是指声明一个键为KeyType类型、值为string类型的multimap对象

     pair<const KeyType, std::string> Pair;
     STL使用模板类pair<class T, class U>将一个键值对存储到一个对象中

*/

int main()
{
     using namespace std;
     MapCode codes;

     //创建一个pair对象，并插入到容器中
     std::pair<const int, string> item(213, "Los Angeles");
     codes.insert(item);

     //将Pair重定义之后可以简化代码
     codes.insert(Pair(415, "San Francisco"));
     codes.insert(Pair(510, "Oakland"));
     codes.insert(Pair(718, "Brooklyn"));
     codes.insert(Pair(718, "Staten Island"));
     codes.insert(Pair(415, "San Rafael"));
     codes.insert(Pair(510, "Berkeley"));

     //count成员函数接受键为参数，返回具有该键的元素数目
     cout << "Number of cities with area code 415: "
          << codes.count(415) << endl;
     cout << "Number of cities with area code 718: "
          << codes.count(718) << endl;
     cout << "Number of cities with area code 510: "
          << codes.count(510) << endl;
     cout << "Area Code\tCity\n";
     MapCode::iterator it;
     //对于pair对象，可以使用first和second成员访问他的两个部分
     for (it = codes.begin(); it != codes.end(); ++it)
          cout << (*it).first << "\t"
               << (*it).second << endl;

     //equal_range使用键作为参数，返回两个迭代器，他们表示的区间与该键匹配
     pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
     cout << "Cities with area code 718:\n";
     for (it = range.first; it != range.second; ++it)
          cout << (*it).second << endl;

     /*
          出错，因为codes.begin()返回的是pair类型的迭代器，无法和out的类型匹配
          ostream_iterator<string, char> out(cout, " ");
          copy(codes.begin(), codes.end(), out);

          copy(codes.rbegin(), codes.rend(), out);
     */
    
     return 0;
}
