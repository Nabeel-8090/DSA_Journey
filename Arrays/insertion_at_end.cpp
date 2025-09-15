#include <iostream>
using namespace std;

int main() {

    int array[100] = {34, 65, 88, 12, 54}, num;
    int size = 5;

    cout << "Enter a number that you want to add at the end: ";
    cin >> num;

    array[size] = num;
    size++;

    for(int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}