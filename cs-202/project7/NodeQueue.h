#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "DataType.h"

template <class D_T>
class NodeQueue;

template <class D_T>
class Node {
public:
    Node(){
        m_next = NULL;
    }
    Node(const D_T& data, Node<D_T>* next = NULL){
        m_next = next;
        m_data = data;					//uses D_T's assignment operator=
    }
    
    D_T& getData(){			//gets non-const reference, can be used to modify value of underlying data
        //return const_cast<D_T&>(static_cast<const Node&>(*this).getData());  //an alternative implementation, for reference
        return m_data;
    }
    const D_T& getData() const{ 	//gets const reference, can be used to access value of underlying data
        return m_data;
    }
    Node<D_T>* getNext(){
        return m_next;
    }
    const Node<D_T>* getNext() const{
        return m_next;
    }
    
    friend class NodeQueue<D_T>;					//allows accessing of link(s) and data from NodeQueue (link remains otherwise inaccessible outside of Node)
private:
    Node<D_T>* m_next; 						//the link to next node
    D_T m_data;						//the actual data
};

template <class D_T>
class NodeQueue{
private:
    Node<D_T>* m_front;  //templated Node pointer type that points to the front (first) element of the Queue
    Node<D_T>* m_back;   //templated Node pointer type that points to the back (last) element of the Queue
    
public:
    NodeQueue(); //(1)
    NodeQueue(int size, const D_T& value); //(2)
    NodeQueue(const NodeQueue<D_T>& other); //(3)
    ~NodeQueue(); //(4)
    NodeQueue<D_T>& operator= (const NodeQueue<D_T>& other_nodeQueue); //(5)
    D_T& front(); //(6a)
    const D_T& front() const; //(6b)
    D_T& back(); //(7a)
    const D_T& back() const; //(7b)
    void push(const D_T& value); //(8)
    void pop(); //(9)
    int size() const; //(10)
    bool empty() const; //(11)
    bool full() const; //(12)
    void clear(); //(13)
    
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const NodeQueue<U>& nodeQueue);
};

template <class D_T>
NodeQueue<D_T>::NodeQueue()
//Default constructor that instantiates new Queue object with no valid data
{
    m_front = NULL;
    m_back = NULL;
}
template <class D_T>
NodeQueue<D_T>::NodeQueue(int size, const D_T& value)
/*Parameterized constructor that instantiates new Queue object which will hold
 an int size number of elements, all initialized to have same value as parameter*/
{
    if (size <= 0)
    {
        m_front = NULL;
        m_back = NULL;
    }
    else
    {
        m_front = new Node<D_T> (value, NULL);
        Node<D_T>* temp = m_front;
        for (int i = 1; i < size; i++)
        {
            temp->m_next = new Node<D_T> (value, NULL);
            temp = temp->getNext();
        }
        m_back = temp;
        temp->m_next = NULL;
    }
}
template <class D_T>
NodeQueue<D_T>::NodeQueue(const NodeQueue<D_T>& other)
/*Copy constructor that instantiates new Queue object which is a separate copy of the
 data of the other Queue object which is getting copied*/
{
    if (other.m_front != NULL)
    {
        m_front = new Node<D_T> (other.m_front->getData(), NULL);
        
        Node<D_T>* temp1 = m_front;
        Node<D_T>* temp2 = other.m_front;
        while (temp2->getNext() != NULL)
        {
            temp2 = temp2->getNext();
            temp1->m_next = new Node<D_T> (temp2->getData(), NULL);
            temp1 = temp1->getNext();
        }
        m_back = temp1;
        temp1->m_next = NULL;
    }
    else
    {
        m_front = NULL;
        m_back = NULL;
    }
}
template <class D_T>
NodeQueue<D_T>::~NodeQueue()
//Destructor which destroys the instance of the Queue object
{
    clear();
}
template <class D_T>
NodeQueue<D_T>& NodeQueue<D_T>::operator= (const NodeQueue<D_T>& other_nodeQueue)
/*Given a NodeQueue object, the operator= will assign a new value to the calling Queue object,
 which will be an exact copy of the NodeQueue object passed as a parameter*/
{
    if (other_nodeQueue.m_front != NULL)
    {
        m_front = new Node<D_T> (other_nodeQueue.m_front->getData(), NULL);
        
        Node<D_T>* temp1 = m_front;
        Node<D_T>* temp2 = other_nodeQueue.m_front;
        while (temp2->getNext() != NULL)
        {
            temp2 = temp2->getNext();
            temp1->m_next = new Node<D_T> (temp2->getData(), NULL);
            temp1 = temp1->getNext();
        }
        m_back = temp1;
        temp1->m_next = NULL;
    }
    else
    {
        m_front = NULL;
        m_back = NULL;
    }
    return *this;
}
template <class U>
std::ostream& operator<<(std::ostream& os, const NodeQueue<U>& nodeQueue)
/*Overloaded operator that will output to the terminal or file depending on
 the type of ostream& os object passed to it, the content of the Queue object*/
{
    NodeQueue<U> temp(nodeQueue);
    for (int i = 0; i < temp.size(); i++)
    {
        os << temp.front() << " ";
        temp.pop();
    }
    return os;
}
template <class D_T>
D_T& NodeQueue<D_T>::front()
//Returns a reference to the first element (Node) of the Queue
{
    return m_front->getData();
}
template <class D_T>
const D_T& NodeQueue<D_T>::front() const
//Returns a reference to the first element (Node) of the Queue
{
    return m_front->getData();
}
template <class D_T>
D_T& NodeQueue<D_T>::back()
//Returns a reference to the last element (Node) of the Queue
{
    return m_back->getData();
}
template <class D_T>
const D_T& NodeQueue<D_T>::back() const
//Returns a reference to the last element (Node) of the Queue
{
    return m_back->getData();
}
template <class D_T>
void NodeQueue<D_T>::push(const D_T& value)
//Inserts at the back of the Queue a Node element of the given value
{
    Node<D_T>* tempNode_Pt = new Node<D_T>(value);
    if (empty())
    {
        tempNode_Pt->m_next = NULL;
        m_back = tempNode_Pt;
        m_front = tempNode_Pt;
    }
    else
    {
        tempNode_Pt->m_next = NULL;
        m_back->m_next = tempNode_Pt;
        m_back = tempNode_Pt;
    }
}
template <class D_T>
void NodeQueue<D_T>::pop()
//Removes from the front element of the Queue if it is not empty
{
    if (!empty())
    {
        Node<D_T>* delete_Pt = m_front;
        m_front = m_front->m_next;
        delete delete_Pt;
    }
}
template <class D_T>
int NodeQueue<D_T>::size() const
//Returns the size of the current Queue
{
    int counter = 0;
    Node<D_T>* temp = m_front;
    while (temp != NULL)
    {
        counter++;
        temp = temp->getNext();
    }
    return counter;
}
template <class D_T>
bool NodeQueue<D_T>::empty() const
//Returns a bool, true if the Queue is empty (m_front is NULL), false otherwise
{
    if (m_front == NULL)
    {
        return true;
    }
    return false;
}
template <class D_T>
bool NodeQueue<D_T>::full() const
//Returns a bool, true if the Queue is full (m_front is NULL), false otherwise
{
    return false;
}
template <class D_T>
void NodeQueue<D_T>::clear()
//Clears the contents of the Queue, so after its call will be an empty Queue object
{
    Node<D_T>* current = m_front;
    Node<D_T>* previous = m_front;
    while (current != NULL)
    {
        current = current->getNext();
        delete previous;
        previous = current;
    }
    m_front = NULL;
}

#endif
