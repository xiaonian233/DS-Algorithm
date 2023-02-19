#include<iostream>
using namespace std;
template<typename T>
bool is_sorted(T* arr, int n)
{
    bool asc,desc = false;
    for(int i = 0; i < n - 1; i ++)
    {
        if(arr[i] == arr[i + 1])
            continue;
        if(arr[i] > arr[i + 1])
            asc = true;
        else
            desc = true;
        if(asc && desc)
            return false;
    }
    return true;
}
int main()
{
    int arr1[5] = {1, 1, 1, 1, 1};
    int arr2[5] = {1, 3, 5, 7, 9};
    int arr3[5] = {10, 8, 6, 4, 2};
    int arr4[5] = {5, 6, 7, 1, 3};
    cout<< "arr1: "<<is_sorted(arr1,5)<<endl;
    cout<< "arr2: "<<is_sorted(arr2,5)<<endl;
    cout<< "arr3: "<<is_sorted(arr3,5)<<endl;
    cout<< "arr4: "<<is_sorted(arr4,5)<<endl;
}