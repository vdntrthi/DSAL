/*
Problem Statement:
Linked List
"Efficient Data Management Using Linked Lists: Implementing
Dynamic Operations for Contact Management System"
Utilize Singly and Doubly Linked Lists to manage a Contact
Management System. The system will support key operations such as:
• Creating a contact list dynamically.
• Adding new contacts efficiently.
• Deleting contacts when no longer needed.
• Searching for specific contacts based on name or number.
• Reversing the contact list for alternate viewing orders.
• Traversing through the list to display all stored contacts. 
 */

#include<iostream>
using namespace std;


class Contact{
    public:
    string name, email, gender, dob, phone;
};


class SNode{
    public:
    Contact data;
    SNode *next;
    SNode(Contact c)
    {
        data=c;
        next=nullptr;
    }
};
 

class CMS_SLL{
    SNode *head;
    public:
    Contact c;

    CMS_SLL()
    {
        head=nullptr;
    }

    void insert()
    {
        cout<<"Enter Name: ";
        getline(cin>>ws,c.name);
        cout<<"Enter Email ID: ";
        cin>>c.email;
        cout<<"Enter Phone Number: ";
        cin>>c.phone;
        cout<<"Enter DOB [Format:DDMMYYYY]: ";
        cin>>c.dob;
        cout<<"Enter Gender [M/F/T]: ";
        cin>>c.gender;
        SNode *SetData = new SNode(c);
        SNode *temp;
        if(head==nullptr)
        {
            head=SetData;
        }
        else{
            temp=head;
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=SetData;
            }
    }
   void display()
    {   
        SNode *temp;
        int cnt=1;
        if(head==nullptr)
        {
            cout<<"There is no data\n";
        }
        else{
        temp=head;
        while(temp!=nullptr)
        {
            cout<<cnt<<"\t";
            cout<<temp->data.name<<"\t";
            cout<<temp->data.email<<"\t";
            cout<<temp->data.phone<<"\t";
            cout<<temp->data.dob<<"\t";
            cout<<temp->data.gender<<"\n";
            cnt++;
            temp=temp->next;
        }
        }
    }

    void reverse()
    {
     SNode *curr=head;
     SNode *prev=nullptr;
     SNode *next=nullptr;

     while(curr!=nullptr)
     {
        next=curr->next;    
        curr->next=prev;    
        prev=curr;          
        curr=next;          
     }
     head=prev;
     display();
    }

    void search(string s, int opt)
    {
        SNode *temp;
         if(head==nullptr)
        {
            cout<<"There is no data\n";
        }
        else{
        temp=head;
        bool found=false;
        switch(opt)
        {
            case 1: while(temp!=nullptr)
            {
                if(temp->data.name==s)
                {
                    cout<<temp->data.name<<"\t"<<temp->data.email<<"\t"<<temp->data.phone<<"\t"<<temp->data.dob<<"\t"<<temp->data.gender<<endl;
                    found=true;
                }
                temp=temp->next;
            }
            break;
            case 2: while(temp!=nullptr)
            {
                if(temp->data.email==s) 
                {
                    cout<<temp->data.name<<"\t"<<temp->data.email<<"\t"<<temp->data.phone<<"\t"<<temp->data.dob<<"\t"<<temp->data.gender<<endl;
                    found=true;
                }
                temp=temp->next;
            }
            break;
            case 3: while(temp!=nullptr)
            {
                if(temp->data.phone==s)
                 {
                    cout<<temp->data.name<<"\t"<<temp->data.email<<"\t"<<temp->data.phone<<"\t"<<temp->data.dob<<"\t"<<temp->data.gender<<endl;
                    found=true;
                 }
                temp=temp->next;
            }
            break;
            case 4: while(temp!=nullptr)
            {
                if(temp->data.dob==s)
                {
                    cout<<temp->data.name<<"\t"<<temp->data.email<<"\t"<<temp->data.phone<<"\t"<<temp->data.dob<<"\t"<<temp->data.gender<<endl;
                    found=true;
                }
                temp=temp->next;
            }
            break;
            default: break;
        }
        if (!found)
        {
            cout << "No data found\n";
        }
        }
    }

    void deletion(string s, int opt)
{
    if(head == nullptr) {
        cout << "There is no data to delete\n";
        return;
    }

    SNode *temp = head, *prev = nullptr;

    switch(opt)
    {
        case 1:
            while(head!=nullptr&&head->data.name==s) {
                temp=head;
                head=head->next;
                delete temp;
            }
            temp=head;
            prev=nullptr;
            while(temp!=nullptr) {
                if(temp->data.name == s) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cout<<"\nData was deleted.\nUpdated List:";
            display();

            break;
            
        case 2:
            while(head != nullptr && head->data.email == s) {
                temp = head;
                head = head->next;
                delete temp;
            }
            temp = head;
            prev = nullptr;
            while(temp != nullptr) {
                if(temp->data.email == s) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cout<<"\nData was deleted.\nUpdated List:";
            display();
            break;

        case 3:
            while(head != nullptr && head->data.phone == s) {
                temp = head;
                head = head->next;
                delete temp;
            }
            temp = head;
            prev = nullptr;
            while(temp != nullptr) {
                if(temp->data.phone == s) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cout<<"\nData was deleted.\nUpdated List:";
            display();
            break;
        case 4:
            while(head != nullptr && head->data.dob == s) {
                temp = head;
                head = head->next;
                delete temp;
            }
            temp = head;
            prev = nullptr;
            while(temp != nullptr) {
                if(temp->data.dob == s) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cout<<"\nData was deleted.\nUpdated List:";
            display();
            break;

        default: cout << "Invalid deletion parameter\n"; break;
    }
}
};

int main(){
    CMS_SLL data;
    int opt;
    string str;
    char loopcondn;
    cout<<"Menu\n";
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Display\n";
    cout<<"4.Search\n";
    cout<<"5.Reverse\n";
    do{
        cout<<"Choose a number from 1-6 to select an option: ";
        cin>>opt;
        switch(opt)
        {
            case 1: data.insert();
                break;
            case 2:  cout<<"What parameter do you want to delete using?\n";
                     cout<<"Menu\n";
                     cout<<"1.Name\n";
                     cout<<"2.Email\n";
                     cout<<"3.Phone\n";
                     cout<<"4.DOB\n";
                     cin>>opt;
                     cout<<"Enter key:";
                     cin>>str;
                     data.deletion(str, opt);
                break;
            case 3: data.display();
                break;
            case 4:  cout<<"What parameter do you want to search using?\n";
                     cout<<"Menu\n";
                     cout<<"1.Name\n";
                     cout<<"2.Email\n";
                     cout<<"3.Phone\n";
                     cout<<"4.DOB\n";
                     cin>>opt;
                     cout<<"Enter key:";
                     cin>>str;
                     data.search(str, opt);
                break;
            case 5: data.reverse();
               break;
           default: cout<<"Invalid Input"; 
                 break;
        }
        cout<<"\nDo you want to continue?[y/n]";
        cin>>loopcondn;
        while(loopcondn != 'y' && loopcondn != 'n')
        {
         cout << "Invalid Input, enter again\n";
         cin>>loopcondn;
        }
        if (loopcondn=='n') break;

    }while(loopcondn=='y');

}



/*pict@a330404-OptiPlex-5000:~/Desktop/23269_DSA/1$ cd "/home/pict/Desktop/23269_DSA/1/" && g++ a1_p1.cpp -o a1_p1 && "/home/pict/Desktop/23269_DSA/1/"a1_p1
Menu
1.Insert
2.Delete
3.Display
4.Search
5.Reverse
Choose a number from 1-6 to select an option: 1
Enter Name: Vedant
Enter Email ID: rathi@gmail.com
Enter Phone Number: 9503985700
Enter DOB [Format:DDMMYYYY]: 30042006
Enter Gender [M/F/T]: M

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 1
Enter Name: Siddhant
Enter Email ID: rajput@gmail.com
Enter Phone Number: 9503990789
Enter DOB [Format:DDMMYYYY]: 24022006
Enter Gender [M/F/T]: M

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 1
Enter Name: Simba
Enter Email ID: simb@gmail.com
Enter Phone Number: 9875455642
Enter DOB [Format:DDMMYYYY]: 20022005
Enter Gender [M/F/T]: M

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 1
Enter Name: Aarush
Enter Email ID: oak@gmail.com
Enter Phone Number: 9566554266
Enter DOB [Format:DDMMYYYY]: 28062006
Enter Gender [M/F/T]: M

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 1
Enter Name: Siya
Enter Email ID: sinnk@gmail.com
Enter Phone Number: 8765323054
Enter DOB [Format:DDMMYYYY]: 13052007
Enter Gender [M/F/T]: F

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 3
1       Vedant  rathi@gmail.com 9503985700      30042006        M
2       Siddhant        rajput@gmail.com        9503990789      24022006        M
3       Simba   simb@gmail.com  9875455642      20022005        M
4       Aarush  oak@gmail.com   9566554266      28062006        M
5       Siya    sinnk@gmail.com 8765323054      13052007        F

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 4
What parameter do you want to search using?
Menu
1.Name
2.Email
3.Phone
4.DOB
2
Enter key:oak@gmail.com
Aarush  oak@gmail.com   9566554266      28062006        M

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 4
What parameter do you want to search using?
Menu
1.Name
2.Email
3.Phone
4.DOB
1
Enter key:Ram
No data found

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 2
What parameter do you want to delete using?
Menu
1.Name
2.Email
3.Phone
4.DOB
1
Enter key:Aarush
Data was deleted.
Updated List:
1       Vedant  rathi@gmail.com 9503985700      30042006        M
2       Siddhant        rajput@gmail.com        9503990789      24022006        M
3       Simba   simb@gmail.com  9875455642      20022005        M
4       Siya    sinnk@gmail.com 8765323054      13052007        F

Do you want to continue?[y/n]y
Choose a number from 1-6 to select an option: 5
1       Siya    sinnk@gmail.com 8765323054      13052007        F
2       Simba   simb@gmail.com  9875455642      20022005        M
3       Siddhant        rajput@gmail.com        9503990789      24022006        M
4       Vedant  rathi@gmail.com 9503985700      30042006        M

Do you want to continue?[y/n]n
*/