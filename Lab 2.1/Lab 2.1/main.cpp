/*
 Houman Irani
 Winter 2019
 Lab 2
 Problem 2.1
 This program gets data from the user and stores them in a structure. It then
 output the data
 */




#include<iostream>
#include<string>
using namespace std;



struct Car
{
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination="NONE";
};




void input(Car* carPtr);


void output(Car* carPtr);
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
 asks user for input and after all the data is collected. The data
 is stored in the structure
 */

void input(Car* carPtr)
{
    
    
    string IreportingMark;
    int IcarNumber;
    string Ikind;
    bool Iloaded;
    string Idestination="NONE";
    cout<<"Please enter reportingMark"<<endl;
    cin>>IreportingMark;
    cout<<"Please Enter carNumber"<<endl;
    cin>>IcarNumber;
    cout<<"Please enter kind could be box, tank, flat, or other"<<endl;
    cin>>Ikind;
    cout<<"Please enter true or false for loaded"<<endl;
    string load;
    cin>>load;
   
    
    if(load=="true")
    {
        Iloaded=1;
    }
   
    
    else
    {
        Iloaded=0;
    }
    cout<<"Please enter the destination"<<endl;
    cin.ignore();
    getline(cin,Idestination);
    (*carPtr).reportingMark=IreportingMark;
    carPtr->carNumber=IcarNumber;
    carPtr->kind=Ikind;
    carPtr->loaded=Iloaded;
    carPtr->destination=Idestination;
}




/* ******************** output ********************
 Output all the data from the structure
 */


void output(Car* carPtr)
{
    cout<<"The reportingMark is "<<(carPtr->reportingMark)<<endl;
    cout<<"The car number is "<<(carPtr->carNumber)<<endl;
    cout<<"The kind is "<<(carPtr->kind)<<endl;
    cout<<"The loaded is "<<boolalpha<<(carPtr->loaded)<<endl;
    cout<<"The destination is "<<(carPtr->destination)<<endl;
}
