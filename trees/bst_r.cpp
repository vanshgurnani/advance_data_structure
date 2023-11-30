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
    void search_nr(treenode *par,treenode *temp);
    void bfs();
    void mirror_r1(treenode *root);
    void mirror_r();
    int depth_r1(treenode *root);
    void depth_r();
    treenode* copy_r1(treenode *root); 
    int copy_r();
    void del();
    
};


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

void tree::mirror_r1(treenode *root){
    if (root == NULL) {
        return;
    }
    
    treenode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror_r1(root->left);
    mirror_r1(root->right);
}

void tree::mirror_r() {
    mirror_r1(root);
    bfs();
}


void tree :: create(){
    root= new treenode;
    treenode *temp,*curr;
    cout<<"enter root node:"<<endl;
    cin>>root->data;
    char op;
    do{
        temp=root;
        int flag=0;
        curr=new treenode;
        cout<<"enter curr node:"<<endl;
        cin>>curr->data;
        
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


void tree::search_nr(treenode *par,treenode *temp){
    int flag=0;
    // root=new treenode;
    temp=root;
    string st;
    cout<<"Enter the data to be deleted"<<endl;
    cin>>st;
    while(flag==0 && temp!=NULL){
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

int tree :: depth_r1(treenode *root){
    int t1=0,t2=0;
    if(root==NULL){
        return 0;
    }
    else{
        t1=depth_r1(root->left);
        t2=depth_r1(root->right);
        if(t1>t2){
            return ++t1;
        }
        else{
            return ++t2;
        }
    }
}

void tree :: depth_r(){
    int d=depth_r1(root);
    cout<<"The depth of Tree is: "<<d<<endl;
}

treenode* tree :: copy_r1(treenode *root){
    treenode *temp=NULL;
    if(root!=NULL){
        temp=new treenode;
        temp->data=root->data;
        temp->left=copy_r1(root->left);
        temp->right=copy_r1(root->right);
    }
    
    return temp;
}

int tree :: copy_r() {
    treenode* copy_root = copy_r1(root);
    if(copy_root == NULL) {
        cout<<"The tree is empty"<<endl;
        return 0;
    }
    else {
        cout<<"Original tree: ";
        bfs();
        cout<<"Copy of tree: ";
        tree b;
        b.root = copy_root;
        b.bfs();
        return 1;
    }
}


void tree :: del(){
    treenode *par,*temp;
    par=NULL;
    temp=root;
    search_nr(par,temp);
    treenode *s;
    int c=0;
    cout<<"par->data : "<<par->data<<endl;
    cout<<"temp->data : "<<temp->data<<endl;
    /*if(temp!=root){
        if(temp->left==NULL && temp->right==NULL){
            c=1;
        }
        else{
            if(temp->left==NULL && temp->right!=NULL || temp->left!=NULL && temp->right==NULL){
                c=2;
            }
            else{
                if(temp->left!=NULL && temp->right!=NULL){
                    c=3;
                }
            }
        }
    }
    else{
        c=4;
    }
    
    switch(c){
        case 1:
            if(par->left==temp){
                par->left=NULL;
            }
            else{
                par->right=NULL;
            }
            
            delete temp;
            
        case 2:
            if(temp->right!=NULL){
                if(par->left==temp){
                    par->left=temp->right;
                }
                else{
                    par->right=temp->right;
                }
            }
            else{
                if(temp->left!=NULL){
                    if(par->left==temp){
                        par->left=temp->left;
                    }
                    else{
                        par->right=temp->left;
                    }
                }
                    
            }
            
            delete temp;
        
        case 3:
            s=temp->right;
            temp=temp->left;
            while(s->left!=NULL){
                s=s->left;
            }
            s->left=temp->left;
            if(par->left==temp){
                par->left=temp->right;
            }
            else{
                par->right=temp->right;
            }
            
            delete temp;
            
        case 4:
            if(temp->right==NULL){
                par=par->left;
            }
            else{
                if(temp->left==NULL){
                    par=par->right;
                }
                else{
                    if(temp->right!=NULL && temp->left!=NULL){
                        temp=temp->left;
                        temp=temp->right;
                        s=temp->right;
                        while(s->left!=NULL){
                            s=s->left;
                        }
                        s->left=temp->left;
                    }
                }
                
            }
            
            delete temp;
     
     
     
            
    }*/
    
 cout<<"Deleted Successfully"<<endl;   
}


// void tree :: del(){
    
// }

int main(){
    cout<<"Hello world!"<<endl;
    tree a;
    a.create();
    a.bfs();
    a.del();
    // a.copy_r();
    // a.search_nr();
    // a.mirror_r();
    // a.depth_r();
    
}





















// #include <iostream>
// using namespace std;
// class treenode{
//     public:
//         string data;
//         treenode *left;
//         treenode *right;
//         friend class tree;
// };
// class tree{
//     treenode *root;
//     public:
//     void create();
//     void search_nr(treenode *par,treenode *temp);
//     void bfs();
//     void mirror_r1(treenode *root);
//     void mirror_r();
//     int depth_r1(treenode *root);
//     void depth_r();
//     treenode* copy_r1(treenode *root); 
//     int copy_r();
//     void del();
    
// };


// class queue{
//     int front, rear;
//     treenode *data[30];
//     public:
//     queue(){
//         front=rear=-1;
//     }
//     void enqueue(treenode *temp);
//     treenode *dequeue();
//     bool empty();
//     friend class tree;
// };

// bool queue::empty(){
//     if(front==-1 && rear==-1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// void queue::enqueue(treenode *temp){
//     if(front==-1){
//         front=0;
//     }
//     rear++;
//     data[rear]=temp;
// }
// treenode *queue::dequeue(){
//     treenode *temp;
//     if(front==-1){
//         cout<<"Queue Underflow"<<endl;
//         return NULL;
//     }
//     temp=data[front];
//     if(front==rear){
//         front=rear=-1;
//     }
//     else{
//         front++;
//     }
//     return temp;
// }



// void tree :: create(){
//     root= new treenode;
//     treenode *temp,*curr;
//     cout<<"enter root node:"<<endl;
//     cin>>root->data;
//     char op;
//     do{
//         temp=root;
//         int flag=0;
//         curr=new treenode;
//         cout<<"enter curr node:"<<endl;
//         cin>>curr->data;
        
//         while (flag==0  and temp!=NULL){
//             if(curr->data<temp->data){
//                 if(temp->left==NULL){
//                     temp->left=curr;
//                     flag=1;
//                 }
//                 else{
//                     temp=temp->left;
//                 }
//             }
//             else{
//                 if(temp->right==NULL){
//                     temp->right=curr;
//                     flag=1;
//                 }
//                 else{
//                     temp=temp->right;
//                 }
//             }
//         }
        
        
//         cout<<"want to continue: y||n -> ";
//         cin>>op;
//     }while(op=='y');
//     cout<<"The End"<<endl;
// }


// void tree::search_nr(treenode *par,treenode *temp){
//     int flag=0;
//     // root=new treenode;
//     temp=root;
//     string st;
//     cout<<"Enter the data to be deleted"<<endl;
//     cin>>st;
//     while(flag==0 && temp!=NULL){
//         if(st==temp->data){
//             flag=1;
//             break;
//         }
//         else if(st<temp->data){
//             temp=temp->left;
//         }
//         else{
//             temp=temp->right;
//         }
//     }
    
    
//     if(flag==1){
//         cout<<"Data Found"<<endl;
//     }
//     else{
//         cout<<"Data not Found"<<endl;
//     }
// }

// void tree :: bfs(){
//     queue q;
//     treenode *temp;
//     temp=root;
//     q.enqueue(temp);
//     while(!q.empty()){
//         temp=q.dequeue();
//         cout<<temp->data<<endl;
//         if(temp->left!=NULL){
//             q.enqueue(temp->left);
//         }
//         if(temp->right!=NULL){
//             q.enqueue(temp->right);
//         }
//     }
// }




// void tree :: del(){
//     treenode *par,*temp;
//     par=NULL;
//     temp=root;
//     search_nr(par,temp);
//     treenode *s;
//     int c=0;
//     cout<<"par->data : "<<par->data<<endl;
//     cout<<"temp->data : "<<temp->data<<endl;
//     if(temp!=root){
//         if(temp->left==NULL && temp->right==NULL){
//             c=1;
//         }
//         else{
//             if(temp->left==NULL && temp->right!=NULL || temp->left!=NULL && temp->right==NULL){
//                 c=2;
//             }
//             else{
//                 if(temp->left!=NULL && temp->right!=NULL){
//                     c=3;
//                 }
//             }
//         }
//     }
//     else{
//         c=4;
//     }
    
//     switch(c){
//         case 1:
//             if(par->left==temp){
//                 par->left=NULL;
//             }
//             else{
//                 par->right=NULL;
//             }
            
//             delete temp;
//             break;
            
//         case 2:
//             if(temp->right!=NULL){
//                 if(par->left==temp){
//                     par->left=temp->right;
//                 }
//                 else{
//                     par->right=temp->right;
//                 }
//             }
//             else{
//                 if(temp->left!=NULL){
//                     if(par->left==temp){
//                         par->left=temp->left;
//                     }
//                     else{
//                         par->right=temp->left;
//                     }
//                 }
                    
//             }
            
//             delete temp;
//             break;
        
//         case 3:
//             s=temp->right;
//             while(s->left!=NULL){
//                 s=s->left;
//             }
//             s->left=temp->left;
//             if(par->left==temp){
//                 par->left=temp->right;
//             }
//             else{
//                 par->right=temp->right;
//             }
            
//             delete temp;
//             break;
            
//         case 4:
//             if(temp->right==NULL){
//                 root=root->left;
//             }
//             else{
//                 if(temp->left==NULL){
//                     root=root->right;
//                 }
//                 else{
//                     if(temp->right!=NULL && temp->left!=NULL){
//                         root=temp->right;
//                         s=temp->right;
//                         while(s->left!=NULL){
//                             s=s->left;
//                         }
//                         s->left=temp->left;
//                     }
//                 }
                
//             }
            
//             delete temp;
//             break;
     
     
     
            
//     }
    
//  cout<<"Deleted Successfully"<<endl;   
// }



// int main(){
//     cout<<"Hello world!"<<endl;
//     tree a;
//     a.create();
//     a.bfs();
//     a.del();
//     // a.copy_r();
//     // a.search_nr();
//     // a.mirror_r();
//     // a.depth_r();
    
// }