#include <iostream>
using namespace std;

void second_largest(int arr[], int n) {
    int first = INT_MIN; 
    int second = INT_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    cout << "Second Largest of array: " << second <<  endl;
}

int main() {

    int arr[] = {34, 66, 90, 55, 55, 80};
    int n = 4;

    second_largest(arr, n);

    return 0;
}