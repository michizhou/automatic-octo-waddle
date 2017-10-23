/* Michael Zhou, Project 4, CS 202 Section 1102 */
/* The input for the program is  */
/* The output of the program is  */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void strcpy(char*,char*);
int strcmp(char*,char*);

class CarSensor {
private:
    char m_type[20];
    float m_extracost;
    const static int gps_cnt = 0;
    const static int camera_cnt = 0;
    const static int lidar_cnt = 0;
    const static int radar_cnt = 0;
    
public:
    void SensCon();
    void SensCon(char *);
    void SensCpy(const CarSensor &initsensor);
    
    //Primary get methods
    char* GetType();
    float GetExtraCost();
    int GetGps();
    int GetCam();
    int GetLid();
    int GetRad();
    
    //Primary set methods
    bool SetType(char* newtype);
    bool SetExtraCost(float newextracost);

    void GetReset(int&, int&, int&, int&);
};
bool operator==(const CarSensor& lhs, const CarSensor& rhs);

void CarSensor::SensCon()
//Default constructor that sets the data members for a CarSensor object to default initial values.
{
    strcpy(m_type, '\0');
    m_extracost = 0.0;
}
void CarSensor::SensCon(char* startType)
/*Parameterized constructor that will create a new CarSensor object based on the values for the CarSensor's
 initial type, and the extra rental costs*/
{
    strcpy(m_type,startType);
    if (startType == "gps")
    {
        m_extracost = 5.0;
    }
    else if (startType == "camera")
    {
        m_extracost = 10.0;
    }
    else if (startType == "lidar")
    {
        m_extracost = 15.0;
    }
    else
    {
        m_extracost = 20.0;
    }
}
void CarSensor::SensCpy(const CarSensor &initsensor)
//Parameterized constructor that will create a new CarSensor object which duplicates an input CarSensor object
{
    CarSensor newsensor = initsensor;
    strcpy(m_type,newsensor.m_type);
    m_extracost = newsensor.m_extracost;
    gps_cnt = newsensor.gps_cnt;
    camera_cnt = newsensor.camera_cnt;
    lidar_cnt = newsensor.lidar_cnt;
    radar_cnt = newsensor.radar_cnt;
}
char* CarSensor::GetType()
//Returns the current value for an individual car's year
{
    return m_type;
}
float CarSensor::GetExtraCost()
//Returns the current value for an individual car's make
{
    return m_extracost;
}
int CarSensor::GetGps()
//Returns the current value for an individual car's model
{
    return gps_cnt;
}
int CarSensor::GetCam()
//Returns the current value for an individual car's model
{
    return camera_cnt;
}
int CarSensor::GetLid()
//Returns the current value for an individual car's rental price per day
{
    return lidar_cnt;
}
int CarSensor::GetRad()
//Returns the current value for an individual car's availability
{
    return radar_cnt;
}
bool CarSensor::SetType(char* newtype)
/*Given the new value for a car's year, SetYear will set the current value
 for a car's year to the new value.*/
{
    strcpy(m_type,newtype);
    return true;
}
bool CarSensor::SetExtraCost(float newextracost)
/*Given the new value for a car's make, SetModel will set the current value
 for a car's make to the new value using strcpy().*/
{
    if (newextracost > 0.0)
    {
        m_extracost = newextracost;
        return true;
    }
}
void CarSensor::GetReset(int &gps_cnt, int &camera_cnt, int &lidar_cnt, int &radar_cnt)
{
    gps_cnt = 0;
    camera_cnt = 0;
    lidar_cnt = 0;
    radar_cnt = 0;
}

bool operator== (CarSensor& lhs, CarSensor& rhs)
{
  if (strcmp(lhs.GetType(), rhs.GetType()) == 0)
    {
        if (lhs.GetExtraCost() == rhs.GetExtraCost())
        {
            if (lhs.GetGps() == rhs.GetGps())
            {
                if (lhs.GetCam() == rhs.GetCam())
                {
                    if (lhs.GetLid() == rhs.GetLid())
                    {
                        if (lhs.GetRad() == rhs.GetRad())
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }
}

//Class for storing all data members for an individual car and associated functions that manipulate car data
class RentalCar {
private:
    char m_make[20];     //individual car's make
    char m_model[20];    //individual car's model
    int m_year;    //individual car's year of production
    float m_tank;  //individual car's maximum tank capacity
    CarSensor m_sensors[3];  //individual car's sensors
    int m_senscnt;		 //individual car's total number of sensors
    float m_baseprice;   //rental price for sensorless vehicle
    float m_finalprice;  //rental price for vehicle with sensors
    bool m_available;	 //individual car's availability
    char m_owner[20];    //current lessee of the car
    
public:
    void CarCon();
    void CarCon(char *, char *, int, float, CarSensor *, float, float, bool, char *);
    void CarCpy(RentalCar &initcar);
    
    //Primary get methods
    char* GetMake();
    char* GetModel();
    int GetYear();
    float GetTank();
    CarSensor* GetSensors();
    int GetSenscnt();
    float GetBasePrice();
    float GetFinalPrice();
    bool GetAvailable();
    char* GetOwner();
    
    //Primary set methods
    bool SetMake(char* newMake);
    bool SetModel(char* newModel);
    bool SetYear(int newYear);
    bool SetTank(float newTank);
    bool SetSensCnt(int newSenscnt);
    bool SetBasePrice(float newBaseprice);
    bool SetAvailable(bool newAvail);
    bool SetOwner(char* newOwner);
    
    bool UpdatePrice();
    void PrintCar(ofstream&);
    float EstimateCost(int);
    RentalCar& operator+(CarSensor& nsens);
    RentalCar& operator+(char* nowner);
};

void RentalCar::CarCon()
//Default constructor that sets the data members for a RentalCar object to default initial values.
{
    int i;  //loop counter for all the car's sensors
    strcpy(m_make, '\0');
    strcpy(m_model, '\0');
    m_year = 0;
    m_tank = 0.0;
    CarSensor* senPtr = m_sensors;  //pointer to the current sensor
    for (int i = 0; i < 3; i++)
    {
        senPtr->SensCon();
        senPtr++;
    }
    m_senscnt = 0;
    m_baseprice = 0.0;
    m_finalprice = 0.0;
    m_available = false;
    strcpy(m_owner, '\0');
}
void RentalCar::CarCon(char* stMake, char* stModel, int stYear, float stTank, CarSensor* stSensors, float stBprice, float stFprice, bool stAvail, char* stOwner)
/*Parameterized constructor that will create a new RentalCar object based on values for RentalCar's initial
  make, model, year, tank capacity, sensors, base rental price, final rental price, availability, and owner*/
{
    int i;  //loop counter for all the car's sensors
    strcpy(m_make, stMake);
    strcpy(m_model, stModel);
    m_year = stYear;
    m_tank = stTank;
    CarSensor* sen1Ptr = m_sensors;
    CarSensor* sen2Ptr = stSensors;  //pointer to the current sensor of the initial sensors
    for (int i = 0; i < 3; i++)
    {
        sen1Ptr->SensCpy(*sen2Ptr);
        sen1Ptr++;
	sen2Ptr++;
    }
    m_baseprice = stBprice;
    m_finalprice = stFprice;
    m_available = stAvail;
    strcpy(m_owner, stOwner);
}
void RentalCar::CarCpy(RentalCar &initcar)
//Parameterized constructor that will create a new RentalCar object hich duplicates an input RentalCar object
{
    int i;  //loop counter for all the car's sensors
    strcpy(m_make,initcar.m_make);
    strcpy(m_model,initcar.m_model);
    m_year = initcar.m_year;
    m_tank = initcar.m_tank;
    CarSensor* sen1Ptr = m_sensors;
    CarSensor* sen2Ptr = initcar.m_sensors;  //pointer to the current sensor of the input RentalCar
    for (int i = 0; i < 3; i++)
    {
        sen1Ptr->SensCpy(*sen2Ptr);
        sen1Ptr++;
        sen2Ptr++;
    }
    m_senscnt = initcar.m_senscnt;
    m_baseprice = initcar.m_baseprice;
    m_finalprice = initcar.m_finalprice;
    m_available = initcar.m_available;
    strcpy(m_owner,initcar.m_owner);
}
char* RentalCar::GetMake()
//Returns the current value for an individual car's make
{
    return m_make;
}
char* RentalCar::GetModel()
//Returns the current value for an individual car's model
{
    return m_model;
}
int RentalCar::GetYear()
//Returns the current value for an individual car's year
{
    return m_year;
}
float RentalCar::GetTank()
//Returns the current value for an individual car's max tank capacity
{
    return m_tank;
}
CarSensor* RentalCar::GetSensors()
//Returns the current values for an individual car's sensors
{
    return m_sensors;
}
int RentalCar::GetSenscnt()
{
    return m_senscnt;
}
float RentalCar::GetBasePrice()
//Returns the current value for an individual car's base rental price per day
{
    return m_baseprice;
}
float RentalCar::GetFinalPrice()
//Returns the current value for an individual car's final rental price per day
{
    return m_finalprice;
}
bool RentalCar::GetAvailable()
//Returns the current value for an individual car's availability
{
    return m_available;
}
char* RentalCar::GetOwner()
//Returns the current value for an individual car's owner
{
    return m_owner;
}
bool RentalCar::SetMake(char* newMake)
/*Given the new value for a car's make, SetMake will set the current value
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
bool RentalCar::SetYear(int newYear)
/*Given the new value for a car's year, SetYear will set the current value for
 a car's year to the new value.*/
{
    if (newYear > 0)
    {
        m_year = newYear;
        return true;
    }
}
bool RentalCar::SetTank(float newTank)
/*Given the new value for a car's tank capacity, SetTank will set the current
 value for a car's tank capacity to the new value.*/
{
    if (newTank > 0.0)
    {
        m_tank = newTank;
        return true;
    }
}
bool RentalCar::SetBasePrice(float newBaseprice)
/*Given the new value for a car's base rental price per day, SetBasePrice will
 set the value for a car's base rental price to the new value.*/
{
    if (newBaseprice > 0.0)
    {
        m_baseprice = newBaseprice;
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
bool RentalCar::SetOwner(char* newOwner)
/*Given the new value for a car's owner, SetOwner will set the current name
 for a car's owner to the new value using strcpy().*/
{
    strcpy(m_owner,newOwner);
    return true;
}
bool RentalCar::UpdatePrice()
/*Updates the final rental price of the car after any potential changes to the
 base rental price of the car or its sensors*/
{
    int i;  //loop counter for all the car's sensors
    float sensCosts = 0.0;  //additional costs from sensors to base rental price
    CarSensor* senPtr = m_sensors;  //pointer to current sensor
    for (int i = 0; i < m_senscnt; i++)
    {
        sensCosts += senPtr->GetExtraCost();
        senPtr++;
    }
    m_finalprice = m_baseprice + sensCosts;
    return true;
}
void RentalCar::PrintCar(ofstream &outFile)
/*Given the output stream variable, PrintCar will print out all the data for a car to
 both the terminal and a separate output file.*/
{
    outFile.open("AllCarData.txt");
    CarSensor* senPtr = m_sensors;  //pointer to current sensor
    cout << m_year << " " << m_make << " " << m_model << " Max Tank Capacity: ";
    cout << m_tank << " gallons " << "Sensors: { ";
    outFile << m_year << " " << m_make << " " << m_model << " Max Tank Capacity: ";
    outFile << m_tank << " gallons " << "Sensors: { ";
    while (senPtr->GetType() != "\0")
    {
        cout << senPtr->GetType() << " ";
        outFile << senPtr->GetType() << " ";
        senPtr++;
    }
    cout << "} Base Price: $" << m_baseprice << " per day " << "Actual Price: $";
    cout << m_finalprice << " per day " << "Available: " << boolalpha << m_available;
    outFile << "} Base Price: $" << m_baseprice << " per day " << "Actual Price: $";
    outFile << m_finalprice << " per day " << "Available: " << boolalpha << m_available;
    if (m_owner != "\0")
    {
        cout << m_owner << endl;
        outFile << m_owner << endl;
    }
    outFile.close();
}
float RentalCar::EstimateCost(int totalDays)
/*Given the number of days that the car will be rented out, EstimateCost will calculate 
 the total rental cost of the car and return the value.*/
{
    float value = 0.0;  //total value of rental costs for car
    value = m_finalprice * totalDays;
    return value;
}
RentalCar& RentalCar::operator+(CarSensor& nsens)
/*Given a new CarSensor object, the AddSensor overloaded operator will add the data for 
 the new CarSensor to the current RentalCar object*/
{
    int i;  //loop counter for all the car's sensors
    CarSensor* senPtr = m_sensors;  //pointer to the current sensor
    if (m_senscnt == 3)
    {
        cout << "This car already has the maximum number of sensors." << endl;
    }
    else
    {
        for (int i = 0; i < m_senscnt; i++)
        {
            senPtr++;
        }
        *senPtr = nsens;
    }
    return *this;
}
RentalCar& RentalCar::operator+(char* nowner)
/*Given a new owner, the AddLessee overloaded operator will add the name of the owner
 to the current RentalCar object and change the RentalCar object's availability*/
{
    strcpy(m_owner,nowner); 
    m_available -= m_available;
    return *this;
}

//Class for storing name, zipcode, and data for all cars of the agency
class RentalAgency {
private:
    char m_name[20];   //character array for storing name of agency
    int m_zipcode[5];  //int array for storing agency zipcode
    RentalCar m_inventory[5];  //inventory of all car objects of agency
    
public:
    void AgenCon();
    
    //Primary get methods
    char* GetName();
    int* GetZipcode();
    
    //Primary set methods
    bool SetName(char* newname);
    bool SetZipcode(int* newzipcode);
    
    RentalCar& operator[](const int index);
    void ReadInData(ifstream &inFile);
    void PrintAllData(ofstream &outFile);
    void PrintAvailableCars(ofstream &outFile);
};

void RentalAgency::AgenCon()
//Default constructor that sets the data members for a RentalCar object to default initial values.
{
    int i; //loop counter for the agency's zipcode digits and cars
    strcpy(m_name, '\0');
    int* zipPtr = m_zipcode;  //pointer for the current digit of the zipcode
    RentalCar* carPtr = m_inventory;  //pointer for the current car of the agency
    for (int i = 0; i < 5; i++)
    {
        *zipPtr = 0;
        carPtr->CarCon();
        carPtr++;
        zipPtr++;
    }
}
char* RentalAgency::GetName()
//Returns the current value for the rental agency's name
{
    return m_name;
}
int* RentalAgency::GetZipcode()
//Returns the current value for the rental agency's zipcode
{
    return m_zipcode;
}
bool RentalAgency::SetName(char* newname)
/*Given the new value for the agency's name, SetName will set
 the value for the agency's name to the new value.*/
{
    strcpy(m_name,newname);
    return true;
}
bool RentalAgency::SetZipcode(int* newzipcode)
/*Given the new value for the agency's zipcode, SetZipcode will set
 the value for the agency's zipcode to the new value.*/
{
    int i;
    int* zipPtr = m_zipcode;
    for (int i = 0; i < 5; i++)
    {
        *zipPtr = *newzipcode;
        zipPtr++;
        newzipcode++;
    }
    return true;
}
RentalCar& RentalAgency::operator[](const int index)
/*Given the value of a desired index, GetInventoryItem will index an object 
 of the m_inventory data members, or a RentalCar object*/
{
    int i;  //loop counter for the RentalCar object array
    RentalCar* carPtr = this->m_inventory;  //pointer to current car
    //if index is not between 0 and 4
    if (index < 0 || index > 4)
    {
        cout << "Invalid index. Please try again." << endl;
    }
    else
    {
	for (int i = 0; i < index; i++)
	{
	    carPtr++;
	}
    }
    return *carPtr;
}
void RentalAgency::ReadInData(ifstream &inFile)
/*Given the input stream variable, ReadInData will read all of the data for
 the agency from a user-provided file.*/
{
    int i;  //loop counter for iterations through zipcode and car sensors 
    RentalCar* carPtr = m_inventory;  //pointer to the current car of the agency
    int* iptr = m_zipcode;  //pointer to the current digit of the agency's zipcode
    
    char tempMake[20];     //temporary array for storing value of car's make
    char tempModel[20];    //temporary array for storing value of car's model
    int tempYear;    //temporary variable for storing value of car's year
    float tempTank;  //temporary variable for storing value of car's tank capacity
    float tempBaseprice;   //temporary variable for storing car's base rental price
    float tempFinalprice;  //temporary variable for storing car's final rental price
    bool tempAvail;  //temporary variable for storing value of car's availability
    char tempOwner[20];    //temporary array for storing value of car's owner
    CarSensor newSensor[3];  //temporary array for storing car's sensors
    
    char newType[20];  //temporary array for storing a car sensor's type
    
    inFile >> m_name;
    inFile.get();
    for (int i = 0; i < 5; i++)
    {
        *iptr = inFile.get() - '0';
        iptr++;
    }
    for (int i = 0; i < 5; i++)
    {
        CarSensor* newPtr = newSensor;  //pointer to current car sensor being read
        inFile >> tempYear >> tempMake >> tempModel >> tempTank >> tempBaseprice;
        carPtr->SetYear(tempYear);
        carPtr->SetMake(tempMake);
        carPtr->SetModel(tempModel);
        carPtr->SetBasePrice(tempBaseprice);
        
        inFile.get();
        inFile.get();
        while (inFile.peek() != '}')
        {
            inFile >> newType;
            newPtr->SetType(newType);
            if (strcmp(newType, "gps") == 0)
            {
                newPtr->SetExtraCost(5.0);
                newPtr->GetGps()+1;
            }
            else if (strcmp(newType, "camera") == 0)
            {
                newPtr->SetExtraCost(10.0);
                newPtr->GetCam()+1;
            }
            else if (strcmp(newType, "lidar") == 0)
            {
                newPtr->SetExtraCost(15.0);
                newPtr->GetLid()+1;
            }
            else if (strcmp(newType, "radar") == 0)
            {
                newPtr->SetExtraCost(20.0);
                newPtr->GetRad()+1;
            }
            else
            {
                newPtr->SetExtraCost(0.0);
            }
            newPtr++;
        }
        inFile.get();
        carPtr->UpdatePrice();
        inFile >> tempAvail >> tempOwner;
        carPtr->SetAvailable(tempAvail);
        carPtr->SetOwner(tempOwner);
        carPtr++;
    }
}
void RentalAgency::PrintAllData(ofstream &outFile)
/*Given the output stream variable, PrintData prints out all the data for an
 agency, including all the car info. It also prints this data to an output file*/
{
    outFile.open("AllAgencyData.txt");
    int i;  //loop counters for iterations over agencies, cars, zipcodes
    RentalCar* carPtr = m_inventory;  //pointer for a RentalCar's data
    int* iptr = m_zipcode;  //pointer for current integer of zipcode

    cout << m_name << " ";
    outFile << m_name << " ";
    for (int i = 0; i < 5; i++)
    {
        cout << *iptr;
        outFile << *iptr;
        iptr++;
    }
    cout << endl;
    outFile << endl;
    for (int i = 0; i < 5; i++)
    {
        carPtr->PrintCar(outFile);
        carPtr++;
    }
    cout << endl;
    outFile << endl;
    outFile.close();
}
void RentalAgency::PrintAvailableCars(ofstream &outFile)
/*Given the output stream variable, PrintAvailableCars will print out all the data only
 for the available cars of the agency. It also writes this data to an output file.*/
{
    outFile.open("AllAvailableCars.txt");
    int i;  //loop counter for iterations over RentalCars
    RentalCar* carPtr = m_inventory;  //pointer for a car's data
    for (int i = 0; i < 5; i++)
    {
        if (carPtr->GetAvailable() == 1)
        {
            carPtr->PrintCar(outFile);
        }
        carPtr++;
    }
    outFile.close();
}

RentalAgency currAgency;

void callMenu(RentalAgency&,ifstream&,ofstream&);
void readIn(RentalAgency&,ifstream&);
void printAgency(RentalAgency&,ofstream&);
void sensorNum(RentalAgency&, ofstream&);
void carSearch(RentalAgency&);
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
    callMenu(currAgency,inFile,outFile);
    
    //closes input file
    inFile.close();
    
    return 0;
}
void callMenu(RentalAgency &currAgency, ifstream &inFile, ofstream &outFile)
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
        cout << "Option 2: Print Out All Agency and Car Data" << endl;
        cout << "Option 3: Print Out Total Number of Sensors" << endl;
        cout << "Option 4: Find Most Expensive Available Car" << endl;
        cout << "Option 5: Exit the Program" << endl;
        cout << "Select an option by entering its number: " << endl;
        cin >> menuOption;
        
        switch (menuOption)
        {
            case 1:
	        readIn(currAgency,inFile);
                break;
            case 2:
	        printAgency(currAgency,outFile);
                break;
	    case 3:
	        sensorNum(currAgency,outFile);
                break;
            case 4:
                carSearch(currAgency);
                break;
            case 5:
                doneStatus = exitProg();
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
        }
    } while (doneStatus != true);
}
void readIn(RentalAgency &currAgency,ifstream &inFile)
/*Given the input stream variable, readIn will read in all the data for the
 agency, including all the data for its cars, from the input file.*/
{
    currAgency.ReadInData(inFile);
}
void printAgency(RentalAgency &currAgency,ofstream &outFile)
/*Given the array of structs with data from all agencies, like car data,
 printData will print out all data for all the cars. The function will
 also write all the data to a separate output file.*/
{
    currAgency.PrintAllData(outFile);
}
void sensorNum(RentalAgency &currAgency, ofstream &outFile)
/*Given the class object with all the data from the agency and the output stream
 variable, sensorNum will print out the total number of sensors in the agency's fleet.
 The function will also print out this data to a separate output file.*/
{
    outFile.open("TotalCarSensors.txt");
    int i;  //loop counter for iterations through inventory of agency
    int totSensors = 0;  //total number of sensors in entire fleet
    for (int i = 0; i < 5; i++)
    {
        totSensors += currAgency[i].GetSenscnt();
    }
    cout << "Total Number of Sensors in All Cars: " << totSensors << endl;
    outFile << "Total Number of Sensors in All Cars: " << totSensors << endl;
    outFile.close();
}
void carSearch(RentalAgency &currAgency)
/*Given the class object with data from the agency, carSearch will find and print out the most 
 expensive available car from the agency. The user is asked if they want to rent it, and the 
 car's lessee and availability status is updated if the user says yes.*/
{
    int i;  //loop counters for iterations over RentalCar objects
    RentalCar maxCar = currAgency[0];  //pointer to most expensive price car
    //RentalCar curPtr = (RentalCar*)currAgency[0];  //pointer to current car being read
    for (int i = 0; i < 5; i++)
      {
	if (currAgency[i].GetFinalPrice() > maxCar.GetFinalPrice() && currAgency[i].GetAvailable() == true)
	  {
	    maxCar = currAgency[i];
	  }
      }
    if (maxCar.GetAvailable() == false)
      {
	cout << "There are no cars available." << endl;
      }
    else
      {
	CarSensor* senPtr = maxCar.GetSensors();  //pointer to current sensor of car
	char answer;  //answer of user as to whether car should be rented
	cout << "Most Expensive Available Car: " << maxCar.GetYear() << " " << maxCar.GetMake()
	     << " " << maxCar.GetModel() << " Max Tank Capacity: " << maxCar.GetTank()
	     << " gallons " << "Sensors: { ";
	while (senPtr->GetType() != "\0")
	  {
	    cout << senPtr->GetType() << " ";
	    senPtr++;
	  }
	cout << "} Actual Price: $" << maxCar.GetFinalPrice() << " per day " << endl;
	cout << "Would you like to rent this car out? Press Y or N" << endl;
        cin >> answer;
	if (answer == 'Y' || answer == 'y')
	  {
	    char ownName[20];  //first name of user
	    cout << "Please enter your first name: " << endl;
	    cin >> ownName;
	    maxCar.SetAvailable(false);
	    maxCar.SetOwner(ownName);
	    cout << "Thank you for your reservation." << endl;
	  }
      }
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
