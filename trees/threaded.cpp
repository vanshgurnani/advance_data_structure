#include <iostream>
using namespace std;

class tbtnode{
    public:
    char data[10];
    bool lbit,rbit;
    tbtnode *rightc,*leftc;
    friend class tbt;
    tbtnode();
};
tbtnode :: tbtnode(){
            lbit=1;
            rbit=1;
}
class tbt{
    tbtnode *head;
    public:
        void create();
        void preorder();
        void inorder();
        tbtnode* in(tbtnode *temp);
        tbt() {
            head = new tbtnode;
            head->lbit = 0;
            head->rbit = 0;
            head->leftc = head;
            head->rightc = head;
        }


};

void tbt::create() {
    tbtnode *root, *head, *temp, *curr;
    root = new tbtnode;
    cout << "Enter the root: " << endl;
    cin >> root->data;
    head = this->head;
    head->lbit = 0;
    root->leftc = head;
    root->rightc = head;
    head->leftc = root;

    char op;

    do {
        int flag = 0;
        temp = root;
        curr = new tbtnode;
        cout << "enter curr node:" << endl;
        cin >> curr->data;
        while (flag == 0) {
            char ch;
            cout << "you want to add L//R of " << temp->data << endl;
            cin >> ch;
            if (ch == 'l') {
                if (temp->lbit == 1) {
                    
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else {
                    temp = temp->leftc;
                }
            }
            if (ch == 'r') {
                if (temp->rbit == 1) {
                    
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else {
                    temp = temp->rightc;
                }
            }
        }

        cout << "Enter your choice y||n : " << endl;
        cin >> op;
    } while (op == 'y');

    cout << "The End" << endl;
}

tbtnode* tbt :: in(tbtnode *temp){
    tbtnode* s;
    s=temp->rightc;
    if(temp->rbit==0){
        while(s->rbit==0){
            s=s->leftc;
        }
    }
    return s;
}

void tbt :: inorder(){
    tbtnode *temp;
    temp=head;
    while(1){
        temp=in(temp);
        if(temp==head){
            break;
        }
        cout<<temp->data<<endl;
    }
}

void tbt :: preorder(){
    tbtnode *temp;
    temp=head->leftc;
    while(temp!=head){
        cout<<temp->data<<endl;
        while(temp->lbit!=1){
            temp=temp->leftc;
            cout<<temp->data<<endl;
        }
        while(temp->rbit==1){
            temp=temp->rightc;
        }
        temp=temp->rightc;

    }
}

int main() {
    // Write C++ code here
    cout << "Hello world!"<<endl;
    tbt a;
    a.create();
    cout<<"The Inorder is: "<<endl;
    a.inorder();
    cout<<"The Preorder is: "<<endl;
    a.preorder();

    return 0;
}
