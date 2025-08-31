#include<iostream>
using namespace std;

int main()
{
    int year;
    cout<<"Enter a Year to check if it is a leap year or not: ";
    cin>>year;
    if(year%100==0 && year%400==0)
    {
        cout<<"It is a leap year\n";
    }
    else if(year%4==0) 
    {
        cout<<"It is a leap year\n";
    }
    else
    {
        cout<<"It is not a leap year\n";
    }
    return 0;
}