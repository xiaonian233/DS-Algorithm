#include<iostream>
using namespace std;
template<typename T>
void make2dArray(T** &a, int numberOfRows, int rowSize[])
{
    //创建行空间
    a = new T* [numberOfRows];
    for(int i = 0; i < numberOfRows; i++)
    {
        a[i] = new int [rowSize[i]];
    }   
}
int main()
{
    int** a;
    int rowSize[2];
    rowSize[0] = 2;
    rowSize[1] = 3;
    make2dArray(a,2,rowSize);
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 9;
    a[1][0] = 3;
    a[1][1] = 4;
    a[1][2] = 5;
    for(int i = 0;i<2;i++)
        for(int j =0;j<3;j++)
            cout<<a[i][j]<<" ";
    return 0;
}