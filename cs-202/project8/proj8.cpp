/* Michael Zhou, Project 8, CS 202 Section 1102 */
/* The input for the program is an input data file filled with an assortment of random integer values that are 
   meant to become values for a vector object of ints. Each of the values is read from the file through the
   input stream variable into a temporary variable, from which each vector element is assigned a value.*/
/* The output of the program is the elements of the vector object, which are sorted, and the elements of a copy
   vector object that is a copy of the initially unsorted vector object. The elements of the copy vector are
   first printed out with one per line, followed by the sorted vector elements in order in rows of ten. The 
   value of the index with the target value specified in the binary search function call is also displayed.*/
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#include "VectorRecursion.h"

using namespace std;

int main() {
    ifstream inFile;
    
    inFile.open("RandomData.txt");
    
    std::vector<int> vecInt(100);
    int inputNum;   //individual input value in vector
    for (int i = 0; i < 100; i++)
    {
        inFile >> inputNum;
        vecInt[i] = inputNum;
    }
    std::vector<int> vecIntCpy(vecInt);
    for (int i = 0; i < 100; i++)
    {
        cout << vecIntCpy[i] << endl;
    }
    cout << endl;
    vector_resort<int>(vecInt, 0, vecInt.size()-1);
    for (int i = 0; i < 100; i++)
    {
        if ((i+1) > 1 && (i+1) % 10 == 1)
        {
            cout << endl;
        }
        cout << vecInt[i] << " ";
    }
    cout << endl << endl;
    int value = vector_research<int>(vecInt, 144, 0, vecInt.size()-1);  //index of target value
    cout << value << endl;
    
    inFile.close();
    
    return 0;
}
