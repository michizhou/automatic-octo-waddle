/* Michael Zhou, Project 5, CS 202 Section 1102 */
/* The input for the program is the many calls to the MyString constructors that result in the instantiation of various new MyString objects that are meant to demonstrate the proper functionalities of the MyString class according to the specifications for its private and public member functions */
/* The output of the program is a sequence of output statements that are printed to the terminal to display the various parameters of their respective calling member functions such as the string size, length, and parts of the character arrays of a MyString object's C-string representation to show proper functionality.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyString.h"

using namespace std;

int main() {
    //(1)
    MyString ms_default();
    cout << ms_default << endl;
    //(2)
    MyString ms_parameterized("Welcome to my brave new world!");
    cout << ms_parameterized << endl;
    //(3)
    MyString ms_copy(ms_parameterized);
    cout << ms_copy << endl;
    //(4)
    MyString* ms_Pt = new MyString("Sad world indeed...");
    delete ms_Pt;
    ms_Pt = NULL;
    //(5),(6)
    MyString ms_size_length("Welcome to our club!");
    cout << ms_size_length.size() << endl;
    cout << ms_size_length.length() << endl;
    //(7)
    MyString ms_toCstring("Kneel before your new emperor you rubes!");
    cout << ms_toCstring.c_str() << endl;
    //(8)
    MyString ms_same1("Maverick"), ms_same2("Maverick");
    if (ms_same1==ms_same2)
        cout << "Same success" << endl;
    MyString ms_different("MaVericK");
    if (!(ms_same1==ms_different))
        cout << "Different success" << endl;
    //(9)
    MyString ms_assign("Before first phase");
    ms_assign = MyString("After brainwashing is complete");
	 cout << ms_assign << endl;
    //(10)
    MyString ms_append1("The cake");
    MyString ms_append2(" is a LIE!!");
    MyString ms_concat = ms_append1+ ms_append2;
	 cout << ms_concat << endl;
    //(11)
    MyString ms_access("Cleared for takeoff (NOT)");
    ms_access[19] = 0;
    
    MyString test1("Hello");
    MyString test2("world");
    cout << test1 + test2 <<endl;
    
    MyString test3("");
    MyString test4("");
    cout << "11" << endl;
    cout << test3 + test4 << endl;
    
    test1 = test1;
    cout << test1 << endl;
    cout << "12" << endl;
    //12
    cout << ms_access << endl;
    
    return 0;
}
