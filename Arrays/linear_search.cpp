#include <iostream>
using namespace std;

int main() {

    int n = 7;
    int array[n] = {35, 64, 32, 776, 53, 100, 2};
    int target = 64;
    int index = -1;

    for(int i=0; i<n; i++) {
        if(array[i] == target) {
            index = i+1;
        }
    }

    if(index>=0) {
        cout << "Value is found at postion: " << index << endl;
    } else {
        cout << "Sorry! Value is not found." << endl;
    }

    return 0;
}