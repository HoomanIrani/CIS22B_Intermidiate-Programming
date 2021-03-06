/*
Houman Irani
Winter 2019
Lab 4
Problem 4.2
This program creates Car object and puts them into StringOfCars
*/

#include <iostream>
#include <fstream>
using namespace std;

class Car
{
private:
    int carNumber;
    bool loaded;
    string reportingMark, kind, destination;
public:
    Car()
    {
        setUp("", 0, "other", false, "NONE");
    }
    Car(const Car &c)
    {
        setUp(c.reportingMark, c.carNumber, c.kind, c.loaded, c.destination);
    }
    Car(string reportingMark, int carNumber, string kind, bool loaded, string destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    ~Car() {}
    friend bool operator==(const Car &car1, const Car &car2);
    void setUp(string reportingMark, int carNumber, string kind, bool loaded, string destination);
    void output();
    Car & operator=(const Car & carB);

};



class StringOfCars
{
private:
    static const int ARRAY_SIZE = 10;
    Car *ptr;
    int carCount;

public:
    StringOfCars()
    {
        ptr = new Car[ARRAY_SIZE];
        carCount = 0;
    }
    StringOfCars(const StringOfCars &c)
    {
        ptr = new Car[ARRAY_SIZE];
        carCount = c.carCount;
        for(int i = 0; i < ARRAY_SIZE; i++){
            ptr[i] = c.ptr[i];
        }
    }
    ~StringOfCars()
    {
        delete [] ptr;
    }
    void push(Car &c);
    void pop(Car &c);
    void output();
};

void input(StringOfCars &soc);


int main()
{
    cout << "Test 1:" << endl;
    Car car1("SP", 34567, "business", 1, "Salt Lake City");
    Car car2;
    car2 = car1;
    car2.output();

    cout << "\nTest 2:\n" << endl;
    StringOfCars string1;
    input(string1);
    cout << "STRING 1:" << endl;
    string1.output();

    cout << "\nTest 3:\n" << endl;
    Car car3;
    string1.pop(car3);
    cout << "CAR 3:" << endl;
    car3.output();
    cout << "\nSTRING 1:" << endl;
    string1.output();

}

/* **************************Car::setUp*********************************************
Takes 5 parameters by value: reporting mark, car number, kind, loaded, and destination
Inputs these paramaters into the Car class' variables
*/
void Car::setUp(string rm, int cn, string k, bool l, string d)
{

    reportingMark = rm, carNumber = cn, kind = k, loaded = l, destination = d;
}
/* **************************Car::output**********************************************
Prints the reporting mark, car number, kind, loaded, and destination in a neat format
*/
void Car::output()
{
    string isLoaded;
    if(loaded) isLoaded = "true";
    else isLoaded = "false";
    cout << "\nReporting Mark: \t" << reportingMark << "\nCar Number: \t\t" << carNumber << "\nKind: \t\t\t" << kind << "\nCar is loaded: \t\t" << isLoaded << "\nDestination: \t\t" << destination << endl;
}
/* **************************Car::operator=**********************************************
sets the values in the left hand object from the right hand object
*/
Car & Car::operator=(const Car & carB)
{
    setUp(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

    return * this;
}
/* **************************StringOfCars::output**********************************************
Prints out car objects in StringOfCars array
*/
void StringOfCars::output()
{
    if(carCount == 0) cout << "NO cars";

    for(int i = 0; i < carCount; i++)
    {
        cout << "Car Number: " << i + 1 << endl;
        ptr[i].output();
    }


}

/* **************************StringOfCars::push**********************************************
Adds car to StringOfCars array
*/
void StringOfCars::push(Car &c)
{
    if(carCount < ARRAY_SIZE)
    {
        ptr[carCount] = c;
        carCount++;
    }
    else cout << "Car array is full, cannot add car";
}

/* **************************StringOfCars::pop**********************************************
Removes car from StringOfCars array and saves it into a different car object
*/
void StringOfCars::pop(Car &c)
{
    if(carCount == 0) cout << "ERROR: No cars in String of Cars";
    else
    {
        c = ptr[carCount - 1];
        carCount--;
    }
}


/* **************************operator==**********************************************
Compares two car objects to see if they equal
*/
bool operator==(const Car &car1, const Car &car2)
{
    return (car1.reportingMark == car2.reportingMark && car1.carNumber == car2.carNumber);
}


/* **************************input**********************************************
Takes the reporting mark, car number, kind, loaded, and destination as value parameters
Values read from a text file
*/
void input(StringOfCars &soc)
{
    string reportingMark, kind, destination, carType;
    int carNumber;
    bool loaded;
    string loadedString;

    ifstream inputFile;
    inputFile.open("cardata.txt");
    if(!inputFile.is_open())
    {
        fprintf(stderr, "Error Opening File\n");
        exit(1);
    }
    while(inputFile.peek() != EOF)
    {

        inputFile >> carType >> reportingMark >> carNumber >> kind >> loadedString;
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
            Car temp(reportingMark, carNumber, kind, loaded, destination);
            soc.push(temp);
        }

        else
        {
            cout << "\nError: carType not 'Car'\n";
        }
    }
    inputFile.close();
}
