
/*
 Houman Irani
 Winter 2019
 Lab 3
 Problem 3.2
 This program creates 3 Car from the 3 different constructors. It then
 output the data.
 */


#include<iostream>
#include<string>

using namespace std;



class Car
{
private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
public:
    void output();
    void SetUp(const string& a,const int& b,const string& c,const bool& d,const string& e);
    /* ******************** Car::Car ********************
     This the default constructor that set's reportingMark="",
     carNumber=0,kind="other",bool=0,destination="NONE"
     */
    Car()
    {
        SetUp("",0,"other",0,"NONE");
    }
    /* ******************** Car::Car ********************
     This is a copy constructor which copies one Car object into the other
     */
    Car(const Car& a)
    {
        reportingMark=a.reportingMark;
        carNumber=a.carNumber;
        kind=a.kind;
        loaded=a.loaded;
        destination=a.destination;
    }
    /* ******************** Car::Car ********************
     This is a constructor that accepts 5 parameter that would be
     stored into the variables inside the Object
     */
    Car(const string& a,const int& b,const string& c,const bool& d,const string& e)
    {
        SetUp(a,b,c,d,e);
    }
    
};





void input(string& a,int& b,string& c,bool& d, string& e);
/* ******************** main ********************
 creates 3 car object and calls the other functions
 */




int main()
{
    string reportingMarkM;
    int carNumberM;
    string kindM;
    bool loadedM;
    string destinationM="NONE";
    input(reportingMarkM,carNumberM,kindM,loadedM,destinationM);
    Car car1(reportingMarkM,carNumberM,kindM,loadedM,destinationM);
    Car car2=car1;
    Car car3;
    cout<<"content of car 1"<<endl;
    car1.output();
    cout<<"content of car 2"<<endl;
    car2.output();
    cout<<"content of car 3"<<endl;
    car3.output();
}
/* ******************** Car::output ********************
 Output all the data from the class
 */




void Car::output()
{
    cout<<"The reportingMark is: "<<reportingMark<<endl;
    cout<<"The car number is: "<<carNumber<<endl;
    cout<<"The kind is: "<<kind<<endl;
    cout<<"The loaded is: "<<boolalpha<<loaded<<endl;
    cout<<"The destination is: "<<destination<<endl;
}
/* ******************** Car::SetUp ********************
 Puts all data from main into the Car object
 */




void Car::SetUp(const string& a,const int& b,const string& c,const bool& d,const string& e)
{
    reportingMark=a;
    carNumber=b;
    kind=c;
    loaded=d;
    destination=e;
}
/* ******************** input ********************
 asks the user for input and puts it in the variables in main
 */




void input(string& a,int& b,string& c,bool& d, string& e)
{
    cout<<"Please enter reportingMark"<<endl;
    cin>>a;
    cout<<"Please enter carNumber"<<endl;
    cin>>b;
    cout<<"Please enter kind"<<endl;
    cin>>c;
    cout<<"Please enter true or false for loaded"<<endl;
    string load;
    cin>>load;
    if(load=="true")
    {
        d=1;
    }
    else
    {
        d=0;
    }
    cin.ignore();
    cout<<"Enter the destination"<<endl;
    getline(cin,e);
}
