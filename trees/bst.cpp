#include <iostream>
using namespace std;
class treenode{
    public:
        string data;
        treenode *left;
        treenode *right;
        friend class tree;
};
class tree{
    treenode *root;
    public:
    void create();
    void search_nr();
    void remove();
    treenode* deleteNode(treenode *root, string key);
    void inorder(treenode *);
    void inorder();
};

void tree :: create(){
    root= new treenode;
    treenode *temp,*curr;
    cout<<"enter root node:"<<endl;
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
    char op;
    do{
        temp=root;
        int flag=0;
        curr=new treenode;
        cout<<"enter curr node:"<<endl;
        cin>>curr->data;
        curr->left=NULL;
        curr->right=NULL;
        
        while (flag==0  and temp!=NULL){
            if(curr->data<temp->data){
                if(temp->left==NULL){
                    temp->left=curr;
                    flag=1;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->right==NULL){
                    temp->right=curr;
                    flag=1;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        
        
        cout<<"want to continue: y||n -> ";
        cin>>op;
    }while(op=='y');
    cout<<"The End"<<endl;
}


void tree::search_nr(){
    treenode *temp;
    int flag=0;
    // root=new treenode;
    temp=root;
    string st;
    cout<<"Enter the data to be found"<<endl;
    cin>>st;
    while(flag==0){
        if(st==temp->data){
            flag=1;
            break;
        }
        else if(st<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    
    
    if(flag==1){
        cout<<"Data Found"<<endl;
    }
    else{
        cout<<"Data not Found"<<endl;
    }
}


treenode*tree :: deleteNode(treenode *root, string key){
    if (root == NULL){
        return NULL;
    }
    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if (root->left == NULL){
            treenode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            treenode *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            treenode *temp = root->right;
            while (temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void tree::remove(){
    string key;
    cout << "Enter the value to remove: " << endl;
    cin >> key;
    root = deleteNode(root, key);
}

void tree :: inorder(treenode *temp){
    if (temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<endl;
        inorder(temp->right);
    }
    
}

void tree :: inorder(){
    inorder(root);
}

int main(){
    cout<<"Hello world!"<<endl;
    tree a;
    a.create();
    a.search_nr();
    a.remove();
    a.inorder();
}