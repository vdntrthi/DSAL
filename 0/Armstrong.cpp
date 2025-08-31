#include<iostream>
using namespace std;

int main()
{
    int temp, num, arm=0, i;
    cout<<"Enter a number: ";
    cin>>num;
    temp=num;
    do{
        i=num%10;
        arm=arm+i*i*i;
        num=num/10;
    }while(num%10!=0);
    if(temp==arm) cout<<"It's an Armstrong Number\n";
    else cout<<"It's not an Armstrong Number\n";
    return 0;
}