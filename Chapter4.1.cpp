#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int nums[2];    //声明数组
	nums[0] = 1;    //单个赋值
	nums[1] = 2;
	cout << nums[0] << " " << nums[1] << endl;

	int nums2[2] = {3, 4}; //初始时一次声明多个；只能在定义数组时才能使用初始化，已不能将一个数组赋值给另一个数组
	cout << nums2[0] << " " << nums2[1] << endl;

	int total[5] = {0};     //赋值个数小于数组长度时，其余的都被设置为0，只要显示的第一个元素设置为0则其他的都为0
	cout << total[3] << endl;

	double strs[3] {2.7, 4.9};      //double数组初始化不需要"="
	cout << strs[1] << endl;

	//int num[] = {23, 44, 0.4};      //不能缩窄数组中的元素属性
	double num[] = {23.4, 44, 0.4};   //可以扩大数组元素的属性范围

	//char dog[] = "Dog Wang!";     //使用引号扩起的字符串隐式的包括末尾的空字符。自带一个\0在末尾
	char dog[] = {'a', 'b', ' ', 'c', '\0'};    //'\0'表示结尾
	cout << dog << endl;

    char s1 = 's';  //单引号表示字符常量，在ASCII系统中实际上是将ASCII码赋值给了s1
    //char s2 = "s";  //"s"表示的是s和一个空字符组成的字符串，而s2其实是被赋予了一个内存地址，而地址是另一种数据类型，此处对s2的赋值就报错了

    char name1[15];
    cin >> name1;
    //cin使用空白（空格、制表、换行）来确定字符串的结束位置，这意味cin只会读取一个单词，读取后放在字符串末尾且补上空字符
    cout << "Hello! " << name1 << " your name is leng " << strlen(name1) << " Your arrey leng is " << sizeof(name1) <<endl;
    //sizeof计算的是整个数组的长度； strlen计算的是非空字符串的长度，只计算可见字符

    char name2[15];
    cin.getline(name2, 20);
    //getline读取指定数目的字符或遇到换行符时停止读取。getline会丢弃换行符，末尾使用空字符串。
    cout << "Hello! " << name2 << " your name is leng " << strlen(name2) << " Your arrey leng is " << sizeof(name2) <<endl;

    char name3[15];
    //get的第一种用法，和getline一致，但是会保留字符串最后的换行符。
    //cin.get(name3, 15);
    /*
    两个get函数一起使用时：
        cin.get(name1, 15);
        cin.get(name2, 15);
    第二个get函数遇到的是第一个字符就是换行符，因此他会认为已经到达行尾。如果没有其他操作，第二个get无法跨过这个换行符。

    前文name1的换行符就会对name2的读取产生影响

    解决方法：
    get()可以不带任何参数的读取一个字符，此时读取的就是换行符
        cin.get(name1, 15);
        cin.get();
        cin.get(name2, 15);
    另一种方法是函数拼接：
        cin.get(name1, 15).get();
    */

   cin.get(name3, 15).get();
   cin.clear();
   char name4[15];
   cin.get(name4, 15).get();
   cout << name3 << " say hello to " << name4 <<endl;

    /*
    空行问题：
    int year;
    cin >> year;

    char add[20];
    cin.getline(add,20);

    在这种情况下，对于键盘输入的一个整数传给year之后，紧接着的空格符会直接传给getline，此时会被认为是一个空行
    并将空字符串传给add，用户没有机会再第二次输入。

    解决方法：
    在add输入之前，先读取并丢弃换行符
    如cin >> year; cin.get(); 或者 (cin >> year).get();

    截断问题：
    char name[20];
    char add[20];

    cin.getline(name, 20);
    cin.getline(add,20);

    在这种情况下，当用户在name处输入超过20个字符时，多余的字符会保留在结束读取的位置，余下字符会留在输出队列中并传给add

    解决方法：?待解决
    cin.clear()    
    */

}
