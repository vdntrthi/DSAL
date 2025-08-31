/*Problem Statement:
Consider a student database of SEIT class (at least 15 records). Database
contains different fields of every student like Roll No, Name and SGPA.
(array of structure)
a) Design a roll call list, arrange list of students according to roll
numbers in ascending order (Use Bubble Sort)
b) Arrange a list of students alphabetically. (Use Insertion sort)
c) Arrange a list of students to find out the first ten toppers from a class.
(Use Quick sort)
d) Search for students according to SGPA. If more than one student has
the same SGPA, then print a list of all students having the same SGPA.
e) Search for a particular student according to name using binary search
without recursion. (all the student records having the presence of search
key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
*/

#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

struct Student{
    string name;
    int rollno;
    float cgpa;
};

class SYIT{
    struct Student s[5];
    public:
    void getData(){
        for(int i=0;i<5;i++){
            cout<<"Enter name: ";
            cin>>s[i].name;
            cout<<"Enter roll no: ";
            cin>>s[i].rollno;
            cout<<"Enter CGPA: ";
            cin>>s[i].cgpa;
        }
    }

    void display(){
        cout<<"Name\t\tRoll Number\t\t CGPA"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        
        for(int i=0;i<5;i++){
            cout<<s[i].name<<"\t\t"<<s[i].rollno<<"\t\t\t"<<s[i].cgpa<<endl;
        }
        cout<<"-----------------------------------------------------"<<endl;
    }

    void displaytoppers(){
        cout<<"Name\t\tRoll Number\t\t CGPA"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        
        for(int i=0;i<3;i++){
            cout<<s[i].name<<"\t\t"<<s[i].rollno<<"\t\t\t"<<s[i].cgpa<<endl;
        }
        cout<<"-----------------------------------------------------"<<endl;
    }

    void bubbleSort(){
        struct Student temp;
            for(int i=0;i<5;i++){
                for(int j=0;j<5-i-1;j++){
                    if(s[j].rollno>s[j+1].rollno){
                        temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }
                }
            }
    }

    void insertionSort(){
        struct Student temp;
        int j;
        for(int i=1;i<5; i++)
        {
           temp=s[i];
           j=i-1;
           while(j>=0 && s[j].name>temp.name)
           {
                s[j+1]=s[j];
                j--;
           }
            s[j+1]=temp;
        }
    }

    int partition(int low, int high) {
        float pivot=s[low].cgpa;
        int i=low+1;
        int j=high;

        while (i<=j) {
            while (i<=high && s[i].cgpa>pivot) i++;
            while (j>=low && s[j].cgpa<pivot) j--;
            if (i<j) {
                swap(s[i],s[j]);
            }
        }
        swap(s[low],s[j]);
        return j;
    }

    void quickSort(int beg,int end){
        if (beg<end){
            int p=partition(beg, end);
            quickSort(beg,p-1);
            quickSort(p+1,end);
        }
    }

    void linearSearch(){
        struct Student temp;
        float key;
        int count;
            cout<<"Enter the CGPA of which details you want";
            cin>>key;
            cout<<"Name\t\tRoll Number\t\t CGPA"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
                for(int i=0;i<5;i++){
                        if(key==s[i].cgpa){
                        cout<<s[i].name<<"\t\t"<<s[i].rollno<<"\t\t\t"<<s[i].cgpa<<endl;
                        count++;
                    }
            }

                if(count==0){
                    cout<<"No match found."<<endl;
                }
            cout<<"-----------------------------------------------------"<<endl;
    }

    void binarySearch(string val){
        insertionSort();
        struct Student temp;
        int i=0;
        int beg=0, mid, end=4;
        do{
            mid=(beg+end)/2;
            if(val>s[mid].name){
                beg=mid+1;
            }
            if(val<s[mid].name){
                end=mid-1;
            }
            if(val==s[mid].name){
                cout<<"Data Found:\n";
                cout<<"Name\t\tRoll Number\t\t CGPA"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<s[mid].name<<"\t\t"<<s[mid].rollno<<"\t\t\t"<<s[mid].cgpa<<endl;
                i++;
                break;
            }
        }while(beg<=end);
        if(i==0) cout<<"Data is not found. \n";
    }
};

int main(){
    char opt;
    SYIT s10;
    string n;
    cout<<"Enter Details: "<<endl;
    s10.getData();

    cout<<"Student's Data: "<<endl;
    s10.display();

    int choice;
    do{
        cout<<"1. Sorting by roll number using bubble sort\n";
        cout<<"2. Sorting by name using insertion sort\n";
        cout<<"3. Sorting by CGPA using quick sort\n";
        cout<<"4. Searching by CGPA using Linear Search \n";
        cout<<"5. Searching by name using Binary Search\n";
        cout<<"Enter one of the above choices.";
        cin>>choice;

        switch(choice){
            case 1:s10.bubbleSort();
            cout<<"Sorted all by roll numbers: \n";
            s10.display();
            break;

            case 2:s10.insertionSort();
                   s10.display();
            break;

            case 3:s10.quickSort(0,4);
                   s10.displaytoppers();
            break;

            case 4:s10.linearSearch();
            break;

            case 5: cout<<"Enter Name Key: ";
                    cin>>n;
                    s10.binarySearch(n);
                    break;
            default: 
            cout<<"Enter a valid choice.";
            break;
        }
        cout<<"Press y if you want to continue or any other key to exit: ";
        cin>>opt;
    }
    while(opt=='y');

    return 0;
}
