#include <iostream>
using namespace std;

int main() {

    int size = 5;
    int array[size] = {54, 65, 4, 24, 66, 66};

    int largest = INT_MIN;
    for(int i=0; i<size; i++) {
        if(array[i]>largest) {
            largest = array[i];
        }
    }    

    cout << "Largest: " << largest << endl;

    return 0;
}