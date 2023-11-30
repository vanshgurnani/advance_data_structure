#include <iostream>
using namespace std;
class treenode{
public:
char data[10];
treenode *left;
treenode *right;
friend class tree;
};
class tree{
    treenode *root;
    public:
    void create_nr();
    void preorder_nr();
    void inorder_nr();
    void postorder_nr();
    void bfs();
};
class stack{
    int top;
    treenode *data[30];
    public:
    stack(){
        top=-1;
    }
    void push(treenode *temp);
    treenode *pop();
    bool empty();
    friend class tree;
};

bool stack::empty(){
    if(top==-1){
        return true;
    
    }
    else{
        return false;
    }
}
void stack:: push(treenode *temp){
    top++;
    data[top]=temp;
}
treenode *stack ::pop(){
    treenode *temp;
    temp =data[top];
    top--;
    return temp;
}

class queue{
    int front, rear;
    treenode *data[30];
    public:
    queue(){
        front=rear=-1;
    }
    void enqueue(treenode *temp);
    treenode *dequeue();
    bool empty();
    friend class tree;
};

bool queue::empty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
}
void queue::enqueue(treenode *temp){
    if(front==-1){
        front=0;
    }
    rear++;
    data[rear]=temp;
}
treenode *queue::dequeue(){
    treenode *temp;
    if(front==-1){
        cout<<"Queue Underflow"<<endl;
        return NULL;
    }
    temp=data[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return temp;
}


void tree:: create_nr()
{
 if (root==NULL)
 {
root= new treenode;
cout<<"enter root node:"<<endl;
cin>>root->data;
root->left=NULL;
root->right=NULL;
treenode *temp,*curr;
char op;
  do{
 temp=root;
int flag=0;
curr= new treenode;
cout<<"enter curr node:"<<endl;
cin>>curr->data;
curr->left=NULL;
curr->right=NULL;
    while(flag==0)
    {
    char ch;
    cout<<"you want to add L//R of "<<temp->data<<endl;
    cin>>ch;
    if (ch=='l')
    {
    if(temp->left ==NULL)
    {
    temp->left=curr;
    flag=1;
    }
    temp=temp->left;
    }
    else
    {
    if (ch=='r')
    {
    if (temp->right==NULL)
    {
    temp->right=curr;
    flag=1;
    }
    temp=temp->right;
    }
    }
    }
    cout<<"want to continue: y||n -> ";
    cin>>op;
  }while(op=='y');
 }
}


void tree:: inorder_nr(){
    stack s;
    treenode* temp;
    temp = root;
    while(1){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }
        if(s.empty()){
            break;
        }
        temp=s.pop();
        cout<<temp->data<<endl;
        temp = temp->right; 
    }
}

void tree:: preorder_nr(){
    stack s;
    treenode* temp;
    temp=root;
    
    while(1){
        while(temp!=NULL){
            cout<<temp->data<<endl;
            s.push(temp);
            temp = temp->left;
        }
        
        if(s.empty()){
            break;
        }
        temp=s.pop();
        temp = temp->right;
    }
}



void tree :: bfs(){
    queue q;
    treenode *temp;
    temp=root;
    q.enqueue(temp);
    while(!q.empty()){
        temp=q.dequeue();
        cout<<temp->data<<endl;
        if(temp->left!=NULL){
            q.enqueue(temp->left);
        }
        if(temp->right!=NULL){
            q.enqueue(temp->right);
        }
    }
}

void tree :: postorder_nr(){
    stack s;
    treenode *temp;
    temp=root;
    while(1){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        if(s.data[s.top]->right==NULL){
            temp=s.pop();
            cout<<temp->data<<endl;
        }
        while(!s.empty() && s.data[s.top]->right==temp){
            temp=s.pop();
            cout<<temp->data<<endl;
        }
        if(s.empty()){
            break;
        }
        temp=s.data[s.top]->right;
    }
}

int main(){
    tree a;
    a.create_nr();
    
    cout<<"Non-Recursive inorder: ";
    a.inorder_nr();
    
    cout<<"Non-Recursive preorder: ";
    a.preorder_nr();
    
    cout<<"Non-Recursive postorder: ";
    a.postorder_nr();
    
    cout<<"BFS: ";
    a.bfs();
    
}

