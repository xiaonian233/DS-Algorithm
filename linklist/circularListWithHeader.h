//#ifdef cirucalarListWithHeader_
//#define cirucalarListWithHeader_

#include<iostream>
#include<string>
#include<sstream>
#include"chainNode.h"
using namespace std;
template<typename T>
class circularListWithHeader
{
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* headerNode;
    int listSize;
public:
    circularListWithHeader();
    int size() const{return listSize;}
    void insert(int theIndex,const T& theElement);
    int indexOf(const T& theElement) const;
    void output(ostream& out)const;
};

template<typename T>
circularListWithHeader<T>::circularListWithHeader()
{
    headerNode = new chainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}
template<typename T>
void circularListWithHeader<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0||theIndex >=listSize)return;
}
template<typename T>
int circularListWithHeader<T>::indexOf(const T& theElement) const
{
    headerNode->element = theElement;
    chainNode<T>* currentNode = headerNode->next;
    int index = 0;
    while (currentNode->element!=theElement)
    {
        currentNode = currentNode->next;
        index ++;
    }
    if(currentNode == headerNode)
        return -1;
    else
        return index;
}
template<typename T>
void circularListWithHeader<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0||theIndex > listSize)return;
    chainNode<T>* p = headerNode;
    for(int i =0;i<theIndex;i++)
        p = p->next;
    p->next = new chainNode<T>(theElement,p->next);
    listSize++;
}
template<typename T>
void circularListWithHeader<T>::output(ostream& out) const
{
    for(chainNode<T>* currentNode = headerNode; currentNode!=headerNode;currentNode=currentNode->next)
        out<<currentNode->element<<"  ";
}
template<typename T>
ostream& operator<<(ostream& out, const circularListWithHeader<T>& x)
{
    x.output(out);
    return out;
}



//#endif