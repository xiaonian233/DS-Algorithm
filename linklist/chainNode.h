template<typename T>
struct chainNode
{   
    T element;
    chainNode<T> *next;
    chainNode() {}
    chainNode(const T& theElement)
    {
        this->element = theElement;
    }
    chainNode(const T& theElement, chainNode<T>* next)
    {
        this->element = theElement;
        this->next = next;
    }
};
