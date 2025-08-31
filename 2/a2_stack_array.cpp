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
using namespace std;
#define max 10
class Stack
{
    public:
    int data[max];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(int val)
    {
        if(top==max-1){
             cout<<"Stack Overflow\n";
             return;
        }
        else 
        {
            top++;
            data[top]=val;
        }
    }

    void pop()
    {
        if (top==-1) {
            cout<<"Stack Underflow\n";
            return;
        }
        else
        {
            cout<<"Popped: "<<data[top]<<endl;
            top--; 
        }
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        else return data[top];
    }

    bool isEmpty() {
        return top==-1;
    }

    void display() {
        cout<<"Stack (top to bottom): ";
        for (int i=top;i>=0;i--) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
}



(((A+B)*C)-(D-E))$(F+G) 
