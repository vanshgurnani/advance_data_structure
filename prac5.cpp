#include <iostream>
#include <string>

using namespace std;

class gnode{
    string name;
    gnode* next;
    friend class graph;
};

class graph{
    gnode* head[20];
    int n;

    public:
    graph(){
        string str;
        cout << endl << "Enter number of vertices: ";
        cin >> n;
        for (int i=0; i<n; i++){
            cout << endl << "Enter name: ";
            cin >> str;
            head[i] = new gnode();
            head[i]->name = str;
            head[i]->next = NULL;
        }
    }

    void create();
    void disp();
    void nonrec_dft();
};

class queue{
    gnode *q[30];
    int front, rear;

    public:
    queue(){
        front = rear = -1;
    }

    void enque(gnode*);
    gnode* deque();
    int empty();
};

void queue::enque(gnode* temp){
    rear++;
    q[rear] = temp;
}

gnode* queue::deque(){
    front++;
    return(q[front]);
}

int queue::empty(){
    if (front == rear)
        return 1;
    else
        return 0;
}

class stack{
    int top;
    gnode *s[30];

    public:
    stack(){
        top = -1;
    }

    void push(gnode*);
    gnode *pop();
    int empty();
    friend class binarytree;

};

void stack::push(gnode *temp){
    top++;
    s[top]= temp;
}

gnode* stack::pop(){
    if (top == -1){
        cout << "Stack is Empty";
        return NULL;
    }
    else{
        gnode *temp = s[top];
        top--;
        return temp;
    }
}

int stack::empty(){
    if (top == -1)
        return 1;
    else
        return 0;
}


void graph::create(){
    gnode* temp;
    char ch;
    for(int i=0; i<n; i++){
        temp = head[i];
        do
        {
            string v;
            cout << endl << "Enter friend name of " << head[i]->name << ": ";
            cin >> v;
            if(v == head[i]->name){
                cout << "Self loop is not allowed";
            }
            gnode* curr = new gnode();
            curr->name = v;
            curr->next = NULL;
            temp->next = curr;
            temp = curr;
            cout << endl << "Do you wish to continue?";
            cin >> ch;
        } while (ch == 'y');
    }
}

void graph::disp(){
    for (int i=0; i<n; i++){
        gnode* temp = head[i];
        while(temp!= NULL){
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void graph::nonrec_dft(){
    string s;
    int visited[n];
    cout << endl << "Enter Starting vertex Name: ";
    cin >> s;
    stack a;
    for (int i=0; i<n; i++){
        visited[i] = 0;
    }
    for (int i=0; i<n; i++){
        if(head[i]->name == s){
            visited[i] = 1;
            a.push(head[i]);
            break;
        }
    }
    while(a.empty() == 0){
        gnode* temp = a.pop();
        cout << temp->name;
        while(temp->next != NULL){
            temp = temp->next;
            for (int i=0;i<n;i++){
                if(head[i]->name == temp->name){
                    if(visited[i]==0){
                        a.push(temp);
                        visited[i] =1;
                    }
                }
            }
        }
    }

}




int main(){

    graph a;
    a.create();
    a.disp();
    cout << endl << "DFT Non-Recurssive";
    a.nonrec_dft();
    
    return 0;
}