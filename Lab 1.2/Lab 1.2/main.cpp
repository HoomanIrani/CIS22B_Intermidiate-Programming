/*
 Houman Irani
 Winter 2019
 Lab 1
 Problem 1.2
 Description of problem:
 Exercise 1:read a input from the user and put it into string1
 Exercise 2:create a string called string2 and append " sleepy head" to it
 Exercise 3:create a string named string3 with an initial value
            find the column number of the first "h" in string3
 Exercise 4:create an empty string named string4 and copy string3 into it
            change the first "h" into "j"
 Exercise 5:create a copy of string3 named string5
            use the find last_of member function to find the position of the last "y"
 Exercise 6:create a string named string6 that contains the content of string3 erase all chracter following the last "y"

 */


#include<iostream>
#include<string>


using namespace std;



int main()
{
/* *****************************Exercise 1**************************
 Read a input from the user and put it into string1
 */
    
    string string1;
    getline (cin,string1);
    cout << "Exercise 1" << endl;
    cout << string1 << endl;
/* ****************************Exercise 2***************************
 create a string called string2 and append " sleepy head" to it
*/
    string string2;
    string2 = string1;
    string2.append(" sleepy heads");
    cout << "Exercise 2" << endl;
    cout << string2 << endl;
/* **************************Exercise 3*****************************
 create a string named string3 with an initial value
 find the column number of the first "h" in string3
 */
    string string3;
    string3 = "bello cello fellow hello mellow Novello Othello pillow Rollo solo yello";
    cout << "Exercise 3" << endl;
    cout << "The first h is at " << (string3.find_first_of("h")) << endl;
/* ***********************Exercise 4******************************
 create a string named string4 and copy string3 into it
 change the first "h" into "j"
 */
    
    string string4;
    string4 = string3;
    string4.replace((string3.find_first_of("h")),1,"j");
    cout << "Exercise 4" << endl;
    cout << string4 << endl;
/* ************************Exercise 5******************************
 create a copy of string3 named string5
 use the first last_of member function to find the position of the last "y"
*/
    string string5;
    string5 = string3;
    cout << "Exercis 5" << endl;
    cout << string5.find_last_of("y") << endl;
/* ***********************Exercise 6********************************
 create a string named string6 that contains the content of string3
 erase all characters following the last "y"
 */
    string string6;
    string6 = string3;
    string6.erase(string6.find_last_of("y")+1);
    cout << "Exercise 6" <<endl;
    cout << string6;
    
    
    return 0;
}
