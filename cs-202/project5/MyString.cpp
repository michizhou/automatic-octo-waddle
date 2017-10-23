//Necessary include(s)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyString.h"

using namespace std;

MyString::MyString()
//Default constructor which instantiates a new MyString objwect with no valid data
{
    m_buffer = NULL;
    m_size = 0;
}
MyString::MyString(const char* str)
/*Parameterized constructor which instantiates a new MyString object which will be
  initialized to hold a copy of the C-string str passed as a parameter*/
{
    m_buffer = NULL;
    m_size = strlen(str);
    buffer_allocate(m_size);
    strcpy(m_buffer,str);
}
MyString::MyString(const MyString& other_myStr)
/*Copy constructor which instantiates a new MyString object which will be a separate
  copy of the data of the other_myStr object which is getting copied*/
{
    m_buffer = NULL;
    m_size = other_myStr.m_size;
    buffer_allocate(m_size);
    strcpy(m_buffer,other_myStr.m_buffer);
}
MyString::~MyString()
//Destructor which destroys the instance of the MyString object
{
    buffer_deallocate();
    m_buffer = NULL;
}
int MyString::size() const
//Returns the size of the currently allocated char buffer
{
    return m_size;
}
int MyString::length() const
//Returns the size of the string without counting the null-terminating character
{
    return m_size - 1;
}
const char* MyString::c_str() const
/*Returns a pointer to a char array which represents the C-string equivalent of the
  calling MyString object's data*/
{
    return m_buffer;
}
bool MyString::operator== (const MyString& other_myStr) const
/*Given a MyString object other_myStr, the overloaded operator== will check if the
  calling object represents the same string as the other_myStr object. Returns true
  if yes, or false if not.*/
{
    if (strcmp(m_buffer,other_myStr.m_buffer) != 0 || m_size != other_myStr.m_size)
    {
        return false;
    }
    return true;
}
MyString& MyString::operator= (const MyString& other_myStr)
/*Given a MyString object other_myStr, the overloaded operator= will assign a new
  value to the calling object's string data, based on the data of other_myStr object.
  Returns a reference to the calling object to be used for cascading operator=.*/
{
    if (this != &other_myStr)
    {
        m_buffer = NULL;
        m_size = other_myStr.m_size;
        buffer_allocate(m_size);
        strcpy(m_buffer,other_myStr.m_buffer);
    }
    return *this;
}
MyString& MyString::operator+ (const MyString& other_myStr)
/*Given a MyString object other_myStr, the overloaded operator+ will assign a new
  value to the calling object's string data, which will be the result of appending
  the other_myStr object's data to the orginial calling object's data. Returns a 
  reference to the calling object to be used for cascading operator=.*/
{
    int totalLength = this->length() + other_myStr.size();  //total length of new buffer
    char * tempBuf = new char [totalLength];  //character array allocated to new buffer
    strcpy(tempBuf,m_buffer);
    int counter = 0;  //counter indicating current character of other string's buffer 
    for (int i = this->length(); i < totalLength; ++i)
    {
        tempBuf[i] = other_myStr.m_buffer[counter++];
    }
    tempBuf[totalLength-1] = 0;
    buffer_allocate(totalLength);
    strcpy(m_buffer,tempBuf);
    return *this;
}
char& MyString::operator[] (int position)
/*Given an index value, the overloaded operator[] will allow by-reference accessing
  of a specific character at index position within the allocated m_buffer char array.*/
{
    return m_buffer[position];
}
ostream& operator<< (ostream& os, const MyString& myStr)
/*Given an output stream variable and a MyString object myStr, the overloaded operator<<
  will output to the terminal or file, depending on the type of ostream& os object passed
  as a parameter to it, the MyString data. Returns the output stream variable.*/
{
    os << myStr.c_str();
    return os;
}
void MyString::buffer_allocate(int size)
/*Given a value for the size of a buffer, buffer_allocate will allocate the required
  size of char array and point m_buffer to it. Also checks whether there is an already
  allocated space for m_buffer and properly deallocate it prior to reallocating the new
  memory required. Updates m_size which keeps track of m_buffer with each call.*/
{
    if (m_buffer != NULL)
    {
        delete [] m_buffer;
    }
    m_buffer = new char [size];
    m_size = size;
}
void MyString::buffer_deallocate()
/*Deallocates the dynamic memory pointed to by m_buffer while also making sure to update
  the m_size which keeps track of m_buffer.*/
{
    if (m_buffer != NULL)
    {
        delete [] m_buffer;
        m_buffer = NULL;
    }
    m_size = 0;
}

void strcpy(char* dest, const char* src)
/*Given a source character array pointer and destination character array pointer,
 strcpy will copy the characters of the source array into the destination array.*/
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
int strcmp(char* first, char* sec)
/*Given two different character array pointers, strcmp will compare characters of the
 same positions with each other to determine whether the character arrays are different
 or similar. Returns numerical value if different or zero if same.*/
{
    int value = 0;  //value that represents difference between strings
    while (*first != '\0' || *sec != '\0')
    {
        if (*first - *sec != 0)
        {
            value = (*first)-(*sec);
            return value;
        }
        first++;
        sec++;
    }
    return value;
}
int strlen(const char* str)
/*Given a character array pointer for a certain string, strlen will calculate the total
  size of the character array that represents the string. Returns the total length of the
  character array with the null-terminating character included.*/
{
    int counter = 1;  //value that represents the total length of the string
    while (*str != 0)
    {
        counter++;
        str++;
    }
    return counter;
}
