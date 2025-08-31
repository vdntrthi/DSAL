#include<iostream>
using namespace std;

int max(int n1, int n2)
{
    if(n1>n2){
        return n1;
    }
    else return n2;
}

int main()
{
    int n1, n2;
    cout<<"Enter 2 numbers: ";
    cin>>n1>>n2;
    cout<<"Maximum of the two numbers is: "<<max(n1,n2)<<endl;
    return 0;
}