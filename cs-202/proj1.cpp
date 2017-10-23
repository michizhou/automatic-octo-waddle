/* Michael Zhou, Project 1, CS 202 Section 1102 */
/* The input for the program is a certain input file that lists the first names of students in an unsorted order. All the names in the file start with a capital letter, and only the first ten names are read */
/* The output of the program is two lists, the first which lists the unsorted names read in from the input file in their order read while the second lists the same first ten names sorted in alphabetical order. The program also puts the sorted list of names to an output file */
 
#include <iostream>
#include <fstream>

using namespace std;

const int NUM_OF_STUDENTS = 10;  //number of student names read in as input
const int STR_SIZE = 20;  //maximum string size of character arrays

char names[NUM_OF_STUDENTS][STR_SIZE];  //2D array for storing student names
char temp[STR_SIZE];  //array for temporary strings from strcpy()

void bubblesort(char[][STR_SIZE]);
void print_names(char[][STR_SIZE]);
void strcpy(char[],char[]);
int strcmp(char[],char[]);
int main()
{
  ifstream inFile;   //input stream variable
  ofstream outFile;  //output stream variable

  char inpfile[STR_SIZE];  //name of input file as a character array
  char otpfile[STR_SIZE];  //name of output file as a character array

  //reads in file names of input and output files from command line
  cout << "Please enter the name of input file: " << endl;
  cin >> inpfile;
  cout << "Please enter the name of output file: " << endl;
  cin >> otpfile;

  //opens input file for reading and output file for writing
  inFile.open(inpfile);
  outFile.open(otpfile);

  //prints the first ten unsorted names of the input file in the order read
  cout << "Unsorted Names: " << endl;
  cout << "==============" << endl;
  for (int i = 0; i < NUM_OF_STUDENTS; i++)
    {
      inFile >> names[i];
    }
  print_names(names);
  
  //sorts the student names read in by alphabetical order
  bubblesort(names);

  //prints the first ten names of the input file in sorted order to terminal
  cout << "Sorted Names: " << endl;
  cout << "==============" << endl;
  print_names(names);

  //prints sorted names read from the input file to separate output file
  for (int i = 0; i < NUM_OF_STUDENTS; i++)
    {
      outFile << names[i] << endl;
    }

  //closes input and output files
  inFile.close();
  outFile.close();

  return 0;
}
void bubblesort(char names[][STR_SIZE])
/*Given a two-dimensional character array listing names, bubblesort will sort 
  the separate name character arrays in alphabetical order, passing through 
  the list of name arrays (rows) and swapping two names if out of order.*/
{
  for (int i = 0; i < NUM_OF_STUDENTS-1; i++)
    {
      for (int j = 0; j < NUM_OF_STUDENTS-(i+1); j++)
        {
          if (strcmp(names[j],names[j+1]) > 0)
            {
              strcpy(temp,names[j]);
              strcpy(names[j],names[j+1]);
              strcpy(names[j+1],temp);
            }
        }
    }
}
void print_names(char names[][STR_SIZE])
/*Given a two-dimensional character array listing names, print_names will print
  the names arrays, giving each their own row before moving to the next line.*/
{
  for (int i = 0; i < NUM_OF_STUDENTS; i++)
    {    
      cout << names[i] << endl;
    }
  cout << endl;
}
void strcpy(char dest[],char src[])
/*Given a source character array and destination character array, strcpy will 
  copy the characters of the source array into the destination array.*/ 
{
  int i = 0;  //position of current character from source array
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}
int strcmp(char first[], char sec[])
/*Given two different character arrays, strcmp will compare characters of the 
  same positions with each other to determine whether the character arrays are
  different or similar. Returns numerical value if different or zero if same.*/
{
  int i = 0;      //position of characters being compared in both strings
  int value = 0;  //value that represents difference between strings
  while (first[i] != '\0' || sec[i] != '\0')
    {
      if (first[i]-sec[i] != 0)
        {
          value = first[i]-sec[i];
          return value;
        }
      i++;
    }
  return value;
}
