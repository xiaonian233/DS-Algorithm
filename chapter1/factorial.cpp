#include<iostream>
using namespace std;
long factorial(int n)
{
    if(n <= 1)return 1;
    long sum = 1;
    for(int i = 1;i<=n;i++)
    {
        sum *= i;
    }
    return sum;
    
}
int main()
{
    cout<<factorial(5);
}
