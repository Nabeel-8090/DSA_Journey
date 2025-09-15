#include <iostream>
using namespace std;

int main() {

    int array[100] = {34, 54, 97, 32, 63, 534}, num;
    int size = 6;

    cout << "Enter a number that you want to insert at start: ";
    cin >> num;

    for(int i=size; i>0; i--) {
        array[i] = array[i-1];
    }

    array[0] = num;
    size++;

    for(int i=0; i<size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}