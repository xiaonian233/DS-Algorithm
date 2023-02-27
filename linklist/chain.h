#include"chainNode.h"
#include<algorithm>
#include"linearList\linearList.h"
template<typename T>
class chain : public linearList<T>
{
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstnode;
    int listSize;
public:
    chain (int initialCapacity = 10);
    chain (const chain<T>& theList);
    ~chain();
    bool empty() const{return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    class iterator;
    iterator begin(){return iterator(firstnode);}
    iterator end() {return iterator(NULL);}
    class interator
    {
    protected:
        chainNode<T>* node;
    public:
        typedef forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        interator(chainNode<T>* theNode = NULL){node = theNode;}
        T& operator->() const{return node->element;}
        T* operator&() const{return &node->element;}

        iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator old = *this;
            node = node->next;
            return old;
        }
        bool operator!=(const interator right)const {return node != right.node;}
        bool operator==(const interator right) const{return node == right.node;}
    };  
};
template<typename T>
void chain<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= listSize)return;
}
template<typename T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstnode = NULL;
    listSize = 0;
}
template<typename T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    if(listSize == 0)
    {
        firstnode = NULL;
        return;
    }
    chainNode<T>* sourceNode = theList.firstnode;
    firstnode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstnode;
    while ((sourceNode != NULL))
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}
template<typename T>
chain<T>::~chain()
{
    while (firstnode!=NULL)
    {
      chainNode<T>* nextNode = firstnode->next;
      delete firstnode;
      firstnode = nextNode;
    }
}
template<typename T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstnode;
    for(int i = 0;i<theIndex;i++)
    {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}
template<typename T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstnode;
    int index = 0;
    while (currentNode!=NULL && currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if(currentNode == NULL)
        return -1;
    else
        return index;
}
template<typename T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if(theIndex==0)
    {
        deleteNode = firstnode;
        firstnode = firstnode->next;
    }
    else
    {
        //p指向要删除节点的前驱节点
        chainNode<T>* p = firstnode;
        for(int i = 0;i<theIndex-1;i++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > listSize)
        return;
    if(theIndex == 0)
        firstnode = new chainNode<T>(theElement,firstnode);
    else
    {
        chainNode<T>* p = firstnode;
        for(int i = 0;i<theIndex-1;i++)
            p = p->next;
        p->next = new chainNode<T>(theElement,p->next);
    }
    listSize++;
}
template<typename T>
void chain<T>::output(ostream& out) const
{
    for(chainNode<T>* currentNode = firstnode;currentNode!=NULL;currentNode =currentNode->next)
        out<<currentNode->element<<" ";
}
template<typename T>
ostream& operator<<(ostream& out,const chain<T>& x)
{
    x.output(out);
    return out;
}
