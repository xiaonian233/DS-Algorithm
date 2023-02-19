#include<iostream>
using namespace std;
long fibo_rec(int n)
{
    if(n <= 2)return 1;
    return fibo_rec(n-1) + fibo_rec(n-2);
}
long fibo(int n)
{
    if(n <= 2)return 1;
    int q = 1;
    int h = 1;
    int temp = 0;
    for(int i = 1; i <= n - 2; i++)
    {
        temp = q + h;
        q = h;
        h = temp;
    }
    return temp;

}
int main()
{
    cout<<fibo(6)<<" non-rec: "<<fibo_rec(6);
}
