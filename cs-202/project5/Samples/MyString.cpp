#include <iostream>

#include "MyString.h"

MyString::MyString(){

}

MyString::MyString(const char* str){

}

MyString::MyString(const MyString& other_myStr){

}

MyString::~MyString(){

}

int MyString::size() const{

  return 0; //dummy
}

int MyString::length() const{

  return 0; //dummy
}

const char* MyString::c_str() const{

  return NULL; //dummy
}

bool MyString::operator==( const MyString& other_myStr) const{

  return false; //dummy
}

MyString& MyString::operator=(const MyString& other_myStr){

  return *this; //dummy
}

MyString& MyString::operator+(const MyString& other_myStr){

  return *this; //dummy
}

char& MyString::operator[] (int position){

  return *m_buffer; //dummy
}

const char& MyString::operator[] (int position) const{

  return *m_buffer; //dummy
}

void MyString::buffer_deallocate(){

}

void MyString::buffer_allocate(int size){

}

std::ostream& operator<<(std::ostream& os, const MyString& myStr){

  return os;
}
