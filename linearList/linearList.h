#ifndef linearList_
#define linearList_
#include <iostream>

using namespace std;
template<typename T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int Index) const = 0;
    virtual int indexOf(const T& Element) const = 0;
    virtual void erase(int Index) = 0;
    virtual void insert(int theIndex, const T& Element) = 0;
    virtual void output(ostream& out) const = 0;
};
#endif
