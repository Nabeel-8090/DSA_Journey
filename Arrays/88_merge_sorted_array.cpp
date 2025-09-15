#include <iostream>
using namespace std;

int main() {

    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m = 3;
    int n = 3;

    int merge[m+n];
    for(int i=0; i<m; i++) {
        if(nums1[i]!=0) {
            nums1[i] = nums1[i];
        }   
    }
    for(int i=0; i<n; i++) {
        nums1[i+m] = nums2[i];
    }
    for(int i=0; i<m+n; i++) {
        for(int j=i+1; j<m+n; j++) {
            if(nums1[i]>nums1[j]) {
                int temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
        cout << nums1[i] << " ";
    }

    return 0;
}