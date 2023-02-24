#ifndef studentRecord_
#define studentRecord_
#include<string>
#include<iostream>
using namespace std;
// //第一种实现方式
// struct studentRecord
// {
//     int score;
//     string* name;
//     int operator != (const studentRecord& x) const 
//     {
//         return (score != x.score);
//     }
// };
// ostream& operator<<(ostream& out,const studentRecord& x)
// {
//     out<<x.score<<' '<<*x.name<<endl;
//     return out;
// }
//第二种方式重载int()
// struct studentRecord
// {
//     int score;
//     string* name;
//     operator int() const {return score;}
// };
// ostream& operator<<(ostream& out,const studentRecord& x)
// {
//     out<<x.score<<' '<<*x.name<<endl;
//     return out;
// }
//二合一
struct studentRecord
{
    int score;
    string* name;
    int operator != (const studentRecord& x) const 
    {
        return (score != x.score);
    }
    operator int() const {return score;}
};
ostream& operator<<(ostream& out,const studentRecord& x)
{
    out<<x.score<<' '<<*x.name<<endl;
    return out;
}

#endif