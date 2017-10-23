#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

template <class T>
void vector_resort(std::vector<T> &vecNum, int first, int last)
/*Given a std::vector passed by-Reference and the indices of its first and last elements, vector_resort will
  perform recursive sorting of the vector elements through the Quicksort algorithm.*/
{
    if (first < last)
    {
        T pivot = vecNum[first];    //reference pivot value for sorting
        int leftside = first + 1;   //marker for the left index element
        int rightside = last;       //marker for the right index element
        bool fin = false;           //variable indicating if right index is less than left index
        while (!fin)
        {
            while (leftside <= rightside && vecNum[leftside] <= pivot)
            {
                leftside = leftside + 1;
            }
            while (rightside >= leftside && vecNum[rightside] > pivot)
            {
                rightside = rightside - 1;
            }
            if (rightside < leftside)
            {
                fin = true;
            }
            else
            {
                T temp1 = vecNum[leftside];     //temporary variable for storing left index element
                vecNum[leftside] = vecNum[rightside];
                vecNum[rightside] = temp1;
            }
        }
        T temp2 = vecNum[first];    //temporary variable for storing left index element
        vecNum[first] = vecNum[rightside];
        vecNum[rightside] = temp2;
        vector_resort<T>(vecNum,first,rightside - 1);
        vector_resort<T>(vecNum,rightside + 1,last);
    }
}
template <class T>
int vector_research(std::vector<T> &sorted_vecNum, const T& target, int low, int high)
/*Given a sorted std::vector passed by-Reference, the indices of its first and last elements, and a target
  value, vector_research will perform recursive binary search until the target value is found. The function 
  will then return the index where the target value is found, returning -1 if the item is not found.*/
{
    if (low < high)
    {
        int middle = (low + high)/2;        //index for the middle element
        T pivot = sorted_vecNum[middle];    //reference pivot value for searching
        if (target == pivot)
        {
            return middle;
        }
        else if (target < pivot)
        {
            return vector_research<T>(sorted_vecNum,target,low,middle - 1);
        }
        else
        {
            return vector_research<T>(sorted_vecNum,target,middle + 1,high);
        }
    }
    return -1;
}
