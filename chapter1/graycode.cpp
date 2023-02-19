#include<iostream>
using namespace std;

void gray(int n)
{
    if(n == 1)cout<< 1;
    else
    {
        gray(n-1);
        cout<<","<<n<<",";
        gray(n-1);
    }
}
int main()
{
    gray(2);
}
