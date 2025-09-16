#include <iostream>
using namespace std;

int main() {

    int n = 7;
    int array[n] = {23, 43, 65, 76, 86, 88, 96};
    int target = 96;
    int index = -1;

    int left = 0;
    int right = n-1;


    while(left<=right) {
        int mid = (left+right)/2;
        if(array[mid] == target) {
            index = mid;
            break;
        }
        if(array[mid] < target) {
            left = mid+1;
        }
        if(array[mid] > target) {
            right = mid-1;
        }
    }

    if(index >= 0) {
        cout << "Value is found at position: " << index+1 << endl;
    } else {
        cout << "Value is not found!" << endl;
    }
 
    return 0;
}