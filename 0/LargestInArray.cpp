#include<iostream>
using namespace std;

int main()
{
    int num[10], largest;
    cout<<"Enter 10 elements in the array: \n";
    for(int i=0;i<10;i++)
    {
        cin>>num[i];
    }
    cout<<"The array elements are: \n";
    for(int i=0;i<10;i++)
    {
        cout<<num[i]<<endl;
    }
    largest=num[0];
    for(int i=0;i<9;i++)
    {
        if(num[i]<num[i+1]) largest=num[i+1];
    }
    cout<<"Largest element of the array is: "<<largest;
    return 0;
}