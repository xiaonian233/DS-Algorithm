#include<iostream>
using namespace std;
template<typename T>
void fill(T* arr, int start, int end, const T& val)
{
    for(int i = start; i < end; i ++)
        arr[i] = val; 
}
int main()
{
    int *arr = new int[10];
    fill(arr,0,9,5);
    for(int i = 0; i < 10; i++)
    {
        cout << "arr: " << arr[i] << " ";
    }
    return 0;
}