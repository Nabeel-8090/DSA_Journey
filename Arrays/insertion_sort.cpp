#include <iostream>
using namespace std;

int main() {

    int n = 5;
    int array[n] = {125, 34, 120, 7, 3};

    for(int i=0; i<n; i++) {
        int key = array[i];
        int j = i - 1;
        while(j>=0 && array[i]>key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}