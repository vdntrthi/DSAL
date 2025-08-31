#include<iostream>
using namespace std;

int main()
{
    int num, revnum=0;
    cout<<"Enter a number: ";
    cin>>num;
    do{
        revnum=revnum*10+num%10;
        num=num/10;
    }while(num%10!=0);
    cout<<"Reverse of the number entered is: "<<revnum;
    return 0;
}