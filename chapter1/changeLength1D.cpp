#include<iostream>
using namespace std;
int min(int a, int b)
{
    if(a > b)
        return b;
    else 
        return a;
}
template<typename T>
void changeLength1D(T* a, int oldLength, int newLength)
{
   T* temp = new T[newLength]; 
   int number = min(oldLength, newLength); 
   copy(a, a + number, temp);
   delete [] a;
   a = temp;
}
int main()
{
    int a[4]={1,3,5,4};
    changeLength1D(a,4,6);
    a[4] = 8;
    a[5] = 9;
    for(int i = 0;i<6;i++)
    cout<<a[i]<<" ";
    return 0;
}   