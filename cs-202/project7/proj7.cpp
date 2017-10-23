/* Michael Zhou, Project 7, CS 202 Section 1102 */
/* The input for the program is the many calls to the ArrayQueue and NodeQueue constructors that result in the instantiation of various new ArrayQueue and NodeQueue objects that are meant to demonstrate the proper functionalities of the ArrayQueue and NodeQueue classes according to specifications for their member functions with the format of templated classes and functions generalized for all types of data. */
/* The output of the program is a sequence of output statements that are printed to the terminal to display the various parameters of their respective calling member functions such as the first and last elements, size, and elements before or after the pushing or popping of another value into an ArrayQueue or NodeQueue object to show proper functionality of all member functions.*/
#include <iostream>

#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main(){
    //(1)
    ArrayQueue<DataType> aq_default;
    cout << aq_default << endl;
    NodeQueue<DataType> nq_default;
    cout << nq_default << endl;
    //(2)
    DataType def_value1(3000, 250.0);
    DataType def_value2(300, 25.0);
    ArrayQueue<DataType> aq_parameterized(5, def_value1);
    cout << aq_parameterized << endl;
    NodeQueue<DataType> nq_parameterized(5, def_value2);
    cout << nq_parameterized << endl;
    //(3)
    ArrayQueue<DataType> aq_copy(aq_parameterized);
    cout << aq_copy << endl;
    NodeQueue<DataType> nq_copy(nq_parameterized);
    cout << nq_copy << endl;
    //(4)
    DataType null_value(0, 0.0);
    ArrayQueue<DataType>* aq_Pt = new ArrayQueue<DataType>(5, null_value);
    NodeQueue<DataType>* nq_Pt = new NodeQueue<DataType>(5, null_value);
    delete aq_Pt;
    aq_Pt = NULL;
    delete nq_Pt;
    nq_Pt = NULL;
    //(5)
    DataType assign_value(840, 60.0), access_value(30, 10.0), in_value(120, 25.0);
    ArrayQueue<DataType> aq_assign(6, assign_value), newarr(6, in_value);
	 aq_assign = newarr;
    cout << aq_assign << endl;
    ArrayQueue<DataType> aq_access(6, access_value);
    cout << aq_access << endl;
    
    NodeQueue<DataType> nq_assign(6, assign_value), newmod(6, in_value);
	 nq_assign = newmod;
    cout << nq_assign << endl;
    NodeQueue<DataType> nq_access(6, access_value);
    cout << nq_access << endl;
    //(6),(7)
    ArrayQueue<DataType> aq_first_element(aq_assign), aq_last_element(aq_assign);
    if (!aq_first_element.empty())
    {
        DataType print_first = aq_first_element.front();
        cout << print_first << endl;
    }
    if (!aq_last_element.empty())
    {
        DataType print_last = aq_last_element.back();
        cout << print_last << endl;
    }
    
    NodeQueue<DataType> nq_first_element(nq_assign), nq_last_element(nq_assign);
    if (!nq_first_element.empty())
    {
        DataType print_fnode = nq_first_element.front();
        cout << print_fnode << endl;
    }
    if (!nq_last_element.empty())
    {
        DataType print_lnode = nq_last_element.back();
        cout << print_lnode << endl;
    }
    //(8),(9)
    aq_assign.push(in_value);
    cout << aq_assign.back() << endl;
    nq_assign.push(in_value);
    cout << nq_assign.back() << endl;
    
    aq_assign.pop();
    cout << aq_assign.front() << endl;
    nq_assign.pop();
    cout << nq_assign.front() << endl;
    //(10)
    ArrayQueue<DataType> aq_size(1000, assign_value);
    cout << aq_size.size() << endl;
    NodeQueue<DataType> nq_size(8, assign_value);
    cout << nq_size.size() << endl;
    //(11),(12),(13)
    cout << boolalpha << aq_size.full() << endl;
    aq_access.clear();
    cout << boolalpha << aq_access.empty() << endl;
    
    cout << boolalpha << nq_access.full() << endl;
    nq_access.clear();
    cout << boolalpha << nq_access.empty() << endl;
    
    aq_assign.clear();
    nq_assign.clear();
    aq_parameterized.clear();
    nq_parameterized.clear();
    aq_copy.clear();
    nq_copy.clear();
    aq_first_element.clear();
    nq_first_element.clear();
    aq_last_element.clear();
    nq_last_element.clear();
    
    return 0;
}
