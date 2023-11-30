#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;

class node{
    string word;
    string mean;
    node *left;
    node *right;
    public:
    friend class avl;
};


class avl{
    private:
    node *root;

    public:
    node *balance(node *);
    int height(node *);
    int diff(node *);
    node * rr(node *);
    node * ll(node *);
    node * lr(node *);
    node * rl(node *);

    //void display(node *,int);
    void inorder();
    void inorder(node *);
    void preorder();
    void preorder(node *);
    void postorder();
    void postorder(node*);
    void insert();
    node *insert(node *,node *);

    avl(){
        root=NULL;
    }

};

node * avl::ll(node *a){
    node *b;
    node *c;
    b = a->left;
    c = b->left;

    a->left = b->right;
    b->right = a;
    return b;
}

node * avl::rr(node *a){
    node *b;
    node *c;
    
    b = a->right;
    c = b->right;

    a->right = b->left;
    b->left = a;
    return b;
}

node * avl::lr(node *a){
    node *b;
    node *c;
    b = a->left;
    c = b->right;

    b->right = c->left;
    a->left = c->right;
    c->left = b;
    c->right = a;
    return c;
}

node * avl::rl(node *a){
    node *b;
    node *c;

    b = a->right;
    c = b->left;

    a->right = c->left;
    b->left = c->right;
    c->left = a;
    c->right = b;
    return c;
}

int avl::diff(node *temp){
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

int avl::height(node *temp){
    int h=0;
    if(temp!=NULL){
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height,r_height);
        h = max_height+1;
    }
    return h;
}

node *avl::balance(node *temp){
    int bal_factor = diff(temp);
    if(bal_factor>1){
        if(diff(temp->left)>0) temp = ll(temp);
        else temp = lr(temp);
    }
    else if(bal_factor<-1){
        if(diff(temp->right)>0) temp = rl(temp);
        else temp = rr(temp);
    }

    return temp;
}

void avl::insert(){
    char ch;
    do{
        node *temp;
        temp = new node;
        cout<<"\nenter word and meaning: ";
        cin>>temp->word;
        cin>>temp->mean;
        temp->left = NULL;
        temp->right = NULL;

        root = insert(root,temp);
        cout<<"\ndo you want to add another node? y:yes choice: ";
        cin>>ch;
    }while(ch=='y');
}


node *avl::insert(node *root,node*temp){
    if(root == NULL){
        root = new node;
        root->word = temp->word;
        root->mean = temp->mean;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(temp->word < root->word){
        root->left = insert(root->left,temp);
        root = balance(root);
    }
    else if(temp->word >root->word){
        root->right = insert(root->right,temp);
        root = balance(root);
    }
    return root;
}

void avl::inorder(){
    cout<<"\nin order traversal: ";
	inorder(root);
}


void avl::inorder(node *temp){
	if (temp!=NULL){
		inorder(temp->left);
		cout<<temp->word<<" : "<<temp->mean<<"\t";
		inorder(temp->right);
	}
}

void avl::preorder(){
    cout<<"\npre order traversal: ";
	preorder(root);
}


void avl::preorder(node *temp){
	if (temp!=NULL){
        cout<<temp->word<<" : "<<temp->mean<<"\t";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void avl::postorder(){
    cout<<"\npost order traversal: ";
	postorder(root);
}


void avl::postorder(node *temp){
	if (temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
        cout<<temp->word<<" : "<<temp->mean<<"\t";
	}
}

int main(){
    cout<<"hello world\n";
    avl tree;
    int ch;
    do{
        cout<<"\nchoose operation: \n1:insert \n2:inorder \n3:preorder \n4:postorder \nchoice: ";
        cin>>ch;

        switch(ch){
            case 1:
                tree.insert();
                break;
            case 2:
                tree.inorder();
                break;
            case 3:
                tree.preorder();
                break;
            case 4:
                tree.postorder();
                break;
        }
    }while(ch<5);
    return 0;
}
