#include<iostream>
#include<string>
#include<sstream>
#include"chainNode.h"
using namespace std;
template<typename T>
class doublyLinkedList
{
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;
public:
    doublyLinkedList();
    int size() const{return listSize;}
    void insert(int theIndex,const T& theElement);
    int indexOf(const T& theElement) const;
    void output(ostream& out)const;
};
template<typename T>
doublyLinkedList<T>::doublyLinkedList()
{
    firstNode = NULL;
    lastNode = NULL;
    listSize = 0;
}
template<typename T>
void doublyLinkedList<T>::insert(int theIndex,const T& theElement)//TODO
{
    if(theIndex < 0||theIndex > listSize)return;
    chainNode<*> p = firstNode;
    for(int i = 0;i<theIndex;i++)
        p = p.next;
    p.next = new chainNode<T>(theIndex,p.next);
}
