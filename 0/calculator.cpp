#include<iostream>
using namespace std;
 int main()
 {
    int a, result, n1, n2;
    do{
        cout<<"Calculator Menu\n";
        cout<<"1. Addition\n";
        cout<<"2. Subtraction\n";
        cout<<"3. Multiplication\n";
        cout<<"4. Division\n";
        cout<<"Choose a valid option (1-4): ";
        cin>> a;
    }while(a>=4||a<=1);

    cout<<"Enter 2 Numbers for Calculation: ";
    cin>>n1>>n2;

    switch(a)
    {
        case 1: cout<<"Sum is "<<n1+n2;
                break;
        case 2: cout<<"Difference is "<<n1-n2;
                break;
        case 3: cout<<"Product is "<<n1*n2;
                break;
        case 4: if(n2!=0){
                cout<<"Quotient is "<<n1/n2<<endl;
                cout<<"Remainder is "<<n1%n2;
                }
                else cout<<"Second Number cannot be zero";
                break;
        default: break;     
    }
    cout<<endl;
    return 0;
 }