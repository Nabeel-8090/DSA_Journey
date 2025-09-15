#include <iostream>
using namespace std;

int main() {

    int size = 5;
    int array[size] = {65, 34, 53, 76, 55};

    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(array[i]<array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << "Second Largest Element: " << array[1] << endl;

    return 0;
}