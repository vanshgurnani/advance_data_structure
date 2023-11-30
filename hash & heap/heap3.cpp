#include <iostream>
using namespace std;

class heap{
    public:
        void adjust(int a[], int n, int i) {
    int j = 2 * i + 1;
    int item = a[i];
    while (j <= n) {
        if (j < n && a[j] < a[j+1]) {
            j = j+1;
        }
        if (item >= a[j]) {
            break;
        }
        a[(j-1)/2] = a[j];
        j = 2 * j + 1;
    }
    a[(j-1)/2] = item;
}

void sort(int a[], int n) {
    int t;
    for (int i = (n/2)-1; i >= 0; i--) {
        adjust(a, n-1, i);
    }
    while (n > 0) {
        t = a[0];
        a[0] = a[n-1];
        a[n-1] = t;
        n--;
        adjust(a, n-1, 0);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void get(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin>> a[i];
    }
    cout << endl;
}
int max(int a[],int n){
    return a[n-1];
}

int min(int a[],int n){
    return a[0];
}

};

int main(){
    heap h;
    int a[20] ;
    int n ;
    cout<<"Enter the no. of student: "<<endl;
    cin>>n;
    h.get(a,n);
    cout << "Original array: ";
    h.printArray(a, n);
    h.sort(a, n);
    cout << "Sorted array: ";
    h.printArray(a, n);

    cout<<h.max(a,n)<<endl;
    cout<<h.min(a,n)<<endl;
}