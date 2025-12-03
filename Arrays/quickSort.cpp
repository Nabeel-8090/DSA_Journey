#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {

    int arr[] = {7, 2, 1, -9, 6, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size-1);

    cout << "Sorted Array: ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}