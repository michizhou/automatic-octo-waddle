/* Michael Zhou, Project 3, CS 202 Section 1102 */
/* The input for the program is a certain input file that lists all the data for a list of agencies in an unsorted order. The data for each agency includes its name, zipcode, and inventory of car objects. Each of these car objects includes the car's year, make, model, rental price per day, and availability */
/* The output of the program is an interactive menu, which lists six options for the user to select from to perform certain actions. These actions include reading the data, printing the data, estimating the cost to rent a certain car from a certain agency, finding the most expensive car, and printing only available cars from all agencies. Once a user selects an option, the program will execute the action and print out the relevant data if needed. The program also puts the list of agencies and all their data to an output file */

#include <iostream>
#include <fstream>

using namespace std;

void strcpy(char*,char*);
int strcmp(char*,char*);

//Class for storing all data members for an individual car and associated functions that manipulate car data
class RentalCar {
    private:
    int m_year;			//individual car's year
    char m_make[20];    //individual car's make
    char m_model[20];   //individual car's model
    float m_price;      //individual car's rental price
    bool m_available;	//individual car's availability
    
    public:
    void CarCon();
    void CarCon(int, char *, char *, float, bool);
    
    //Primary get methods
    int getYear();
    char* getMake();
    char* getModel();
    float getPrice();
    bool getAvailable();
    
    //Primary set methods
    bool SetYear(int newyear);
    bool SetMake(char* newmake);
    bool SetModel(char* newmodel);
    bool SetPrice(float newprice);
    bool SetAvailable(bool newavail);
    
    void PrintCars(RentalCar*,ofstream&);
    float EstimateCost(RentalCar*,int);
};

void RentalCar::CarCon()
//Default constructor that sets the data members for a RentalCar object to default initial values.
{
    m_year = 0;
    strcpy(m_make, "blank");
    strcpy(m_model, "blank");
    m_price = 0.0;
    m_available = false;
}

void RentalCar::CarCon(int startYear, char* startMake, char* startModel, float startPrice, bool startAvail)
/*Parameterized constructor that will create a new RentalCar object based on the values for the RentalCar's
 initial year, make, model, rental price, and availability*/
{
    m_year = startYear;
    strcpy(m_make, startMake);
    strcpy(m_model, startModel);
    m_price = startPrice;
    m_available = startAvail;
}
int RentalCar::getYear()
//Returns the current value for an individual car's year
{
    return m_year;
}
char* RentalCar::getMake()
//Returns the current value for an individual car's make
{
    return m_make;
}
char* RentalCar::getModel()
//Returns the current value for an individual car's model
{
    return m_model;
}
float RentalCar::getPrice()
//Returns the current value for an individual car's rental price per day
{
    return m_price;
}
bool RentalCar::getAvailable()
//Returns the current value for an individual car's availability
{
    return m_available;
}
bool RentalCar::SetYear(int newYear)
/*Given the new value for a car's year, SetYear will set the current value
 for a car's year to the new value.*/
{
    if (newYear > 0)
    {
        m_year = newYear;
        return true;
    }
}
bool RentalCar::SetMake(char* newMake)
/*Given the new value for a car's make, SetModel will set the current value
 for a car's make to the new value using strcpy().*/
{
    strcpy(m_make,newMake);
    return true;
}
bool RentalCar::SetModel(char* newModel)
/*Given the new value for a car's model, SetModel will set the current value
 for a car's model to the new value using strcpy().*/
{
    strcpy(m_model,newModel);
    return true;
}
bool RentalCar::SetPrice(float newPrice)
/*Given the new value for a car's rental price per day, SetPrice will set
 the value for a car's rental price to the new value.*/
{
    if (newPrice > 0.0)
    {
        m_price = newPrice;
        return true;
    }
}
bool RentalCar::SetAvailable(bool newAvail)
/*Given the new value for a car's availability, SetAvailable will set the
 value for a car's availability to the new value.*/
{
    m_available = newAvail;
    return true;
}
void RentalCar::PrintCars(RentalCar* carPtr, ofstream &outFile)
/*Given the pointer to an individual car's data and output stream variable,
 PrintCars will print out all the data for a car to both the terminal and
 a separate output file.*/
{
    cout << carPtr->getYear() << " " << carPtr->getMake() << " "
         << carPtr->getModel() << " $" << carPtr->getPrice() << " per day ";
    cout << "Available: " << boolalpha << carPtr->getAvailable() << endl;
    outFile << carPtr->getYear() << " " << carPtr->getMake() << " "
            << carPtr->getModel() << " $" << carPtr->getPrice() << " per day ";
    outFile << "Available: " << boolalpha << carPtr->getAvailable() << endl;
}
float RentalCar::EstimateCost(RentalCar* carPtr, int totalDays)
/*Given the pointer to an individual car's data and the number of days that
 the car will be rented out, EstimateCost will calculate the total rental
 cost of the car and return the value.*/
{
    float value = 0.0;  //total value of rental costs for car
    value = carPtr->getPrice() * totalDays;
    return value;
}

//Struct for storing name, zipcode, and data for all cars of an agency
struct RentalAgency {
    char name[20];   //character array for storing name of agency
    int zipcode[5];  //int array for storing agency zipcode
    RentalCar inventory[5];  //inventory of all car objects of agency
};

RentalAgency agencies[3];   //array of structs storing all data for all rental agencies
RentalAgency* aptr = agencies;  //pointer that refers to array of structs for agency data

void callMenu(RentalAgency*,ifstream&,ofstream&);
void readIn(RentalAgency*,ifstream&);
void printData(RentalAgency*,ofstream&);
void rentalCost(RentalAgency*);
void carSearch(RentalAgency*);
void printAvail(RentalAgency*,ofstream&);
bool exitProg();
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
    callMenu(aptr,inFile,outFile);
    
    //closes input file
    inFile.close();
    
    return 0;
}
void callMenu(RentalAgency *aptr, ifstream &inFile, ofstream &outFile)
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
                readIn(aptr,inFile);
                break;
            case 2:
                printData(aptr,outFile);
                break;
            case 3:
                rentalCost(aptr);
                break;
            case 4:
                carSearch(aptr);
                break;
            case 5:
                printAvail(aptr,outFile);
                break;
            case 6:
                doneStatus = exitProg();
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
        }
    } while (doneStatus != true);
}
void readIn(RentalAgency *aptr, ifstream &inFile)
/*Given the array of structs with data from all agencies, like car data,
 the input stream variable, and the counter for number of cars read, readIn
 will read in all the data for cars from the input file.*/
{
    int i;  //loop counter for iterations over agencies, cars, and zipcodes
    int tempYear;  //temporary character storing car year
    char tempMake[20];   //temporary character array storing car make
    char tempModel[20];  //temporary character array storing car model
    float tempPrice;  	 //temporary value for storing car price
    bool tempAvail;		 //temporary value for storing car availability
    aptr = agencies;     //pointer for RentalAgency array with agency data
    RentalCar* carPtr = aptr->inventory;  //pointer for a car's data
    int* iptr = aptr->zipcode;  //pointer for current integer of zipcode
    for (int i = 0; i < 3; i++)
    {
        inFile >> aptr->name;
        inFile.get();
        for (int i = 0; i < 5; i++)
        {
            *iptr = inFile.get() - '0';
            iptr++;
        }
        for (int i = 0; i < 5; i++)
        {
            inFile >> tempYear >> tempMake >> tempModel
                   >> tempPrice >> tempAvail;
            carPtr->SetYear(tempYear);
            carPtr->SetMake(tempMake);
            carPtr->SetModel(tempModel);
            carPtr->SetPrice(tempPrice);
            carPtr->SetAvailable(tempAvail);
            carPtr++;
        }
        aptr++;
        carPtr = aptr->inventory;
        iptr = aptr->zipcode;
    }
}
void printData(RentalAgency *aptr, ofstream &outFile)
/*Given the array of structs with data from all agencies, like car data,
 printData will print out all data for all the cars. The function will
 also write all the data to a separate output file.*/
{
    outFile.open("AllAgenciesAllCars.txt");
    int i, j;  //loop counters for iterations over agencies, cars, zipcodes
    aptr = agencies;     //pointer for RentalAgency array with agency data
    RentalCar* carPtr = aptr->inventory;  //pointer for a car's data
    int* iptr = aptr->zipcode;  //pointer for current integer of zipcode
    for (int i = 0; i < 3; i++)
    {
        cout << aptr->name << " ";
        for (int i = 0; i < 5; i++)
        {
            cout << *iptr;
            iptr++;
        }
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            carPtr->PrintCars(carPtr,outFile);
            carPtr++;
        }
        cout << endl;
        aptr++;
        carPtr = aptr->inventory;
        iptr = aptr->zipcode;
    }
    outFile.close();
}
void rentalCost(RentalAgency *aptr)
/*Given the array of structs with data from all agencies, like car data,
 rentalCost will prompt the user for agency name, a car number, and the
 number of days to rent the car. Estimates rental cost based on inputs.*/
{
    char agencyName[5];  	 //name of car agency from input
    int carNum;     //car number from user input
    aptr = agencies;     //pointer for RentalAgency array with agency data
    RentalCar* carPtr;    	 //pointer to car number in agency inventory
    int count = 1;  //counter for current car number in agency list
    int totalDays;  //total number of days to rent the car
    float totalCost = 0.0;  //total car rental cost
    
    cout << "Please enter name of rental agency from the following (case-sensitive): " << endl;
    cout << agencies[0].name << " " << agencies[1].name << " " << agencies[2].name << endl;
    cin >> agencyName;
    cout << "Please enter the number of the rental car: " << endl;
    cin >> carNum;
    cout << "Enter number of days you want to rent the car: " << endl;
    cin >> totalDays;
    
    while (strcmp(agencyName,aptr->name) != 0)
    {
        aptr++;
    }
    carPtr = aptr->inventory;
    while (count != carNum)
    {
        carPtr++;
        count++;
    }
    totalCost = carPtr->EstimateCost(carPtr,totalDays);
    cout << "Total Estimated Rental Cost: $" << totalCost << endl;
}
void carSearch(RentalAgency* aptr)
/*Given the array of structs with data from all agencies, like car data, and
 the pointer to the array of RentalAgency structs, carSearch will find and
 print out the most expensive car from all the agencies.*/
{
    int i, j;  //loop counters for iterations over RentalAgencies and RentalCars
    aptr = agencies;  //pointer for RentalAgency array with agency data
    RentalCar* maxPtr = aptr->inventory;  //pointer to most expensive price car
    RentalCar* curPtr = aptr->inventory;  //pointer to current car being read
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (curPtr->getPrice() > maxPtr->getPrice())
            {
                maxPtr = curPtr;
            }
            curPtr++;
        }
        aptr++;
        curPtr = aptr->inventory;
    }
    cout << "Most Expensive Car: " << maxPtr->getYear() << " " << maxPtr->getMake()
    << " " << maxPtr->getModel() << " $" << maxPtr->getPrice() << " per day ";
    cout << "Available: " << boolalpha << maxPtr->getAvailable() << endl;
}
void printAvail(RentalAgency *aptr, ofstream &outFile)
/*Given the array of structs with data from all agencies, like car data, and
 the pointer to the array of RentalAgency structs, printAvail will print only
 the available cars. It also writes data for available cars to an output file.*/
{
    outFile.open("AllAgenciesAvailableCars.txt");
    int i, j;  //loop counters for iterations over RentalAgencies and RentalCars
    aptr = agencies;  //pointer for RentalAgency array with agency data
    RentalCar *carPtr = aptr->inventory;  //pointer for a car's data
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (carPtr->getAvailable() == 1)
            {
                carPtr->PrintCars(carPtr,outFile);
            }
            carPtr++;
        }
        aptr++;
        carPtr = aptr->inventory;
    }
    outFile.close();
}
bool exitProg()
//Terminates and exits the program and interactive menu based on user input
{
    return true;
}
void strcpy(char* dest, char* src)
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
            value = *first-*sec;
            return value;
        }
        first++;
        sec++;
    }
    return value;
}
