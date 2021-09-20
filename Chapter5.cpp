#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int i;
    for (i = 0; i < 5; i++) //如果在括号中声明i，则函数的剩下部分不能使用i这个变量
    {
        cout << i << endl;
    }

    string word111 = "word"; //字符串可以按位访问
    for (i = word111.size() - 1; i >=0; i--)
    {
        cout << word111[i] <<endl;
    }

    double arr[5] = {11.1,22.2,33.3,44.4,55.5};
    auto pt = arr;        //auto会自动根据赋值的类型给pt赋上指针类型
    cout << *pt << endl;
    ++pt;                 //pt指向arr[1]的地址
    cout << *pt << endl;
    double x;
    x = (*pt)++;          //先取pt的值赋给x，然后将值加一，pt本身不移动
    cout << x << endl;
    x = ++*pt;            //上面操作导致*pt为23.2，此处取得pt的值然后加一再赋给x，pt本身不移动
    cout << x << endl;
    x = *pt++;            //++优先级高于*，所以pt先取作为指针传给*pt求得值给x，pt再向下移动一位              
    cout << x << endl;
    cout << *pt << endl;

    char word[] = "word";
    string s = "word";

    cout << strcmp(word, "word") << endl; //字符数组比较必须使用库函数，不相等时返回非零值，并不一定非负
    cout << strcmp(word, "wora") << endl;
    cout << (s == "word") << endl;  //string类可以直接使用==符合判断
    cout << (s == "word1") << endl;

    double prices[5] = {1.1,2.2,3.3,4.4,5.5};

    for (double x: prices)  //基于范围的循环，对数组或容器类的每个元素执行相同操作
    {   
        x += 1;
        cout << x << endl; 
    }

    for (double &x: prices) //&x是引用变量，他让接下来对x的操作会影响原来的数据，而上一种语法不可以
    {   
        x += 1;
        cout << x << endl; 
    }

    for (double x: prices) //值被修改了
        cout << x << endl;

    char ch;
    int count = 0;

    cout << "Enter '#' to quit:" << endl;
    cin >> ch;
    while (ch != '#')
    {
        cout << ch;
        cin >> ch;      //忽略换行和空格，多余的输入会被放入到缓冲区中
        count ++;
    }
    cout << endl << count << endl;

    count = 0;
    cout << "Enter '#' to quit:" << endl;
    cin.get(ch);
    while (ch != '#')
    {
        cout << ch;
        cin.get(ch);    //全部字符计算在内，包括空格 换行
        count ++;
    }
    cout << endl << count << endl;

    while (cin.get(ch))
        cout << ch;

    char cities1[5][20] =       //字符数组的数组
    {
        "Gribble City",
        "Gribbletown",
        "New York"
    };

    string cities2[5] =         //对象数组
    {
        "San Fronsico",
        "Washton",
        "Beijing"
    };    
}