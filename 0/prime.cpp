#include<iostream>
using namespace std;

int main()
{
    int num, cnt=0;
    cout<<"Enter a positive number to check if it is prime or not: ";
    cin>>num;
    if(num>0)
    {
    for(int i=1;i<=num;i++)
    {
        if(num%i==0) cnt++;
    }

    if(cnt>2) cout<<"Not Prime\n";
    else cout<<"Prime\n";
    }
    else cout<<"Invalid Input\n";
    return 0;
}