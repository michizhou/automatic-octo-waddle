/* Michael Zhou, Project 2, CS 202 Section 1102 */
/* The input for the program is a certain input file that lists all the data for a list of cars in an unsorted order. The data for each car includes its year, make, model, rental price per day, and availability */
/* The output of the program is an interactive menu, which lists six options for the user to select from to perform certain actions. These actions include reading the data, printing the data, estimating the cost to rent a certain car, finding the most expensive car, and printing only available cars. Once a user selects an option, the program will execute the action and print out the relevant data if needed. The program also puts the list of cars and all their data to an output file */

#include <iostream>
#include <fstream>

using namespace std;

//struct for storing all the data for each individual car
struct RentalCar {
    char make[20];
    char model[20];
    int year;
    float price;
    bool avail;
};

const int NUM_OF_CARS = 1000;  //maximum number of cars that can be read by program

RentalCar cars[NUM_OF_CARS];   //array of structs storing all the data for the list of cars

void callMenu(RentalCar[],ifstream&,int&,ofstream&);
void readIn(RentalCar[],ifstream&,int&);
void printData(RentalCar[],int,ofstream&);
void rentalCost(RentalCar[]);
void carSearch(RentalCar[],int);
void printAvail(RentalCar[],int,ofstream&);
bool exitProg();
int main()
{
    ifstream inFile;   //input stream variable
    ofstream outFile;  //output stream variable
    
    char inpfile[20];  //name of input file as a character array
    int count = 0;     //counter for total number of cars read in as input
    
    //reads in file names of input and output files from command line
    cout << "Please enter the name of your input file: " << endl;
    cin >> inpfile;
    
    //opens input file for reading
    inFile.open(inpfile);
    
    //calls for the interactive menu to be displayed on screen and receive user input
    callMenu(cars,inFile,count,outFile);
    
    //closes input file
    inFile.close();
    
    return 0;
}
void callMenu(RentalCar cars[], ifstream &inFile, int &count, ofstream &outFile)
/*Prints out the interactive menu with a list of options that allow for user 
  input. Based on the option that the user selects, callMenu will call upon
  the appropriate separate function to carry out the action requested.*/
{
    int menuOption;  //number of menu option selected by user input
    bool doneStatus = false;  //variable that determines exit from program
    
    do {
        cout << "Menu Options" << endl;
        cout << "==============" << endl;
        cout << "Option 1: Read All Data From File" << endl;
        cout << "Option 2: Print Out All Car Data" << endl;
        cout << "Option 3: Estimate Car Rental Cost" << endl;
        cout << "Option 4: Find Most Expensive Car" << endl;
        cout << "Option 5: Print Out Available Cars" << endl;
        cout << "Option 6: Exit the Program" << endl;
        cout << "Select an option by entering its number: " << endl;
        cin >> menuOption;
        
        switch (menuOption)
        {
            case 1:
                readIn(cars,inFile,count);
                break;
            case 2:
                printData(cars,count,outFile);
                break;
            case 3:
                rentalCost(cars);
                break;
            case 4:
                carSearch(cars,count);
                break;
            case 5:
                printAvail(cars,count,outFile);
                break;
            case 6:
                doneStatus = exitProg();
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
        }
    } while (doneStatus != true);
}
void readIn(RentalCar cars[], ifstream &inFile, int &count)
/*Given the array of structs with all car data, the input stream variable,
  and the counter for number of cars read, readIn will read in all the data 
  for cars in the input file. For every car read, the counter is updated.*/
{
    while (!inFile.eof())
    {
        inFile >> cars[count].year >> cars[count].make >> cars[count].model
               >> cars[count].price >> cars[count].avail;
        count++;
    }
}
void printData(RentalCar cars[], int count, ofstream &outFile)
/*Given the array of structs with all car data and the total number of cars
  read from the file, printData will print out all data for all the cars.
  The function will also write all the data to a separate output file.*/
{
    outFile.open("AllCars.txt");
    for (int i = 0; i < count-1; i++)
    {
        cout << cars[i].year << " " << cars[i].make << " "
             << cars[i].model << " $" << cars[i].price << " per day ";
        outFile << cars[i].year << " " << cars[i].make << " "
                << cars[i].model << " $" << cars[i].price << " per day ";
        if (cars[i].avail == 1)
        {
            cout << "Available: true" << endl;
            outFile << "Available: true" << endl;
        }
        else
        {
            cout << "Available: false" << endl;
            outFile << "Available: false" << endl;
        }
    }
    outFile.close();
}
void rentalCost(RentalCar cars[])
/*Given the array of structs with all car data, rentalCost will prompt the
  user for a car number and the number of days to rent the car. It will
  then estimate the car rental cost based on the inputs.*/
{
    int carNum;     //car number from user input
    int totalDays;  //total number of days to rent the car
    float totalCost = 0.0;  //total car rental cost

    cout << "Please enter the number of the rental car: " << endl;
    cin >> carNum;
    cout << "Enter number of days you want to rent the car: " << endl;
    cin >> totalDays;
    
    totalCost = cars[carNum-1].price * totalDays;
    cout << "Total Estimated Rental Cost: $" << totalCost << endl;
}
void carSearch(RentalCar cars[], int count)
/*Given the array of structs with all car data and the total number of cars
  read from the file, carSearch will find and print the most expensive car.*/
{
    int max = 0;  //index of car with most expensive price
    for (int i = 0; i < count; i++)
    {
        if (cars[i].price > cars[max].price)
        {
            max = i;
        }
    }
    cout << "Most Expensive Car: " << cars[max].year << " " << cars[max].make
			 << " " << cars[max].model << " $" << cars[max].price << " per day ";
    if (cars[max].avail == 1)
    {
        cout << "Available: true" << endl;
    }
    else
    {
        cout << "Available: false" << endl;
    }
}
void printAvail(RentalCar cars[], int count, ofstream &outFile)
/*Given the array of structs with all car data and the total number of cars
  read from the file, printAvail will print out only the available cars.
  The function will also write data for available cars to an output file.*/
{
    outFile.open("AvailableCars.txt");
    for (int i = 0; i < count; i++)
    {
        if (cars[i].avail == 1)
        {
            cout << cars[i].year << " " << cars[i].make << " "
                 << cars[i].model << endl;
            outFile << cars[i].year << " " << cars[i].make << " "
                    << cars[i].model << endl;
        }
    }
    outFile.close();
}
bool exitProg()
//Terminates and exits the program and interactive menu based on user input
{
    return true;
}
