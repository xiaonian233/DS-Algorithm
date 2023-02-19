#include<iostream>
using namespace std;

// int fenduan(int n)
// {
//     if(n % 2)
//         return fenduan(3 * n + 1);
//     else
//         return n / 2;
// }
// int fenduan_non(int n)
// {
//     if(n % 2)n = n * 3 + 1;
//     return n / 2;
// }
// int ackerfun(int i,int j)
// {
//     if(i == 1 && j >= 1)
//     {
//         int sum = 1;
//         while (j--)
//         {
//             sum*=2;
//         }
//         return sum;
//     }
//     if(i >=2 && j == 1)
//     {
//         return ackerfun(i - 1,2);
//     }
//     return ackerfun(i - 1, ackerfun(i, j - 1));
// }
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    cout<<gcd(10,0);
}
