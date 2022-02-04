/*
 Houman irani
 Winter 2019
 Lab 5
 Problem 5.2
 This program creates a StringOfCar which stores pointer to Car objects
 */

#include <iostream>
#include <fstream>
#include <string>


using namespace std;
/* Car class
 This is a class for object of cars
 */


enum Kind {business, maintenance, other, box, tank, flat, otherFreight, chair, sleeper, otherPassenger};
string KIND_ARRAY[]={"business", "maintenance", "other", "box","tank", "flat","otherFreight","chair","sleeper","otherPassenger"};
class Car
{
protected:
    int carNumber;
    bool loaded;
    string reportingMark,destination;
    Kind kind;
public:
    Car()
    {
        setUp("",0, "other", false, "NONE");
    }
    
    Car(const Car &c)
    {
        setUp(c.reportingMark, c.carNumber, KIND_ARRAY[c.kind], c.loaded, c.destination);
    }
    
    
    Car(string reportingMark, int carNumber, string kind, bool loaded, string destination)
    {
        setUp(reportingMark, carNumber,kind, loaded, destination);
    }
    virtual ~Car()
    {
    }
    friend bool operator==(const Car &car1, const Car &car2);
    void setUp(string reportingMark, int carNumber, string kind, bool loaded, string destination);
    void output();
    virtual void setKind(const string & kindstring);
    Car & operator=(const Car & carB);
};
//this is the derived class freight car
class FreightCar : public Car
{
public:
    FreightCar()
    {
        setUp("", 0, "other", false, "NONE");
    }
    FreightCar(const FreightCar &oldFreight)
    {
        setUp(oldFreight.reportingMark, oldFreight.carNumber, KIND_ARRAY[oldFreight.kind], oldFreight.loaded, oldFreight.destination);
    }
    FreightCar(const string &reportingMark, const int &carNumber, const string &kind, const bool &loaded, const string &destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    void setKind(const string & stringKind);
};

//this is the derive class passenger car
class PassengerCar : public Car
{
public:
    PassengerCar()
    {
        setUp("", 0, "other", false, "NONE");
    }
    PassengerCar(const PassengerCar &oldPassenger)
    {
        setUp(oldPassenger.reportingMark, oldPassenger.carNumber, KIND_ARRAY[oldPassenger.kind], oldPassenger.loaded, oldPassenger.destination);
    }
    PassengerCar(const string &reportingMark, const int &carNumber, const string &kind, const bool &loaded, const string &destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    void setKind(const string & stringKind);
    
};


/* StringIfCars
 This is a class which contains an array of cars
 */
class StringOfCars
{
private:
    static const int ARRAY_SIZE = 10;
    Car **ptr;
    int carCount;
    
public:
    
    StringOfCars()
    {
        ptr = new Car*[ARRAY_SIZE];
        carCount = 0;
    }
    
    StringOfCars(const StringOfCars &c)
    {
        ptr = new Car*[ARRAY_SIZE];
        carCount = c.carCount;
        for(int i = 0; i < carCount; i++){
            ptr[i]=new Car;
            ptr[i] = c.ptr[i];
        }
    }
    ~StringOfCars()
    {
        delete [] ptr;
    }
    void push(Car &c);
    void push(FreightCar &f);
    void push(PassengerCar &f);
    void output();
};

void input(StringOfCars &soc);

int main()
{
    StringOfCars a;
    input(a);
    StringOfCars b=a;
    b.output();
}
void Car::setKind(const string & kindstring )
{
    if(kindstring=="business")
        kind=business;
    else if(kindstring=="maintenance")
        kind=maintenance;
    else
        kind=other;
}

void FreightCar::setKind(const string & stringKind)
{
    if (stringKind == "box")
        kind = box;
    else if (stringKind == "tank")
        kind = tank;
    else if (stringKind == "flat")
        kind = flat;
    else kind = otherFreight;
}

void PassengerCar::setKind(const string & stringKind)
{
    if (stringKind == "chair")
        kind = chair;
    else if (stringKind == "sleeper")
        kind = sleeper;
    else kind = otherPassenger;
}

/*
 Takes 5 parameters by value: reporting mark, car number, kind, loaded, and destination
 Inputs these paramaters into the Car class' variables
 */
void Car::setUp(string rm, int cn, string k, bool l, string d)
{
    setKind(k);
    reportingMark = rm, carNumber = cn, loaded = l, destination = d;
}

//Prints the reporting mark, car number, kind, loaded, and destination in a neat format

void Car::output()
{
    string isLoaded;
    if(loaded) isLoaded = "true";
    else isLoaded = "false";
    cout << "\nReporting Mark: \t" << reportingMark << "\nCar Number: \t\t" << carNumber << "\nKind: \t\t\t" << KIND_ARRAY[kind] << "\nCar is loaded: \t\t" << isLoaded << "\nDestination: \t\t" << destination << endl;
}

//sets the values in the left hand object from the right hand object

Car & Car::operator=(const Car & carB)
{
    setUp(carB.reportingMark, carB.carNumber,KIND_ARRAY[carB.kind], carB.loaded, carB.destination);
    
    return * this;
}

//Prints out car objects in StringOfCars array

void StringOfCars::output()
{
    if(carCount == 0) cout << "NO cars";
    
    for(int i = 0; i < carCount; i++)
    {
        cout << "\nCar Number: " << i + 1 << endl;
        ptr[i]->output();
    }
    
    
}

//Adds car to StringOfCars array

void StringOfCars::push(Car &c)
{
    if(carCount < ARRAY_SIZE)
    {
        ptr[carCount]=new Car;
        *(ptr[carCount]) = c;
        carCount++;
    }
    else cout << "Car array is full, cannot add car";
}

void StringOfCars::push(FreightCar &f)
{
    if(carCount<ARRAY_SIZE)
    {
        ptr[carCount]=new FreightCar;
        *(ptr[carCount])=f;
        carCount++;
    }
    else cout<< "Car array is full, cannot add car";
}

void StringOfCars::push(PassengerCar &p)
{
    if(carCount<ARRAY_SIZE)
    {
        ptr[carCount]=new PassengerCar;
        *(ptr[carCount])=p;
        carCount++;
    }
}
//creates a car and push into array
void buildcar(string reportingMarkBC, int carNumberBC, string kindBC, bool loadedBC, string destinationBC,StringOfCars &soc)
{
    Car c(reportingMarkBC,carNumberBC,kindBC,loadedBC,destinationBC);
    soc.push(c);
}
//creates a car and push into array
void buildFreightCar(string reportingMarkBC, int carNumberBC, string kindBC, bool loadedBC, string destinationBC,StringOfCars &soc)
{
    FreightCar f(reportingMarkBC,carNumberBC,kindBC,loadedBC,destinationBC);
    soc.push(f);
}
//creates a car and push into array
void buildPassengerCar(string reportingMarkBC, int carNumberBC, string kindBC, bool loadedBC, string destinationBC,StringOfCars &soc)
{
    PassengerCar p(reportingMarkBC,carNumberBC,kindBC,loadedBC,destinationBC);
    soc.push(p);
}

//Compares two
// objects to see if they equal

bool operator==(const Car &car1, const Car &car2)
{
    return (car1.reportingMark == car2.reportingMark && car1.carNumber == car2.carNumber);
}

/*
 Takes the reporting mark, car number, kind, loaded, and destination as value parameters
 Values read from a text file
 */
void input(StringOfCars &soc)
{
    string reportingMark, kind, destination, carType,orderofcar;
    int carNumber;
    bool loaded;
    string loadedString;
    ifstream inputFile;
    inputFile.open("cardata5.txt");
    if(!inputFile.is_open())
    {
        fprintf(stderr, "Error Opening File\n");
        exit(1);
    }
    while(inputFile.peek() != EOF)
    {
        
        inputFile >> carType >>orderofcar>> reportingMark >> carNumber >> kind >> loadedString;
        
        if(loadedString == "true") loaded = true;
        else if(loadedString == "false") loaded = false;
        else cout << "There has been a problem with loaded";
        while(inputFile.peek() == ' ')
        {
            inputFile.get();
        }
        
        getline(inputFile, destination, '\n');
        
        if(carType == "Car")
        {
            buildcar(reportingMark,carNumber,kind,loaded,destination,soc);
        }
        else if(carType=="FreightCar")
        {
            buildFreightCar(reportingMark,carNumber,kind,loaded,destination,soc);
        }
        else if(carType=="PassengerCar")
        {
            buildPassengerCar(reportingMark,carNumber,kind,loaded,destination,soc);
        }
        else
        {
            cout << "\nError: carType not 'Car'\n";
        }
    }
    inputFile.close();
}


