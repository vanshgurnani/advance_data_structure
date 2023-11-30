#include <iostream>
using namespace std;
class treenode{
char data[10];
treenode *left;
treenode *right;
friend class tree;
};
class tree{
    treenode *root;
    public:
    void create_nr();
    void preorder_r();
    void preorder_r(treenode *temp);
    void inorder_r();
    void inorder_r(treenode *temp);
    void postorder_r();
    void postorder_r(treenode *temp);
};

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

void tree :: preorder_r(treenode *temp){
    if(temp!=NULL){
        cout<<temp->data<<endl;
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void tree :: preorder_r(){
    preorder_r(root);
}

void tree :: inorder_r(treenode *temp){
    if(temp!=NULL){
        inorder_r(temp->left);
        cout<<temp->data<<endl;
        inorder_r(temp->right);
    }
}

void tree :: inorder_r(){
    inorder_r(root);
}

void tree :: postorder_r(treenode *temp){
    if(temp!=NULL){
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout<<temp->data<<endl;
    }
}

void tree :: postorder_r(){
    postorder_r(root);
}


int main(){
    tree a;
    a.create_nr();
    
    cout<<"preorder: ";
    a.preorder_r();
    cout<<endl;
    
    cout<<"inorder: ";
    a.inorder_r();
    cout<<endl;
    
    cout<<"postorder: ";
    a.postorder_r();
    cout<<endl;
    
}

