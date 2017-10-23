#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "DataType.h"

const int ARRAY_MAX = 1000;

template <class D_T>
class ArrayQueue{
private:
    D_T m_array[ARRAY_MAX];  //array that holds the data in the form of DataType class objects
    int m_front;  //respective m_array index of the front (first) element of the Queue
    int m_back;   //respective m_array index of the back (last) element of the Queue
    int m_size;   //number of valid elements currently stored in the Queue
    
public:
    ArrayQueue(); //(1)
    ArrayQueue(int size, const D_T& value); //(2)
    ArrayQueue(const ArrayQueue<D_T>& other); //(3)
    ~ArrayQueue(); //(4)
    ArrayQueue<D_T>& operator= (const ArrayQueue<D_T>& other_arrayQueue); //(5)
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
    friend std::ostream& operator<<(std::ostream& os, const ArrayQueue<U>& arrayQueue);
};

template <class D_T> 
ArrayQueue<D_T>::ArrayQueue()
//Default constructor that instantiates new Queue object
{
    m_front = 0;
    m_back = 0;
    m_size = 0;
}
template <class D_T> 
ArrayQueue<D_T>::ArrayQueue(int size, const D_T& value)
/*Parameterized constructor that instantiates new Queue object which will hold
 an int size number of elements, all initialized to have same value as parameter*/
{
    m_size = size;
    m_front = 0;
    m_back = m_size - 1;
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = value;
    }
}
template <class D_T> 
ArrayQueue<D_T>::ArrayQueue(const ArrayQueue<D_T>& other)
/*Copy constructor that instantiates new Queue object which is a separate copy of the
 data of the other Queue object which is getting copied*/
{
    m_size = other.m_size;
    m_front = other.m_front;
    m_back = other.m_back;
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = other.m_array[i];
    }
}
template <class D_T> 
ArrayQueue<D_T>::~ArrayQueue()
//Destructor which destroys the instance of the Queue object
{
    clear();
}
template <class D_T> 
ArrayQueue<D_T>& ArrayQueue<D_T>::operator= (const ArrayQueue<D_T>& other_arrayQueue)
/*Given an ArrayQueue object, the operator= will assign a new value to the calling Queue object,
 which will be an exact copy of the ArrayQueue object passed as a parameter*/
{
    if (this != &other_arrayQueue)
    {
        m_size = other_arrayQueue.m_size;
        m_front = other_arrayQueue.m_front;
        m_back = other_arrayQueue.m_back;
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = other_arrayQueue.m_array[i];
        }
    }
    return *this;
}
template <class U>
std::ostream& operator<<(std::ostream& os, const ArrayQueue<U>& arrayQueue)
/*Overloaded operator that will output to the terminal or file depending on
 the type of ostream& os object passed to it, the content of the Queue object*/
{
	 ArrayQueue<U> temp(arrayQueue);
    for (int i = 0; i < temp.size(); i++)
    {
        os << temp.front() << " ";
        temp.pop();
    }
    return os;
}
template <class D_T> 
D_T& ArrayQueue<D_T>::front()
//Returns a reference to the first element of the Queue
{
    return m_array[m_front];
}
template <class D_T> 
const D_T& ArrayQueue<D_T>::front() const
//Returns a reference to the first element of the Queue
{
    return m_array[m_front];
}
template <class D_T> 
D_T& ArrayQueue<D_T>::back()
//Returns a reference to the last element of the Queue
{
    return m_array[m_back];
}
template <class D_T> 
const D_T& ArrayQueue<D_T>::back() const
//Returns a reference to the last element of the Queue
{
    return m_array[m_back];
}
template <class D_T> 
void ArrayQueue<D_T>::push(const D_T& value)
/*First finds the element that contains D_T target and then inserts before it a
 new element that holds the value D_T value, returning a D_T pointer to value.*/
{
    if (!full())
    {
        if (empty())
        {
            m_array[0] = value;
            m_size++;
        }
        else
        {
            m_back = (m_back + 1) % ARRAY_MAX;
            m_array[m_back] = value;
            ++m_size;
        }
    }
}
template <class D_T> 
void ArrayQueue<D_T>::pop()
/*Finds the element that contains the target and then removes it from the Queue.
 Returns a D_T pointer to the element after the last one it removed.*/
{
    if (!empty())
    {
        m_front = (m_front + 1) % ARRAY_MAX;
        --m_size;
    }
}
template <class D_T> 
int ArrayQueue<D_T>::size() const
//Returns the size of the current array
{
    return m_size;
}
template <class D_T> 
bool ArrayQueue<D_T>::empty() const
//Returns a bool, true if the Queue is empty, false otherwise
{
    if (m_size == 0)
    {
        return true;
    }
    return false;
}
template <class D_T> 
bool ArrayQueue<D_T>::full() const
{
    if (m_size == ARRAY_MAX)
    {
        return true;
    }
    return false;
}
template <class D_T> 
void ArrayQueue<D_T>::clear()
//Clears the contents of the Queue, so after its call will be an empty Queue object
{
    if (m_size > 0)
    {
        for (int i = 0; i < m_size; i++)
        {
            pop();
        }
    }
    m_size = 0;
    m_front = 0;
    m_back = 0;
}

#endif
