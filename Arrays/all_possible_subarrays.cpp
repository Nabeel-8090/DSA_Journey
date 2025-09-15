#include <iostream>
using namespace std;

int main() {

    int n = 5;
    int array[n] = {2, 5, 3, 5, 3};

    for(int st=0; st<n; st++) {
        for(int end=st; end<n; end++) {
            for(int i=st; i<=end; i++) {
                cout << array[i];
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}