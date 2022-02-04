/*
 Houman Irani
 Winter 2019
 Lab 2
 Problem 2.2
 This program gets data from the user and stores them in a class. It then
 output the data
 */




#include<iostream>
#include<string>
using namespace std;



class Car
{
public:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination="NONE";
    /* ******************** SetUpCar ********************
     Puts all the data collected from the user into the class
     */
   
    
    
    
    void SetUpCar(string a,int b,string c,bool d,string e)
    {
        reportingMark=a;
        carNumber=b;
        kind=c;
        loaded=d;
        destination=e;
    }
};


void input(Car* b);

void output(Car* b);
/* ******************** main ********************
 Dynamically allocates a car object and calls the
 other functions and delete the object at the end of the program
 */



int main()
{
    Car*a= new Car;
    input(a);
    output(a);
    delete a;
    a=0;
}
/* ******************** input ********************
 asks the user for input and after all the input is collected it
 calls the SetUpCar function
 */



void input(Car* b)
{
    
    
    string inputReportingMark;
    int inputCarNumber;
    string inputKind;
    bool inputLoaded;
    string inputDestination="NONE";
    cout<<"Please enter reportingMark"<<endl;
    cin>>inputReportingMark;
    cout<<"Please enter carNumber"<<endl;
    cin>>inputCarNumber;
    cout<<"Please enter kind"<<endl;
    cin>>inputKind;
    cout<<"Please enter true or false for loaded"<<endl;
    string load;
    cin>>load;
   
   
    if(load=="true")
    {
        inputLoaded=1;
    }
    
   
    else
    {
        inputLoaded=0;
    }
    cout<<"Enter the destination"<<endl;
    cin.ignore();
    getline(cin,inputDestination);
    (*b).SetUpCar(inputReportingMark,inputCarNumber,inputKind,inputLoaded,inputDestination);
    
}
/* ******************** output ********************
 Output all the data from the structure
 */




void output(Car* b)

{
    cout<<"The reportingMark is "<<(*b).reportingMark<<endl;
    cout<<"The car number is "<<(*b).carNumber<<endl;
    cout<<"The kind is "<<(*b).kind<<endl;
    cout<<"The loaded is "<<boolalpha<<(*b).loaded<<endl;
    cout<<"The destination is "<<(*b).destination<<endl;
}
