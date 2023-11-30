// Online C++ compiler to run C++ program online
// Vansh Gurnani
// 1032210790
// PC-25
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX=100;

class record{
    public:
        int roll;
        int marks;
};

class student{
    public:
        record data;
        int next;
        student(){
            next=-1;
        }
};

class filehandle{
    public:
    fstream file;
    filehandle(string filename){
        file.open(filename,ios::in|ios::out|ios::app);
    }
    void read(student &s){
        file.read((char *)&s,sizeof(student));
    }
    void write(student &s){
        file << "Roll No.: " << s.data.roll << endl;
        file << "Marks: " << s.data.marks << endl;
        file << "-----------" << endl;
    }
    int insert(student hashTable[], student s) {
    int key = s.data.roll;
    int loc = key % MAX;
    if (hashTable[loc].data.roll == -1) {
        hashTable[loc] = s;
        // write(s); // Write the student record to the file
        return (loc);
    } else {
        int i = (loc + 1) % MAX;
        while (i != loc) {
            if (hashTable[i].data.roll == -1) {
                hashTable[i] = s;
                // write(s); // Write the student record to the file
                return (i);
            }
            i = (i + 1) % MAX;
        }

        if (i == loc) {
            cout << "HASH TABLE IS FULL" << endl;
            return -1;
        }
    }
}

   
    int search(student hashTable[],int key){
        int loc=key%MAX;
        if(hashTable[loc].data.roll==key){
            cout<<"Key is Found"<<endl;
        }
        else{
            int i=(loc+1)%MAX;
            while(i!=loc){
                if(hashTable[i].data.roll==key){
                    cout<<"Key is Found"<<endl;
                }
                i=(i+1)%MAX;
            }
        if(i==loc){
            cout<<"KEY NOT FOUND"<<endl;
            return -1;
        }
       
    }
   
   
}

};

int main() {
    // Write C++ code here
    cout << "Hello world!";
    student hashTable[MAX];
   
    for(int i=0;i<MAX;i++){
        hashTable[i].data.roll=-1;
    }
    filehandle file("s2.txt");
    int choice;
    do{
        cout<<endl<<"The choices are:"<<endl<< "1. insert"<<endl<<"2. search"<<endl<<"3. exit"<<endl;
        cout<<"Enter the choices"<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                student s;
                cout << "\nEnter student details:" << endl;
                cout << "Roll No.: ";
                cin >> s.data.roll;
                cout << "Marks: ";
                cin >> s.data.marks;
                int loc = file.insert(hashTable, s);
                if (loc != -1) {
                    file.write(s);
                    cout << "Student record added successfully" << endl;
                }
                break;
            }
            case 2: {
                int rollNo;
                cout << "\nEnter roll no. to search: ";
                cin >> rollNo;
                int loc = file.search(hashTable, rollNo);
                if (loc != -1) {
                    student s;
                    file.read(s);
                } else {
                    cout << "\nStudent not found" << endl;
                }
                break;
            }

           
            case 3: {
                cout << "\nExiting program." << endl;
                file.file.close();
                break;
            }
            default: {
                cout << "\nInvalid choice. Please try again." << endl;
            }
        }
    }while(choice!=3);
    return 0;
}