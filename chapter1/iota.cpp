#include<iostream>
using namespace std;
template<typename T>
void iota(T* arr, int n, int val)
{
    for(int i = 0; i < n; i++)
        arr[i] = val + i;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    iota(arr,5,9);
    for(int i = 0; i < 10; i++)
    {
        cout << "arr: " << arr[i] << " ";
    }
}