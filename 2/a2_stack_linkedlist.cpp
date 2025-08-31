/* Problem Statement:
"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management
Systems"
This problem involves designing and implementing queues and stacks using linked lists, focusing
on their practical applications in real-world scenarios such as:
• Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such
as print job scheduling or process management in an operating system.
• Undo/Redo Functionality (Stack): Implementing an undo/redo feature in text editors or
design software using a last-in, first-out (LIFO) approach. */


#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node(string val) {
        data=val;
        next=nullptr;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack() {
        top=nullptr;
    }

    void clear(){
        while(top!=nullptr) pop();
    }

    void push(string val) {
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
    }

    string pop() {
        string val;
        if(top==nullptr) {
            return "";
        }
        val=top->data;
        Node* temp=top;
        top=top->next;
        delete temp;
        return val;
    }

    string peek() {
        if(top==nullptr) {
            cout<<"Stack is empty\n";
            return "";
        }
        return top->data;
    }

    bool isEmpty() {
        return top==nullptr;
    }

    
};

class TextEditor{
    public:
    Stack undoStack;
    Stack redoStack;
    string content="";
    void show()
    {
        cout<<content<<endl;      
    }

    void undo()
    {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo\n";
            return;
        }
        redoStack.push(content);
        content = undoStack.pop();
    }

    void redo()
    {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo\n";
            return;
        }
        undoStack.push(content); 
        content = redoStack.pop();
    }

    void type(string s)
    {
        undoStack.push(content); 
        redoStack.clear();
        content += s;
    }
    
};

int main(){
    TextEditor editor;
    char loopcondn;
    cout<<"Welcome to the TextEditor\n-------------------------------------\n";
    cout<<"1.Add content\n";
    cout<<"2.Show content\n";
    cout<<"3.Undo\n";
    cout<<"4.Redo\n";
    int opt;
    do{
        cout<<"Choose a number from 1-4 to select an option: ";
        cin>>opt;
    switch(opt){
        case 1:{
            string str; 
            cout<<"Input content: ";
            cin>>str;
            editor.type(str);
        }
            break;
        case 2: editor.show();
            break;
        case 3: editor.undo();
            break;
        case 4: editor.redo();
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
    return 0;
}
