#include<iostream>
using namespace std;

template<typename T>
bool is_inarr(T arr[], T val, int len) 
{
    if(arr[len - 1] != val && len - 2 >= 0)
    {
        return is_inarr(arr,val,len-1);
    }
    if(arr[len - 1] == val)
        return true;
    
    return false;
}
int main()
{
    int a[3] = {1, 2, 3};
    cout<<is_inarr(a,5,3);
}
