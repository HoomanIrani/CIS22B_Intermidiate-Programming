/*
Houman Irani
Winter 2019
Lab 1
Problem 1.1
Description of problem:
getSize -Ask user how many string they want
getSpace - puts an array on the heap of the size requested by the user
inputData - allows the user to input the strings and store them in the array
printData -prints all the strings,one string per line
destroy -returns all the space to the heap
ALL of these functions shall have a return of void
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void getSize (int *size);
void getSpace (string *&pStrArr, int );
void inputData (string *pStrArr, int size);
void printData (string *pStrArr, int size);
void destroy (string *pStrArr);
/* **********************main***********************
 calls other functions
*/
int main()
{
    int size;
    string *pStrArr;
    
    getSize(&size);
    
    getSpace(pStrArr,size);
    inputData(pStrArr,size);
    printData(pStrArr,size);
    destroy(pStrArr);
    
    return 0;
}
/* *******************getSize*************************
  Ask user how many strings they want
*/
void getSize (int *size)
{
    cout << "Enter the number of strings you want: ";
    cin >> *size;
    cin.ignore();
}
/* *******************getSpace***********************
 puts an array on the heap of the size requested by the user
 */
void getSpace (string *&pStrArr,int size)
{
    if(size <= 0)
    {
        exit(0);
    }
    pStrArr = new string[size];
}
/* ********************inputData***********************
  Allows the user to input the string and store them in the array
 */
void inputData (string *pStrArr, int size)
{
    for(int i=0;i<size;i++)
    {
        cout << "Enter the number " << i+1 << "string: ";
        getline(cin,pStrArr[i]);
    }
}
/* ******************printData**************************
 prints all the strings,one string per line
 */
void printData (string *pStrArr, int size)
{
    for(int j=0;j<size;j++)
    {
        cout << pStrArr[j] <<endl;
    }
}
/* *******************destroy*****************************
 returns all the space to the heap
 */
void destroy (string *pStrArr)
{
    delete [] pStrArr;
}






