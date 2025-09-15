#include <iostream>
using namespace std;

int main() {

    int array[100] = {3, 64, 65, 23, 76, 33}, pos, num;
    int size = 6;

    cout << "Enter position that you wanna insert an element: ";
    cin >> pos;

    cout << "Enter a number that you want to insert in middle: ";
    cin >> num;

    for(int i=size; i>pos-1; i--) {
        array[i] = array[i-1];
    }

    array[pos-1] = num;
    size++;

    for(int i=0; i<size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}