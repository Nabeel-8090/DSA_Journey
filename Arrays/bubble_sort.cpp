#include <iostream>
using namespace std;

int main() {

    int array[7] = {32, 12, 4, 50, 45, 76, 1}, temp;

    for(int i=0; i<7; i++) {
        for(int j=i+1; j<7; j++) {
            if(array[i]>array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i=0; i<7; i++) {
        cout << array[i] << " ";
    }

    return 0;
}