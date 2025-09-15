#include <iostream>
using namespace std;

int main() {

    int n = 6;
    int array[n] = {423, 64, 6, 33, 5, 53}, value, pos;

    cout << "Original Array: ";
    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\nEnter a value that you want to delete from array: ";
    cin >> value;

    for(int i=0; i<n; i++) {
        if(array[i] == value) {
            pos = i+1;
        }
    }

    for(int i=pos-1; i<n; i++) {
        array[i] = array[i+1];
    }
    n--;

    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}