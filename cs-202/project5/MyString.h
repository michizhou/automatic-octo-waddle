//Necessary preprocessor #define(s)
#ifndef MyString_h
#define MyString_h

//Necessary include(s)
#include <fstream>
#include <cstdlib>

using namespace std;

//C-style string helper functions
void strcpy(char*,const char*);
int strcmp(char*,char*);
int strlen(const char*);

//Class specifications for MyString member functions and variables
class MyString{
public:
    //Class constructors and destructor
    MyString(); //(1)
    MyString(const char* str); //(2)
    MyString(const MyString& other_myStr); //(3)
    ~MyString(); //(4)
    
    //Return value functions for string size, length, and C-string representation
    int size() const; //(5)
    int length() const; //(6)
    const char* c_str() const; //(7)
    
    //Overloaded class operators and friend function
    bool operator== (const MyString& other_myStr) const; //(8)
    MyString& operator= (const MyString& other_myStr); //(9)
    MyString& operator+ (const MyString& other_myStr); //(10)
    char& operator[] (int position); //(11)
    friend ostream& operator<<(ostream& os, const MyString& myStr); //(12)
private:
    //Buffer allocation and deallocation functions
    void buffer_deallocate();
    void buffer_allocate(int size);
    char *m_buffer;  //char-type pointer that points to the dynamically allocated data
    int m_size;      //int value that denotes number of characters allocated for m_buffer
};


#endif /* MyString_h */
