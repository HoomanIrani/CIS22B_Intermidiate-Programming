/*
 Houman Irani
 Winter 2019
 Lab 4
 Problem 4.1
 This program creates 3 car object from the data in the file
 */
#include<iostream>
#include<string>
#include<fstream>
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
    
    friend bool operator==(const Car& a,const Car& b);
};
void input();
/* ******************** main ********************
 creates 3 car object and calls the other functions
 */
int main()
{
    input();
}
/* ******************** Car::output ********************
 Output all the data from the Object
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
void input()
{
    ifstream inputFile;
    string filename;
    cin>>filename;
    inputFile.open(filename.c_str());
    if(inputFile.is_open())
    {
        string a;
        string b;
        int c;
        string d;
        bool e;
        string f;
        while(inputFile.peek()!=EOF)
        {
            inputFile>>a;
            inputFile>>b;
            inputFile>>c;
            inputFile>>d;
            string load;
            inputFile>>load;
            if(load=="true")
            {
                e=1;
            }
            else
            {
                e=0;
            }
            while(inputFile.peek()==' ')
                inputFile.get();
            getline(inputFile,f);
            Car temp(b,c,d,e,f);
            temp.output();
        }
    }
    else
    {
        cout<<"file is not found"<<endl;
    }
    inputFile.close();
}
/* ******************** operator== ********************
 compares and see if two Car object's reportingMark and carNumber is equal
 */
bool operator==(const Car& a,const Car& b)
{
    return (a.reportingMark==b.reportingMark)&&(a.carNumber==b.carNumber);
}

