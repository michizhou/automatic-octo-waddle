#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


/////////////////////////////// CLIENT ///////////////////////////////////
class Client{
  public:
   Client() = delete;
   Client(const char* name) : m_name(name){ }
  friend std::istream& operator>>(std::istream& is, Client& client){      cin >> client.m_name; return is; }
  friend std::ostream& operator<<(std::ostream& os, const Client& client){ os << client.m_name; return os; }
  private:
    std::string m_name; //std::string provides automatic memory management! 
};


/////////////////////////////// STORE ///////////////////////////////////
class Store{
  public:
   Store() = delete;
   Store(const char* location) : m_location(location){ }
  // equality operator== overload is necessary for std::find to work on a std::vector<Store>
  // (needs to perform equality checking on Store type values)
  friend bool operator==(const Store& s1, const Store& s2){ return s1.m_location == s2.m_location; }
  // less than operator< overload is necessary for std::find to work on a std::set<Store> or a std::map<Store,T>
  // (needs to perform equivalence checking on Store type values which are the std::set and std::map Keys)
  friend bool operator<(const Store& s1, const Store& s2){ return s1.m_location < s2.m_location; }
  friend std::istream& operator>>(std::istream& is, Store& store){      cin >> store.m_location; return is; }
  friend std::ostream& operator<<(std::ostream& os, const Store& store){ os << store.m_location; return os; }
  private:
    std::string m_location; //std::string provides automatic memory management! 
};


////////////////////////////// SENSOR //////////////////////////////////
class Sensor{
 const std::map<const std::string, const float> TypePrices {
   // this strongly maps a string (representing type) to a float (value)
   // also since std::map allows only UNIQUE Key entries, is guarantees
   // you will not get muliple pairs ("gps" will be mapped to exactly one price)
   { "gps", 7.5 }, 
   { "camera", 10.0 },
   { "lidar", 15.0 },
   { "radar", 25.0 }
 };    
 public:
  Sensor() = delete;
  Sensor(const char* s_type) : m_type(s_type){
    std::map<const std::string, const float>::const_iterator it = 
    Sensor::TypePrices.find(m_type);
    // constructor throws if given m_type is not found in TypePrices map
    // this permits creation only of objects that have a specific m_type  
    if ( it == Sensor::TypePrices.end() )
      throw std::runtime_error("Sensor: invalid Type requested from ctor.");
  }
  float GetPrice() const{ 
    std::map<const std::string, const float>::const_iterator it = 
    Sensor::TypePrices.find(m_type);
    // will always be valid, constructor throws if not in TypePrices map
    // there is only 1 permissible price per m_type, from TypePrices map
    return it->second;
  }
 private:
  const std::string m_type;
  // notice, that there is no m_price member 
};


/////////////////////////////// VEHICLE //////////////////////////////////
class Vehicle{
  public:
    Vehicle() = delete;
    Vehicle(const std::string model, const size_t year, float price, const Client* owner);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& otherVehicle);
    void SetPrice(const float price);
    void SetOwner(const Client* owner);
    const std::string GetModel() const;
    const size_t GetYear() const;
    const Client* GetOwner() const;
    
    virtual float GetPrice() const;
    virtual void Serialize(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
  protected:
    const std::string m_model;
    const size_t m_year;
  private:
    float m_baseprice;
    const Client* m_owner;
};

Vehicle::Vehicle(const std::string model, const size_t year, float price, const Client* owner)
    : m_model(model), m_year(year), m_owner(owner) {
    m_baseprice = price;
}
Vehicle::Vehicle(const Vehicle& other)
    : m_model(other.m_model), m_year(other.m_year), m_owner(other.m_owner) {
    m_baseprice = other.m_baseprice;
}
Vehicle& Vehicle::operator=(const Vehicle& otherVehicle)
    : m_owner(NULL) {
    if (this != &otherVehicle)
    {
        m_model = otherVehicle.m_model;
        m_year = otherVehicle.m_year;
        m_baseprice = otherVehicle.m_baseprice;
    }
    return *this;
}
void Vehicle::SetPrice(const float price)
{
    m_baseprice = price;
}
void Vehicle::SetOwner(const Client* owner)
{
    m_owner = owner;
}
const std::string Vehicle::GetModel() const
{
    return m_model;
}
const size_t Vehicle::GetYear() const
{
    return m_year;
}
const Client* Vehicle::GetOwner() const
{
    return m_owner;
}

float Vehicle::GetPrice() const
{
    return m_baseprice;
}
void Vehicle::Serialize(std::ostream& os) const
{
    os << m_year << " " << m_model << " $" << m_baseprice;
    if (m_owner)
    {
        os << " Renter: " << m_owner;
    }
    os << endl;
}
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    vehicle.Serialize(os);
    return os;
}

/////////////////////////// ADVANCEDVEHICLE ///////////////////////////////
class AdvancedVehicle : public Vehicle{
  public:
    AdvancedVehicle() = delete;
    AdvancedVehicle(const std::string model, const size_t year, float price,
                    const Client* owner, std::vector sensors);
    AdvancedVehicle(const AdvancedVehicle& other);
    AdvancedVehicle& operator=(const AdvancedVehicle& otherVehicle);
    void AddSensor(const Sensor& sensor);
    
    virtual float GetPrice() const;
    virtual void Serialize(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const AdvancedVehicle& a_vehicle);
  private:
    std::vector<Sensor> m_sensors;
    float m_finalprice;
};

AdvancedVehicle::AdvancedVehicle(const std::string model, const size_t year, float price,
                                 const Client* owner, std::vector<Sensor> sensors)
    : Vehicle(model, year, price, owner)
{
    float addCost = 0.0;
    for (int i = 0; i < sensors.size(); i++)
    {
        float value = sensors[i].GetPrice();
        if (value == 7.5)
        {
            m_sensors[i] = new Sensor("gps");
        }
        else if (value == 10.0)
        {
            m_sensors[i] = new Sensor("camera");
        }
        else if (value == 15.0)
        {
            m_sensors[i] = new Sensor("lidar");
        }
        else
        {
            m_sensors[i] = new Sensor("radar");
        }
        addCost += sensors[i].GetPrice();
    }
    m_finalprice = m_baseprice + addCost;
}
AdvancedVehicle::AdvancedVehicle(const Vehicle& other)
    : Vehicle(other.m_model, other.m_year, other.GetPrice(), other.GetOwner())
{
    float addCost = 0.0;
    for (int i = 0; i < other.m_sensors.size(); i++)
    {
        float value = other.m_sensors[i].GetPrice();
        if (value == 7.5)
        {
            m_sensors[i] = new Sensor("gps");
        }
        else if (value == 10.0)
        {
            m_sensors[i] = new Sensor("camera");
        }
        else if (value == 15.0)
        {
            m_sensors[i] = new Sensor("lidar");
        }
        else
        {
            m_sensors[i] = new Sensor("radar");
        }
        addCost += other.m_sensors[i].GetPrice();
    }
    m_finalprice = m_baseprice + addCost;
}
AdvancedVehicle& AdvancedVehicle::operator=(const Vehicle& otherVehicle)
    : m_owner(NULL)
{
    if (this != &otherVehicle)
    {
        m_model = otherVehicle.m_model;
        m_year = otherVehicle.m_year;
        m_baseprice = otherVehicle.m_baseprice;
        float addCost = 0.0;
        for (int i = 0; i < otherVehicle.m_sensors.size(); i++)
        {
            float value = otherVehicle.m_sensors[i].GetPrice();
            if (value == 7.5)
            {
                m_sensors[i] = new Sensor("gps");
            }
            else if (value == 10.0)
            {
                m_sensors[i] = new Sensor("camera");
            }
            else if (value == 15.0)
            {
                m_sensors[i] = new Sensor("lidar");
            }
            else
            {
                m_sensors[i] = new Sensor("radar");
            }
            addCost += otherVehicle.m_sensors[i].GetPrice();
        }
        m_finalprice = m_baseprice + addCost;
    }
    return *this;
}
void AdvancedVehicle::AddSensor(const Sensor& sensor)
{
    int act_size = m_sensors.size();
    std::vector<Sensor>* tempVector = new std::vector<Sensor>(act_size);
    for (int i = 0; i < act_size; i++)
    {
        int price = m_sensors[i].GetPrice();
        if (price == 7.5)
        {
            tempVector[i] = new Sensor("gps");
        }
        else if (price == 10.0)
        {
            tempVector[i] = new Sensor("camera");
        }
        else if (price == 15.0)
        {
            tempVector[i] = new Sensor("lidar");
        }
        else
        {
            tempVector[i] = new Sensor("radar");
        }
    }
    delete [] m_sensors;
    act_size++;
    m_sensors = new std::vector<Sensor>(act_size);
    for (int i = 0; i < act_size - 1; i++)
    {
        int price = tempVector[i].GetPrice();
        if (price == 7.5)
        {
            m_sensors[i] = new Sensor("gps");
        }
        else if (price == 10.0)
        {
            m_sensors[i] = new Sensor("camera");
        }
        else if (price == 15.0)
        {
            m_sensors[i] = new Sensor("lidar");
        }
        else
        {
            m_sensors[i] = new Sensor("radar");
        }
    }
    int newprice = sensor.GetPrice();
    if (newprice == 7.5)
    {
        m_sensors[act_size-1] = new Sensor("gps");
    }
    else if (newprice == 10.0)
    {
        m_sensors[act_size-1] = new Sensor("camera");
    }
    else if (newprice == 15.0)
    {
        m_sensors[act_size-1] = new Sensor("lidar");
    }
    else
    {
        m_sensors[act_size-1] = new Sensor("radar");
    }
}

float AdvancedVehicle::GetPrice() const
{
    return m_finalprice;
}
void AdvancedVehicle::Serialize(std::ostream& os) const
{
    os << m_year << " " << m_model << " $" << m_finalprice;
    if (m_sensors)
    {
        os << "Sensors: { "
    }
    for (int i = 0; i < m_sensors.size(); i++)
    {
        int price = m_sensors[i].GetPrice();
        if (price == 7.5)
        {
            os << "gps ";
        }
        else if (price == 10.0)
        {
            os << "camera ";
        }
        else if (price == 15.0)
        {
            os << "lidar ";
        }
        else
        {
            os << "radar ";
        }
    }
    os << "}";
    if (m_owner)
    {
        os << " Renter: " << m_owner;
    }
    os << endl;
}
std::ostream& operator<<(std::ostream& os, const AdvancedVehicle& a_vehicle)
{
    a_vehicle.Serialize(os);
    return os;
}


////////////////////////////// INVENTORY /////////////////////////////////
class Inventory{
  public:
   Inventory()
   { }
   Inventory(const std::set<Store>& storesSet)
    : m_stores(storesSet)
   { }
   // adds a Store to the set of m_stores, using a std::set
   Inventory& operator+(const Store& store){
     // using a std::set (and not st::multiset) guarantees that you will have unique Store entries in m_stores
	 m_stores.insert(store);
     // returns calling object for operator+ daisy-chaining
     return *this;
   }
   // finds by name and returns reference to a Store inside the Inventory m_stores
   // note that because the Store& returned corresponds to a Key of a std::set (in a std::set
   // Keys cannot be changed – they are const) it is necessarily returned as a
   // const Store& (even if the function wasn’t marked as const itself, and even 
   // though we are not using a const_iterator to find it! 
   const Store* At(const char* store) const{
     // first, std::find searches for a Store inside a std::set by performing equivalence checking
     // ( this means it is also necessary for operator< for Store to be defined, otherwise it will not work! )
     std::set<Store>::iterator it = std::find(m_stores.begin(), m_stores.end(), Store(store));
     // for finding in a std::set you can also use its own find function like: m_stores.find(Store(store));
     if (it == m_stores.end())
       // if a valid Store is not found by name the function throws a runtime error
       throw std::runtime_error("Inventory: invalid Store requested from function At()...");
     //otherwise it returns The_Address_Of(&)--The_Element_Behind(*)--The_Iterator
  	 return &*it;  // Iterator dereference(*) and Address-Of(&)
   }
   // finds by equivalence of model, date, price a Vehicle inside the Inventory's m_inventory std::map
   // returns a reference to the underlying map element (a std::pair), and for the same reasons as
   // above, the Key used has to be const (since a pointer is used here, we have to declare the pointer
   // to be constant by Vehicle* const
   // remember:  const Vehicle*  is a pointer to a constant Vehicle object
   //            Vehicle* const  is a constant pointer to a Vehicle object
   // therefore we can have the std::map underlying
   std::pair<Vehicle* const, const Store*>& operator[](const char* vehicleModelDatePrice) {
     std::istringstream model_date_price( vehicleModelDatePrice );
     std::string substring;
     std::vector< std::string > substringVec;  
     while (std::getline(model_date_price, substring, ':'))
       substringVec.push_back(substring);
     if (substringVec.size()!=3) // should be exactly 3, vehicle_type:vehicle_date:vehicle_price
       throw std::runtime_error("Inventory: invalid formatting of data requested from operator[].");
     // checking that the input string contains data correcly formatted is done, use data now
     std::string find_model = substringVec.at(0);
     size_t find_date = std::stoi( substringVec.at(1) ); //don't use atoi(), returns 0 on error!
     float find_price = std::stof( substringVec.at(2) );
     // create a temporary vehicle, which we want find by checking equivalence of its values to the
     // Keys already stored in m_inventory (actually the Keys' underlying object values, as the 
     // Keys are raw pointers Vehicle*, see explanation below on how we do this).
     Vehicle find_vehicle(find_model, find_date, find_price);
     // this shows usage of st::map own find() function (instead of std::find())
     auto it = m_inventory.find( &find_vehicle );
     // there is also the possibility in C++11 to infer the type by saying:  auto it = ...
     // without auto we would have to say: std::map<Vehicle* const, const Store*>::const_iterator = ...
     if (it == m_inventory.end())
       throw std::runtime_error("Inventory: invalid Vehicle requested from operator[].");
     return *it;
   }
   // adds a Vehicle to the m_inventory std::map, and associates it with a specific store  
   Inventory& AddEntry(Vehicle* vehicle, const char* store_name){
     // invokes function At() to retreive a Store in m_stores by-Address, function At() will throw
     // an exception if the Store does not exist, so there is no danger to insert a a vehicle with
     // no valid Store association 
     m_inventory.insert( std::make_pair(vehicle, this->At(store_name)) ); 
     // returns calling object for daisy-chaining
     return *this;
   }

 friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory){
    for (auto it = inventory.m_inventory.begin(); it != inventory.m_inventory.end(); ++it){
      os << "Store:\t"<< *it->second << "\t" << *it->first << "\n";
    }
    return os;
 }

 private:
   std::set<Store> m_stores;
   // a custom Equivalence Comparison function to be used with the std::map Keys (of type Vehicle*
   // below) If we left it up to the compiler, it would check for duplicaes and sort the map Keys
   // checking pointer values (Keys are Vehicle*) which are memory addresses. So also in order to
   // std::find a Key we would have to already know its address (because find works with equivalence
   // checking which would be applied on raw pointers (addresses). By defining our own SPECIFIC
   // comparison function to be used SPECIFICALLY for the std::map we are trying to achieve, we
   // achieve a behavior that map insertion/sorting/finding dereferences the underlying object and
   // checks if the values: (m_model, m_year, m_baseprice/m_finalprice - depending if the object is
   // of Base/Derived class type) are equivalent. Therefore we can find a map element (Vehicle-Store
   // std::pair by looking up a sample Vehicle temporary object for which we only have to know the
   // right (m_model, m_year, m_baseprice/m_finalprice) like in the operator[] function above!
   // 
   // note: we could achieve the same by defining an operator< overloaded for Vehicle* types
   // but this would mean that any other function trying to perform such a functionality (comparing
   // two Vehicle pointers) would use that overloaded version, whereas now we keep this desired
   // functionaliy isolated to how the m_inventory std::map operates   
   struct CompareEquivalence_VehiclePtr {
     bool operator()(const Vehicle* v1, const Vehicle* v2) const {
       return ( v1->GetModel() < v2->GetModel()  ||
                v1->GetYear() < v2->GetYear()  ||
                v1->GetPrice() < v2->GetPrice() );
       //the last one is GetPrice() virtual, so will work with Base and Derive class Pointers!
     }
   };
   std::map<Vehicle*, const Store*, CompareEquivalence_VehiclePtr> m_inventory;
   // notice, this is a map with Vehicle* as the Key (therefore ordering would happen
   // based on addresses – if we had not defined the CompareEquivalence_VehiclePtr
   // custom function for Equivalence-based comparison
   // remember a map only allows ONE entry per Key (contrary to a multimap), and in this
   // case in particular two identical keys should never exist in any case, since unique
   // items (Vehicle objects) must have unique addresses too
   // also note, the Values of the Key-Value pairs in the std::map are const Store*
   // as they are pointers to Keys of a std::set (m_stores), this signifies that the
   // underlying Store Object cannot be changed
   // in total, you have a map of unique Vehicle entries paired to unique Store in a
   // way that still allows cross associations, moving around, efficient finding/adding

};


int main()
{
  // Make some clients
  const Client* mary_Pt = new Client("Mary");
  const Client* joe_Pt = new Client("Joe");
  const Client* me_Pt = new Client("Me");
 

  // Make some Vehicles (either with an owner or without)
  // Mazda RX-7
  Vehicle* rx7_Pt = new Vehicle("RX-7", 1997, 200.0);
  // Mitsubishi EVO-8
  Vehicle* evo8_Pt = new Vehicle("EVO-8", 2004, 175.0, mary_Pt);

  // Make some AdvancedVehicles (with some Sensor entries too)
  // Tesla Model-S
  std::vector<Sensor> modelS_sensors = {Sensor("camera"), Sensor("gps"),};
  Vehicle* modelS_Pt = new AdvancedVehicle("Model-S", 2016, 225.0, modelS_sensors, joe_Pt);
  // Aston Martin DB-9
  std::vector<Sensor> db9_sensors = {Sensor("camera"), Sensor("gps"), Sensor("radar"), Sensor("lidar")};
  Vehicle* db9_Pt = new AdvancedVehicle("DB-9", 2014, 300.0, db9_sensors);


  /////////// DEMONSTRATE THE EASE-OF-USE OF THE INVENTORY CLASS //////////////
  ////// TOGETHER WITH ALL THE GUARANTEES IT OFFERS BY USING THE STL //////////

  // Make set of Stores and instantiate the Inventory
  std::set<Store> stores = {Store("Nevada-Reno"), Store("San Francisco"), Store("Los Angeles")};
  Inventory agencyInv(stores);


  // Add entries
  agencyInv.AddEntry(rx7_Pt, "Los Angeles");
  agencyInv.AddEntry(evo8_Pt, "Nevada-Reno");
  agencyInv.AddEntry(modelS_Pt, "San Francisco");
  agencyInv.AddEntry(db9_Pt, "San Francisco");

  
  // Output the Inventory
  cout << endl << agencyInv << endl;

  
  // find a specific entry (a std::map) by simply saying  Inventory[ "Model:Year:Price" ]
  // then access its first member (Vehicle*) to change owner
  // then access its second member (Store*) to some other Store location
  // also use C++11 auto which offers automatic type-inference
  auto& rx7_inventoryEntry = agencyInv["RX-7:1997:200"];
  // the type returned by operator[] is a reference:  std::pair<Vehicle* const, const Store*>&
  // if you use just:  auto  rx7_inventoryEntry = ...
  // instead of :      auto& rx7_inventoryEntry = ...
  // it will mean:  std::pair<Vehicle* const, const Store*> rx7_inventoryEntry = ...
  // this is how auto works, it infers the <type only> not the specifiers (reference &, const, ...) 
  // try it if you don't believe me, change auto& to a simple auto, the effect will be that
  // the Inventory entry will not change when you re-output it in the last line of main()
  rx7_inventoryEntry.first->SetOwner( me_Pt );
  rx7_inventoryEntry.second = agencyInv.At("Nevada-Reno");


  // Output the Inventory new state
  cout << endl << agencyInv << endl;

}

