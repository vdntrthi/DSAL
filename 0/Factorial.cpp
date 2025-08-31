#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    else return n*factorial(n-1);
}

int main()
{
    int num;
    cout<<"Enter number to find factorial: ";
    cin>>num;
    cout<<"Factorial is "<<factorial(num)<<endl;
    return 0;
}