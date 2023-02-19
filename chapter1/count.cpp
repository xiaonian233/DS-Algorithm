#include<iostream>
using namespace std;
template<typename T>
int count(const T& arr)
{
    return (sizeof(arr)/sizeof(arr[0]));
}
int main()
{
    int a[] = {1, 3, 5, 7, 9};
    double b[] = {1.1, 12.540, 531.03};
    cout << "a lenght: "<< count(a)<<endl;
    cout << "b lenght: "<< count(b)<<endl;
    return 0;
}