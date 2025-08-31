/*
Problem Statement:
Linked List
"Efficient Data Management Using Linked Lists: Implementing
Dynamic Operations for Library Management System"
Utilize Doubly Linked Lists to manage a Library
Management System. The system will support key operations such as:
• Creating a library list dynamically.
• Adding new books efficiently.
• Deleting books when no longer needed.
• Searching for specific books based on name or author.
• Reversing the book list for alternate viewing orders.
• Traversing through the list to display all stored books in library. 
 */

#include<iostream>
#include<iomanip>
using namespace std;


class Book{
    public:
    string name, author, pages, price;
};


class DNode{
    public:
    Book data;
    DNode *next, *prev;
    DNode(Book c)
    {
        data=c;
        next=nullptr;
        prev=nullptr;
    }
};
 

class LMS_DLL{
    DNode *head;
    public:
    Book c;

    LMS_DLL() {
        head=nullptr;
    }

    ~LMS_DLL()
    {
    DNode* current=head;
    while (current!=nullptr)
        {
            DNode* nextNode=current->next;
            delete current;
            current=nextNode;
        }
        head=nullptr;
    }

    void create()
    {
        cout<<"Enter Book Name: ";
        getline(cin>>ws,c.name);
        cout<<"Enter Book Author: ";
         getline(cin>>ws,c.author);
        cout<<"Enter No. of Pages: ";
        cin>>c.pages;
        cout<<"Enter Book Price: ";
        cin>>c.price;
        head=new DNode(c);
    }

    void insert_at_beg(Book b)
    {
        DNode *SetData=new DNode(b);
        if (head != nullptr)
        {
            head->prev=SetData;
            SetData->next=head;
            head=SetData;        
        } 
    }

    void insert_at_end(Book b)
    {
        DNode *SetData=new DNode(b);
        if (head==nullptr)
        {
            head=SetData;
            return;
        }
        DNode *temp;
        temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=SetData;
        SetData->prev=temp;
    }

    void insert_at_pos(Book b, int pos)
    {
        if(pos<=0){
            cout<<"Invalid Position Entered\n";
            return;
        }
        if(pos==1){
            insert_at_beg(b);
            return;
        }
        DNode *SetData=new DNode(b);
        DNode *temp=head;
        int i=1;
        while(i<pos-1 && temp!=nullptr)
        {
            temp=temp->next;
            i++;
        }
        if(temp==nullptr)
        {
            cout<<"Location is out of bounds.\n";
        }
        else
        {
            SetData->prev=temp;
            SetData->next=temp->next;
            temp->next=SetData;
        }
        if(SetData->next!=nullptr){
                SetData->next->prev = SetData;
        }
    }

    void search(string s, int opt)
    {
        DNode *temp;
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
                    cout<<temp->data.name<<"\t"<<temp->data.author<<"\t"<<temp->data.pages<<"\t"<<temp->data.price<<endl;
                    found=true;
                }
                temp=temp->next;
            }
            break;
            case 2: while(temp!=nullptr)
            {
                if(temp->data.author==s) 
                {
                    cout<<temp->data.name<<"\t"<<temp->data.author<<"\t"<<temp->data.pages<<"\t"<<temp->data.price<<endl;
                    found=true;
                }
                temp=temp->next;
            }
            break;
            case 3: while(temp!=nullptr)
            {
                if(temp->data.pages==s)
                 {
                    cout<<temp->data.name<<"\t"<<temp->data.author<<"\t"<<temp->data.pages<<"\t"<<temp->data.price<<endl;
                    found=true;
                 }
                temp=temp->next;
            }
            break;
            case 4: while(temp!=nullptr)
            {
                if(temp->data.price==s)
                {
                    cout<<temp->data.name<<"\t"<<temp->data.author<<"\t"<<temp->data.pages<<"\t"<<temp->data.price<<endl;
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

    void traverse_fwd()
    {
        DNode *temp;
        int cnt=1;
        temp=head;
        cout<<setw(8)<<"&NULL\n";
        while(temp!=nullptr)
        {
            cout<<setw(8)<<cnt;
            cout<<setw(15)<<temp->data.name;
            cout<<setw(15)<<temp->data.author;
            cout<<setw(8)<<temp->data.pages;
            cout<<setw(10)<<fixed<<setprecision(2)<<temp->data.price;;
            
            if(temp->next!=nullptr)
            cout<<setw(1)<<setw(7)<<"&"<<(cnt+1)<<endl;
        else
            cout<<setw(8)<<"&NULL"<<endl;

        temp=temp->next;
        cnt++;
        }
    }

    void traverse_bwd()
    {
        DNode *temp, *prev;
        int cnt=1;
        temp=head;
        while(temp->next!=nullptr) 
        {
            temp=temp->next;
        }
        prev=temp;
        while(prev!=nullptr)
        {
            cout<<cnt<<"\t";
            cout<<prev->data.name<<"\t";
            cout<<prev->data.author<<"\t";
            cout<<prev->data.pages<<"\t";
            cout<<prev->data.price<<"\n";
            cnt++;
            prev=prev->prev;
        }
        }

        void delete_head()
        {
            DNode *temp;
            if(head==nullptr) 
            {
                cout<<"List is empty\n";
                return;
            }
            temp=head;
            head=head->next;
            if(head!=nullptr) head->prev=nullptr;
            delete temp;
        }


        void delete_end()
        {
            if (head==nullptr)
            {
                cout<<"List is empty\n";
                return;
            }
            if(head->next==nullptr) 
            {
                delete head;
                head=nullptr;
            }
            else
            {
                DNode *temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->prev->next=nullptr;
                delete temp;
            }
        }

        void delete_at_pos(int pos)
        {
            DNode *curr;
            if(head==nullptr) 
            {
                cout<<"List is empty\n";
                return;
            }
            curr=head;
            for(int i=1;curr!=nullptr&&i<pos;i++)
            {
                curr=curr->next;
            }
            if(curr==nullptr)
            {
                cout<<"Position is out of bounds.\n";
                return;
            }
            if(curr->prev!=nullptr) curr->prev->next=curr->next;
            else head=curr->next;
            if(curr->next!=nullptr) curr->next->prev=curr->prev;
            delete curr;            
        }

        void reverse_dll()
        {
            DNode *curr=head, *temp=nullptr;
            if(head==nullptr)
            {
                cout<<"List is empty\n";
                return;
            }
            while(curr!=nullptr){
                temp=curr->next;
                curr->next=curr->prev;
                curr->prev=temp;
                curr=curr->prev;
            }            
            if(temp!=nullptr) head=temp->prev;

            cout<<"Book List successfully reversed\n";
            cout<<"When traversing forward:\n";
            traverse_fwd();
            cout<<"\nWhen traversing backward:\n";
            traverse_bwd();
        }
};

int main(){
    LMS_DLL data;
    int opt;
    string str;
    Book b;
    cout<<"Welcome to Library Management System\n\nTo get started, enter the details of the first book:\n\n";
    data.create();
    char loopcondn;
    cout<<"\nMenu\n";
    cout<<"1.Insert\n";
    cout<<"2.Traverse\n";
    cout<<"3.Search\n";
    cout<<"4.Delete\n";
    cout<<"5.Reverse\n";
    do{
        cout<<"Choose a number from 1-5 to select an option: ";
        cin>>opt;
        switch(opt)
        {
            case 1: cout<<"\nEnter Book Name: ";
                    getline(cin>>ws,b.name);
                    cout<<"Enter Book Author: ";
                     getline(cin>>ws,b.author);
                    cout<<"Enter No. of Pages: ";
                    cin>>b.pages;
                    cout<<"Enter Book Price: ";
                    cin>>b.price;

                    cout<<"\nWhere do you want to insert data?\n";
                    cout<<"1.Beginning\n2.End\n3.Position\n";
                    cin>>opt;
                    if(opt==1) data.insert_at_beg(b);
                    else if(opt==2) data.insert_at_end(b);
                    else if(opt==3) 
                    {
                        cout<<"\nEnter position at which you want to insert the data:";
                        int pos;
                        cin>>pos;
                        data.insert_at_pos(b, pos);
                    }
                    else cout<<"\nInvalid Option Chosen\n";
                    break;

            case 2: cout<<"Do you want to traverse forwards or backwards?\n";
                    cout<<"1.Forward\n2.Backward\nChoose an Option: ";
                    cin>>opt;
                    if(opt==1) data.traverse_fwd();
                    else if(opt==2) data.traverse_bwd();
                    else cout<<"\nInvalid Option Chosen\n";
                    break;

            case 3:  cout<<"What parameter do you want to search using?\n";
                     cout<<"Menu\n";
                     cout<<"1.Book Name\n";
                     cout<<"2.Book Author\n";
                     cout<<"3.Book Pages\n";
                     cout<<"4.Book Price\n";
                     cin>>opt;
                     cout<<"Enter key:";
                     cin>>str;
                     data.search(str, opt);
                break;
                
            case 4: cout<<"\nAt which position do you want to delete data?\n";
                    cout<<"1.Beginning\n2.End\n3.Position\n";
                    cin>>opt;
                    if(opt==1) data.delete_head();
                    else if(opt==2) data.delete_end();
                    else if(opt==3) 
                    {
                        cout<<"\nEnter position at which you want to delete the data:";
                        int pos;
                        cin>>pos;
                        data.delete_at_pos(pos);
                    }
                    else cout<<"\nInvalid Option Chosen\n";
                    break;
                
            case 5: data.reverse_dll();
                    break;

           default: cout<<"Invalid Input"; 
                 break;
        }
        cout<<"\nDo you want to continue?[y/n]";
        cin>>loopcondn;
        while(loopcondn!='y' && loopcondn!='n')
        {
         cout<<"Invalid Input, enter again\n";
         cin>>loopcondn;
        }
        if (loopcondn=='n') break;

    }while(loopcondn=='y');
    return 0;

}



