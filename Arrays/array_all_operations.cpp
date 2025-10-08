#include <iostream>
using namespace std;

const int capacity = 100;
int arr[capacity] = {2, 1, 4, 3, 5};
int n = 5;

void push_front(int value) {
    for(int i=n; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    n++;
}

void push_back(int value) {
    arr[n] = value;
    n++;
}

void insert(int value, int pos) {
    if(pos < 1 || pos > n) {
        cout << "Invalid Position!" << endl;
        return;
    }
    for(int i=n; i>pos-1; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = value;
    n++;
}

void pop_front() {
    for(int i=0; i<n; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void pop_back() {
    arr[n-1] = 0;
    n--;
}

void deletion(int pos) {
    for(int i=pos-1; i<n; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void bubble_sort() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertion_sort() {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] =  key;
    }
}

void linear_search(int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            cout << "Found at position: " << i+1 << endl;
            return;
        }
    }
    cout << "Not Found!" << endl;
}

void binary_search(int target) {
    int start = 0; 
    int end = n-1;
    while(start <= end) {
        int mid = (start+end)/2;
        if(arr[mid] == target) {
            cout << "Found at position: " << mid+1 << endl;
            return;
        }
        if(arr[mid] > target) {
            end = mid-1;
        }
        if(arr[mid] < target) {
            start = mid+1;
        }
    }
    cout << "Not Found!" << endl;
}

void print() {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {

    push_front(11);
    print();

    push_back(1000);
    print();

    insert(26, 4);
    print();

    pop_front();
    print();

    pop_back();
    print();

    deletion(3);
    print();

    linear_search(5);
    binary_search(1);
    insertion_sort();
    print();
    binary_search(1);


    

    return 0;
}