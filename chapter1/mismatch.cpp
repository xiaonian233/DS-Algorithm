#include<iostream>
using namespace std;
template<typename T>
int mismatch(T* arr, T* brr, int n)
{
    int rel = 0;
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] != brr[i])
        {
            rel = i;
            break;
        }
    }
    return rel;
}
int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {1, 2, 6, 7, 9};
    int c[] = {1, 3, 5, 6, 9};
    cout << "a and b: " <<mismatch(a,b,5)<<endl;
    cout << "c and b: " <<mismatch(c,b,5)<<endl;
    cout << "a and c: " <<mismatch(a,c,5)<<endl;
    return 0;
}