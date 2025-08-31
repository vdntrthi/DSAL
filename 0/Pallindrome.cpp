#include<iostream>
using namespace std;

int main()
{
    int temp, num, revnum=0;
    cout<<"Enter a number: ";
    cin>>num;
    temp=num;
    do{
        revnum=revnum*10+num%10;
        num=num/10;
    }while(num%10!=0);
    if(temp==revnum) cout<<"It's a Pallindrome\n";
    else cout<<"It's not a Pallindrome\n";
    return 0;
}