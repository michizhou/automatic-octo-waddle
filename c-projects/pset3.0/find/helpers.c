/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdbool.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */    
bool search(int value, int values[], int n)
{
    int Begin = 0;
    int End = n - 1;
    
    while (Begin <= End)
    {
        int mid = (Begin + End)/2;         
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] > value)
        {
            End = mid - 1;
        }
        else
        {
            Begin = mid + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int small = values[i];
        int small_locate = i;
        for (int j = i + 1; j < n; j++)
        {
            if (small > values[j])
            {
                small = values[j]; 
                small_locate = j;
            }    
        }  
        values[small_locate] = values[i];
        
        values[i] = small;
    }
    return;
}
