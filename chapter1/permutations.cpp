#include<iostream>
#include <iterator>
using namespace std;
template<typename T>
void permutations(T list[], int k, int m)
{
    if(k == m) 
    {
        copy(list,list+m+1,ostream_iterator<T>(cout," "));
        cout<<endl;
    } else {
        for(int i = k; i<=m; i++)
        {
            swap(list[k],list[i]);
            cout<<"上k: "<<k<<" i: "<<i<<endl;
            permutations(list,k+1,m);
            swap(list[k],list[i]);
            cout<<"下k: "<<k<<" i: "<<i<<endl;
        }
    }

}

int main()
{
    char a[3] = {'1','2','3'};
    permutations(a,0,2);
    return 0;
}   
