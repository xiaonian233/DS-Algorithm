#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
//三参数
template<typename T>
T accumulate(T* start, T* end, T init)
{
    T rel = init;
    while (start!=end)
    {
        rel+=*start;
        start++;
    }
    return rel;
}
//四参数
int function(int a) 
{
    return 3 * a;
}
template<typename T>
T accumulate(T* start, T* end, T init, T (*operation)(T))
{
    T rel = init;
    while (start!=end)
    {
        rel+= operation((*start));
        start++;
    }
    return rel;
}
//copy实现
template<typename T>
void copy(T* start, T* end, T* to)
{
    unsigned long index = end - start;
    for(int i = 0;i< index;i++)
    {
        *(to+i) = *(start+i);
    }
    
}
//修改1-35
template<typename T>
void permutations(T list[],int m)
{
    sort(list,list+m+1);
    do
    {
        copy(list,list+m+1,ostream_iterator<T>(cout," "));
        cout<<endl;
    } while (next_permutation(list,list+m+1));
    
}

int main()
{
    int a[3] = {1,2,3};
    int b[3];
    permutations(a,2);
}
