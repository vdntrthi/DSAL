#include<iostream>
using namespace std;

int main()
{
    int term, p=0, q=1, r;
    cout<<"Enter upto which term you want Fibonacci Series: ";
    cin>>term;
    cout<<p<<endl<<q<<endl;
    for(int i=term-2; i>=1;i--)
    {
        r=p+q;
        p=q;
        q=r;
        cout<<r<<endl;
    }
    return 0;
}