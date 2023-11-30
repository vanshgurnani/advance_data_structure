#include <iostream>
using namespace std;

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

int main() {
    int a[20] = {6, 1, 7, 3, 2, 8, 9, 4, 5, 0};
    int n = 10;
    cout << "Original array: ";
    printArray(a, n);
    sort(a, n);
    cout << "Sorted array: ";
    printArray(a, n);

    cout << "Maximum value: " << a[n-1] << endl;
    cout << "Minimum value: " << a[0] << endl;

    
    return 0;
}