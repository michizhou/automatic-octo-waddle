#include "ArrayList.h"

ArrayList::ArrayList()
//Default constructor that instantiates new list object
{
    m_array = NULL;
    m_size = 0;
    m_maxsize = 0;
}							//(1)
ArrayList::ArrayList(int size, const DataType& value)
/*Parameterized constructor that instantiates new list object which will hold
 an int size number of elements, all initialized to have same value as parameter*/
{
    m_array = new DataType[size];
    m_size = size;
    m_maxsize = size;
    for (int i = 0; i < m_maxsize; i++)
    {
        m_array[i] = value;
    }
}
ArrayList::ArrayList(const ArrayList& other)
/*Copy constructor that instantiates new list object which is a separate copy of the
 data of the other list object which is getting copied*/
{
    m_maxsize = other.m_maxsize;
    m_size = other.m_size;
    m_array = new DataType [m_maxsize];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = other.m_array[i];
    }
}
ArrayList::~ArrayList()
//Destructor which destroys the instance of the list object
{
    if (m_array != NULL)
    {
        delete [] m_array;
        m_array = NULL;
    }
    m_maxsize = 0;
    m_size = 0;
}
ArrayList& ArrayList::operator= (const ArrayList& other_arrayList)
/*Given an ArrayList object, the operator= will assign a new value to the calling list object,
 which will be an exact copy of the ArrayList object passed as a parameter*/
{
    if (this != &other_arrayList)
    {
        m_size = other_arrayList.m_size;
        m_maxsize = other_arrayList.m_maxsize;
        m_array = new DataType [m_maxsize];
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = other_arrayList.m_array[i];
        }
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList)
/*Overloaded operator that will output to the terminal or file depending on
 the type of ostream& os object passed to it, the content of the list object*/
{
    for (int i = 0; i < arrayList.m_size; i++)
    {
        os << arrayList.m_array[i] << " ";
    }
    return os;
}
DataType* ArrayList::first()
//Returns a pointer to the first element of m_array, or NULL if list is empty
{
    DataType* array_first_Pt = m_array;
    if (array_first_Pt != NULL)
    {
        return array_first_Pt;
    }
    return NULL;
}
const DataType* ArrayList::first() const
//Returns a pointer to the first element of m_array, or NULL if list is empty
{
    const DataType* array_first_Pt = m_array;
    if (array_first_Pt != NULL)
    {
        return array_first_Pt;
    }
    return NULL;
}
DataType* ArrayList::last()
//Returns a pointer to the last element of m_array, or NULL if list is empty
{
    DataType* array_last_Pt = m_array;
    if (array_last_Pt != NULL && m_size > 0)
    {
        for (int i = 0; i < m_size - 1; i++)
        {
            array_last_Pt++;
        }
        return array_last_Pt;
    }
    return NULL;
}
const DataType* ArrayList::last() const
//Returns a pointer to the last element of m_array, or NULL if list is empty
{
    DataType* array_last_Pt = m_array;
    if (array_last_Pt != NULL && m_size > 0)
    {
        for (int i = 0; i < m_size - 1; i++)
        {
            array_last_Pt++;
        }
        return array_last_Pt;
    }
    return NULL;
}
DataType* ArrayList::find(const DataType& target, DataType* &previous)
/*Returns a pointer to the first element of m_array, that holds the same value as the
 passed parameter target; if it fails to find the value, it returns NULL. Also takes in
 a Node pointer parameter and sets it to the address of the target Node's predecessor*/
{
    DataType* array_Pt = m_array;
    if (array_Pt != NULL)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (*array_Pt == target)
            {
                array_Pt--;
                if (array_Pt != NULL)
                {
                    previous = array_Pt;
                }
                else
                {
                    previous = NULL;
                }
                array_Pt++;
                return array_Pt;
            }
            array_Pt++;
        }
    }
    previous = NULL;
    return NULL;
}
const DataType* ArrayList::find(const DataType& target, const DataType* &previous) const
/*Returns a pointer to the first element of m_array, that holds the same value as the
 passed parameter target; if it fails to find the value, it returns NULL. Also takes in
 a Node pointer parameter and sets it to the address of the target Node's predecessor*/
{
    DataType* array_Pt = m_array;
    if (array_Pt != NULL)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (*array_Pt == target)
            {
                array_Pt--;
                if (array_Pt != NULL)
                {
                    previous = array_Pt;
                }
                else
                {
                    previous = NULL;
                }
                array_Pt++;
                return array_Pt;
            }
            array_Pt++;
        }
    }
    previous = NULL;
    return NULL;
}
DataType* ArrayList::insertAfter(const DataType& target, const DataType& value, int count)
/*First finds the element that contains DataType target and then inserts after it a
 new element that holds the value DataType value, returning a DataType pointer to value.*/
{
    int counter = 0;
    DataType* current = m_array;
    while (current != NULL)
    {
        if (target == *current)
        {
            if (m_size + count > m_maxsize)
            {
                grow(count);
                *current = m_array[counter];
            }
            for (int i = m_size + count - 1; i > counter + 1; i--)
            {
                m_array[i] = m_array[i-1];
            }
            m_array[counter+1] = value;
            *current = m_array[counter+1];
            return current;
        }
        counter++;
        current++;
    }
    if (empty())
    {
        m_array[0] = value;
        *current = m_array[0];
        m_size++;
        return current;
    }
    return NULL;
}
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value, int count)
/*First finds the element that contains DataType target and then inserts before it a
 new element that holds the value DataType value, returning a DataType pointer to value.*/
{
    int counter = 0;
    DataType* current = m_array;
    while (current != NULL)
    {
        if (target == *current)
        {
            if (m_size + count > m_maxsize)
            {
                grow(count);
                *current = m_array[counter];
            }
            for (int i = m_size + count - 1; i > counter; i--)
            {
                m_array[i] = m_array[i-1];
            }
            m_array[counter] = value;
            return current;
        }
        counter++;
        current++;
    }
    if (empty())
    {
        m_array[0] = value;
        *current = m_array[0];
        m_size++;
        return current;
    }
    return NULL;
}
DataType* ArrayList::removeForward(const DataType& target, int count)
/*Finds the element that contains the target and then removes it from the list.
 Returns a DataType pointer to the element after the last one it removed.*/
{
    int counter = 0;
    DataType* current = m_array;
    while (current != NULL)
    {
        if (target == *current)
        {
            for (int i = counter + count; i < m_size; i++)
            {
                m_array[i-1] = m_array[i];
            }
            if (counter == m_size - 1)
            {
                return NULL;
            }
            else
            {
                DataType* after = find(target,current);
                return after;
            }
            m_size -= count;
            trim();
        }
        counter++;
        current++;
    }
    return NULL;
}
DataType* ArrayList::removeBackward(const DataType& target, int count)
/*Finds the element that contains the target and then removes it from the list.
 Returns a DataType pointer to the element before the last one it removed.*/
{
    int counter = 0;
    DataType* current = m_array;
    while (current != NULL)
    {
        if (target == *current)
        {
            for (int i = counter + count; i < m_size; i++)
            {
                m_array[i-1] = m_array[i];
            }
            if (counter == 0)
            {
                return m_array;
            }
            else
            {
                return current--;
            }
            m_size -= count;
            trim();
        }
        counter++;
        current++;
    }
    return NULL;
}
DataType& ArrayList::operator[] (int position)
/*Allows by-reference accessing of a specific DataType within m_array at an
 index position within the m_array of the object*/
{
    return m_array[position];
}				//(14a)
const DataType& ArrayList::operator[] (int position) const
/*Allows by-reference accessing of a specific DataType within m_array at an
 index position within the m_array of the object*/
{
    return m_array[position];
}		   	//(14b)
int ArrayList::size() const
//Returns the size of the current array
{
    return m_size;
}							//(15)
bool ArrayList::empty() const
//Returns a bool, true if the list empty (m_head is NULL), false otherwise
{
    if (m_size == 0 && m_array == NULL)
    {
        return true;
    }
    return false;
}
void ArrayList::clear()
//Clears the contents of the list, so after its call will be an empty list object
{
    if (m_array != NULL)
    {
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}							//(17)

void ArrayList::grow(int addsize)
/*Given an int addsize, grow() will deallocate the dynamic memory pointed to by m_array and
 then allocate enough total memory to fit the extra int addsize.*/
{
    DataType* tempArray = new DataType [m_size];
    for (int i = 0; i < m_size; i++)
    {
        tempArray[i] = m_array[i];
    }
    delete [] m_array;
    m_maxsize += addsize;
    m_array = new DataType [m_maxsize];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = tempArray[i];
    }
}						//(18)
void ArrayList::trim()
/*Deallocates the dynamic memory pointed to by m_array and allocates enough total memory to
 just fit the current amount of m_size.*/
{
    DataType* tempArray = new DataType [m_size];
    for (int i = 0; i < m_size; i++)
    {
        tempArray[i] = m_array[i];
    }
    delete [] m_array;
    m_maxsize = m_size;
    m_array = new DataType [m_maxsize];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = tempArray[i];
    }
}
