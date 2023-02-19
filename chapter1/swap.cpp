//1-1 函数内的局部变量x和y进行了交换，并不是传入函数的实参进行了交换正确代码
#include<iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 5, b = 6;
    cout<< "before: " << a << " and " << b << endl;
    swap(a,b);
    cout<< "after: " << a << " and " << b << endl;
}