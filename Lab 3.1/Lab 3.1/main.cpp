/*
 Houman Irani
 Winter 2019
 Lab 3
 Problem 3.1
 This program gets data from the user and stores them in a class. It then
 output the data
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
};
void input(string& a,int& b,string& c,bool& d, string& e);
/* ******************** main ********************
 Creates a Car object and calls the other function
 */



int main()
{
    string reportingMarkM;
    int carNumberM;
    string kindM;
    bool loadedM;
    string destinationM="NONE";
    input( reportingMarkM,carNumberM,kindM,loadedM,destinationM);
    Car car1;
    car1.SetUp(reportingMarkM,carNumberM,kindM,loadedM,destinationM);
    car1.output();
}
/* ******************** Car::output ********************
 Output all the data from the class
 */



void Car::output()
{
    cout<<"The reportingMark is "<<reportingMark<<endl;
    cout<<"The car number is "<<carNumber<<endl;
    cout<<"The kind is "<<kind<<endl;
    cout<<"The loaded is "<<boolalpha<<loaded<<endl;
    cout<<"The destination is "<<destination<<endl;
}
/* ******************** Car::SetUp ********************
 Puts all the data from main to object
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
 asks the user for input and puts it in the variable in the
 main
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
