#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include "linearList.h"

using namespace std;
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)//这里是将a看成T型指针，谁传进来都是a的别名，为了改变指针里面存的地址需要使用指针引用
{
   T* temp = new T[newLength]; 
   int number = min(oldLength, newLength); 
   copy(a, a + number, temp);
   delete [] a;
   a = temp;
   
}
template<class T>
class arrayList : public linearList<T> 
{
   public:
      arrayList(int initialCapacity = 10);
      arrayList(const arrayList<T>&);
      ~arrayList() {delete [] element;}

      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;
      int capacity() const {return arrayLength;}
      void reserve(int theCapacity);
      void trimToSize();
      void clear();
      T& set(int theIndex, const T& theElement);
      T& operator [](int i) {return *(element + i);}
      arrayList<T>& swap(arrayList<T>& theList);
      bool operator<(const arrayList<T>& A) const
      {
        if(size() < A.size())return true;
        int num = min(size(),A.size());
        for(int i = 0; i < num; i++)
        {
            if(element[i] < (A.element[i]))return true;
        }
        return false;
      }
      void push_back(const T& theElement);
      void pop_back();
      arrayList<T>& setSize(int size);
      class iterator;
      iterator begin(){return element;}
      iterator end(){return element+listSize;}
      class iterator
      {
      protected:
        T* position;
        
      public:
        //用c++的typedef实现双向迭代器
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        iterator(T* thePosition = 0){position = thePosition;}
        T& operator*() const {return *position;}
        T* operator->() const {return &*position;}
        iterator& operator++()
        {
            ++position;
            return *this;
        }
        iterator operator++(int)//后置++
        {
            iterator old = *this;
            ++position;
            return old;
        }
        iterator& operator--()
        {
            --position;
            return *this;
        }
        iterator operator--(int)//后置--
        {
            iterator old = *this;
            --position;
            return old;
        }
        bool operator!=(const iterator right) const{
            return position != right.position;
        }
        bool operator==(const iterator right) const{
            return position == right.position;
        }
      };
      

   protected:
      void checkIndex(int theIndex) const;
      T* element;
      int arrayLength;
      int listSize;
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
   if (initialCapacity < 1)
   {
    return;
   }
   arrayLength = initialCapacity;
   element = new T[arrayLength];
   listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
   arrayLength = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}
template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= listSize)return;
}
template<typename T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}
template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int)(find(element,element+listSize,theElement) - element);
    if(theIndex == listSize)return -1;
    else return theIndex;
}
//已加入缩长度
template<typename T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex +1,element+listSize,element+theIndex);
    if (listSize < arrayLength/4)
    {
        int num = max(10,arrayLength/2);
        changeLength1D(element,arrayLength,num);
        arrayLength = num;
    }
    element[--listSize].~T();
}
template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        return;
    }
    if(listSize == arrayLength)
    {
        changeLength1D(element,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex] = theElement;
    listSize++;
}
template<typename T>
void arrayList<T>::output(ostream& out) const
{
    copy(element,element+listSize,ostream_iterator<T>(out," "));
}
template<typename T>
ostream& operator<<(ostream& out,const arrayList<T>& x)
{
    x.output(out);
    return out;
}
template<typename T>
void arrayList<T>::trimToSize()
{
    int num = max(listSize,1);
    changeLength1D(element,arrayLength,num);
    arrayLength = num;
}
template<typename T>
arrayList<T>& arrayList<T>::setSize(int size)
{
    if(size < 0 || size > listSize)return *this;
    listSize = size;
    return *this;
}
//编写方法 arrayList<T>::push_back，它把元素 theElement 插到线性表的右端。不要利用
//insert 方法。方法的时间复杂度是多少?测试你的代码。
template<typename T>
void arrayList<T>::push_back(const T& theElement)
{
    if(listSize == arrayLength)
    {
        changeLength1D(element,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    element[listSize++] = theElement;
}
//编写方法 arrayList<T>::pop_back，它把线性表右端的元素删除。不要利用 erase 方法。方
//法的时间复杂度是多少? 测试你的代码。
template<typename T>
void arrayList<T>::pop_back()
{
    if(listSize <= 0)return;
    element[--listSize].~T();
}
//编写方法 arrayList<T>::swap(theLisb，它交换线性表的元素 *this 和 theList。方法的时间
//复杂度是多少? 测试你的代码。
template<typename T>
arrayList<T>& arrayList<T>::swap(arrayList<T>& theList)
{
    std::swap(listSize, theList.listSize);
    std::swap(arrayLength,theList.arrayLength);
    std::swap(element,theList.element);
    return *this;
}
//编写方法 arrayList<T>::reserve(theCapacity)，它把数组的容量改变为当前容量和 theCapacity
//的较大者。测试你的代码。
template<typename T>
void arrayList<T>::reserve(int theCapacity)
{
    int num = max(arrayLength,theCapacity);
    changeLength1D(element,arrayLength,num);
    arrayLength = num;
}
//编写方法 arrayList<T>::set(theIndex,theElement)，它用元素 theElement 替换索引为 theIndex
//的元素。若索引 theIndex 超出范围，则抛出异常。返回原来索引为 theIndex 的元素。测试你的代码。
template<typename T>
T& arrayList<T>::set(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    T& old = element[theIndex];
    element[theIndex] = theElement;
    return old;
}
//编写方法 arrayList<T>::clear，它使线性表为空。方法的复杂度是多少?” 测试你的代码。
template<typename T>
void arrayList<T>::clear()
{
    for(int i = 0; i < listSize; i++)
        element[listSize].~T();
    listSize = 0;
    arrayLength = 10;
}

#endif