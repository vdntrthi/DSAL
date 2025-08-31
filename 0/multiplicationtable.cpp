#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter number for Multiplication Table: ";
    cin>>num;
    cout<<"The Multiplication Table of "<<num<<" is:\n";
    for(int i=0; i<=12; i++)
    {
        cout<<num<<"x"<<i<<"="<<num*i<<endl;
    }
}