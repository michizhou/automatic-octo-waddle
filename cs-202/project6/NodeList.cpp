#include "NodeList.h"

NodeList::NodeList()
//Default constructor that instantiates new list object with no valid data
{
    m_head = NULL;
}//(1)
NodeList::NodeList(int size, const DataType& value)
/*Parameterized constructor that instantiates new list object which will hold
 an int size number of elements, all initialized to have same value as parameter*/
{
    if (size <= 0)
    {
        m_head = NULL;
    }
    else
    {
        m_head = new Node (value, NULL);
        Node* temp = m_head;
        for (int i = 1; i < size; i++)
        {
            temp->m_next = new Node (value, NULL);
            temp = temp->m_next;
        }
        temp->m_next = NULL;
    }
}//(2)
NodeList::NodeList(const NodeList& other)
/*Copy constructor that instantiates new list object which is a separate copy of the
 data of the other list object which is getting copied*/
{
    
    if (other.m_head != NULL)
    {
        m_head = new Node (other.m_head->getData(), NULL);
        
        Node* temp1 = m_head;
        Node* temp2 = other.m_head;
        while (temp2->m_next != NULL)
        {
            temp2 = temp2->m_next;
            temp1->m_next = new Node (temp2->getData(), NULL);
            temp1 = temp1->m_next;
        }
        temp1->m_next = NULL;
    }
}//(3)
NodeList::~NodeList()
//Destructor which destroys the instance of the list object
{
    clear();
}//(4)

NodeList& NodeList::operator= (const NodeList& other_nodeList)
/*Given a NodeList object, the operator= will assign a new value to the calling list object,
 which will be an exact copy of the NodeList object passed as a parameter*/
{
    Node* temp1 = m_head;
    Node* temp2 = other_nodeList.m_head;
    if (this->size() < other_nodeList.size())
    {
        clear();
        DataType data0(0, 0.0);
        NodeList new1(other_nodeList.size(), data0);
        temp1 = new1.m_head;
    }
    while (temp2->m_next != NULL)
    {
        temp1->m_data = temp2->getData();
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
    }
    return *this;
}//(5)
std::ostream& operator<<(std::ostream& os, const NodeList& nodeList)
/*Overloaded operator that will output to the terminal or file depending on
 the type of ostream& os object passed to it, the content of the list object*/
{
    for (int i = 0; i < nodeList.size(); i++)
    {
        os << nodeList[i] << " ";
    }
    return os;
}
Node* NodeList::first()
//Returns a pointer to the first element (Node) of the list, or NULL if list is empty
{
    return m_head;
}
const Node* NodeList::first() const
//Returns a pointer to the first element (Node) of the list, or NULL if list is empty
{
    return m_head;
}			      	//(7b)
Node* NodeList::last()
//Returns a pointer to the last element (Node) of the list, or NULL if list is empty
{
    Node* temp = m_head;
    while (temp->m_next != NULL)
    {
        temp = temp->m_next;
    }
    return temp;
}
const Node* NodeList::last() const
//Returns a pointer to the last element (Node) of the list, or NULL if list is empty
{
    Node* temp = m_head;
    while (temp->m_next != NULL)
    {
        temp = temp->m_next;
    }
    return temp;
}
Node* NodeList::find(const DataType& target, Node* &previous)
/*Returns a pointer to the first element of the list that holds the same value as the
 passed parameter target; if it fails to find the value, it returns NULL. Also takes in
 a Node pointer parameter and sets it to the address of the target Node's predecessor*/
{
    Node* node_Pt = m_head;
    while (node_Pt->m_next != NULL && node_Pt != NULL)
    {
        if (node_Pt->m_next->getData() == target)
        {
            if (node_Pt != NULL)
            {
                previous = node_Pt;
            }
            else
            {
                previous = NULL;
            }
            return node_Pt->m_next;
        }
        node_Pt = node_Pt->m_next;
    }
    previous = NULL;
    return NULL;
}
const Node* NodeList::find(const DataType& target, const Node* &previous) const
/*Returns a pointer to the first element of the list that holds the same value as the
 passed parameter target; if it fails to find the value, it returns NULL. Also takes in
 a Node pointer parameter and sets it to the address of the target Node's predecessor*/
{
    Node* node_Pt = m_head;
    while (node_Pt->m_next != NULL && node_Pt != NULL)
    {
        if (node_Pt->m_next->getData() == target)
        {
            if (node_Pt != NULL)
            {
                previous = node_Pt;
            }
            else
            {
                previous = NULL;
            }
            return node_Pt->m_next;
        }
        node_Pt = node_Pt->m_next;
    }
    previous = NULL;
    return NULL;
}
Node* NodeList::insertAfter(const DataType& target, const DataType& value, int count)
/*First finds the element that contains DataType target and then inserts after it a
 new element that holds the value DataType value, returning a Node pointer to value.*/
{
    Node* temp = m_head;
    while (temp != NULL)
    {
        if (temp->getData() == target && temp != NULL)
        {
            temp->m_next = new Node (value,temp->m_next);
            return temp->m_next;
        }
        temp = temp->m_next;
    }
    if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }
    return NULL;
}
Node* NodeList::insertBefore(const DataType& target, const DataType& value, int count)
/*First finds the element that contains DataType target and then inserts before it a
 new element that holds the value DataType value, returning a Node pointer to value.*/
{
    if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }
    else if (m_head->getData() == target)
    {
        Node* m_newHead = new Node (value, NULL);
        m_newHead->m_next = m_head;
        return m_newHead;
    }
    
    Node* first = NULL;
    Node* second = m_head;
    
    while (second != NULL)
    {
        if (second->getData() == target && second != NULL)
        {
            first->m_next = new Node (value,second);
            return first->m_next;
        }
        first = second;
        second = second->m_next;
    }
    return NULL;
}
Node* NodeList::removeForward(const DataType& target, int count)
/*Finds the element that contains the target and then removes it from the list.
 Returns a Node pointer to the element after the last one it removed.*/
{
    if (m_head->getData() == target)
    {
        m_head = m_head->m_next;
        return m_head;
    }
    if (empty())
    {
        return NULL;
    }
    else
    {
        Node *first, *second;
        second = find(target,first);
        if (second != NULL)
        {
            first->m_next = second->m_next;
            delete second;
            return first->m_next;
        }
    }
    return NULL;
}
Node* NodeList::removeBackward(const DataType& target, int count)
/*Finds the element that contains the target and then removes it from the list.
 Returns a Node pointer to the element before the last one it removed.*/
{
    if (m_head->getData() == target)
    {
        m_head = m_head->m_next;
        return m_head;
    }
    if (empty())
    {
        return NULL;
    }
    else
    {
        Node *first, *second;
        second = find(target,first);
        if (second != NULL)
        {
            first->m_next = second->m_next;
            delete second;
            return first;
        }
    }
    return NULL;
}
DataType& NodeList::operator[] (int position)
/*Allows by-reference accessing of a specific DataType within a Node at an
 index position within the linked list*/
{
    Node* current = m_head;
    for (int i = 0; i < position; i++)
    {
        current++;
    }
    return current->getData();
}
const DataType& NodeList::operator[] (int position) const
/*Allows by-reference accessing of a specific DataType within a Node at an
 index position within the linked list*/
{
    Node* current = m_head;
    for (int i = 0; i < position; i++)
    {
        current++;
    }
    return current->getData();
}
int NodeList::size() const
//Returns the size of the current list
{
    int counter = 0;
    Node* temp = m_head;
    while (temp != NULL)
    {
        counter++;
        temp = temp->m_next;
    }
    return counter;
}//(15)
bool NodeList::empty() const
//Returns a bool, true if the list empty (m_head is NULL), false otherwise
{
    if (m_head == NULL)
    {
        return true;
    }
    return false;
}//(16)
void NodeList::clear()
//Clears the contents of the list, so after its call will be an empty list object
{
    Node* current = m_head;
    Node* previous = m_head;
    while (current != NULL)
    {
        current = current->m_next;
        delete previous;
        previous = current;
    }
    m_head = NULL;
}
